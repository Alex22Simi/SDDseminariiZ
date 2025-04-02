﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//metode de evitare a coliziunilor
//liniar probing verifica liniar
//quarter probing sare cate casute ii dam
//chaining->memoram niste pointeri in casute, memoram adresa anumitor obiecte
//atunci cand avem coliziune sa se mai faca un pointer si in acea casuta o sa avem o lista defapt
//adica aceasta presupune un vector de liste mai exact

//trebuie sa folositi fisierul masini.txt
//sau va creati un alt fisier cu alte date

struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

//creare structura pentru un nod dintr-o lista simplu inlantuita
typedef struct Nod Nod;
struct Nod {
	Masina info;
	Nod* urm;
};

//creare structura pentru tabela de dispersie
// aceasta este un vector de liste
struct HashTable {
	int dim;
	Nod** v; //vector de pointeri la nod
};
typedef struct HashTable HashTable;

Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	Masina m1;
	aux = strtok(buffer, sep);
	m1.id = atoi(aux);
	m1.nrUsi = atoi(strtok(NULL, sep));
	m1.pret = atof(strtok(NULL, sep));
	aux = strtok(NULL, sep);
	m1.model = malloc(strlen(aux) + 1);
	strcpy_s(m1.model, strlen(aux) + 1, aux);

	aux = strtok(NULL, sep);
	m1.numeSofer = malloc(strlen(aux) + 1);
	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);

	m1.serie = *strtok(NULL, sep);
	return m1;
}

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);
}

void afisareListaMasini(/*lista de masini*/ Nod* v) {
	//afiseaza toate elemente de tip masina din lista simplu inlantuita
	//prin apelarea functiei afisareMasina()
	while (v != NULL) {
		afisareMasina(v->info);
		v = v->urm;
	}
}

/*void adaugaMasinaInLista(/*lista de masiniNod* v, Masina masinaNoua) {
	//adauga la final in lista primita o noua masina pe care o primim ca parametru

	//daca lista e nula nu mai apelam functia asta
	if (v == NULL) {
		return;
	}
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = masinaNoua; //shallow coppy
	nou->urm = NULL;
	while (v != NULL) {
		v = v->urm;
	}
	v->urm = nou;
}*/

void adaugaMasinaInLista(Nod** v, Masina masinaNoua) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = masinaNoua;
	nou->urm = NULL;

	if (*v == NULL) {
		*v = nou; // lista era goală
	}
	else {
		Nod* temp = *v;
		while (temp->urm != NULL) {
			temp = temp->urm;
		}
		temp->urm = nou;
	}
}

HashTable initializareHashTable(int dimensiune) {
	HashTable ht;
	//initializeaza vectorul de liste si seteaza fiecare lista ca fiind NULL;
	ht.dim = dimensiune;
	ht.v = (Nod**)malloc(sizeof(Nod*) * dimensiune);
	for (int i = 0; i < dimensiune; i++) {
		ht.v[i] = NULL;
	}
	return ht;
}

//calculam dupa numele soferului
int calculeazaHash(/*atribut al masini pentru clusterizare*/const char* nume, int dimensiune) {
	// este calculat hash-ul in functie de dimensiunea tabelei si un atribut al masinii
	if (dimensiune == 0) {
		return 0;
	}
	int s = 0;
	for (int i = 0; i < strlen(nume); i++) {
		s += nume[i];
	}
	return s % dimensiune;
}

void inserareMasinaInTabela(HashTable hash, Masina masina) {
	//este folosit mecanismul CHAINING
	//este determinata pozitia si se realizeaza inserarea pe pozitia respectiva
	int poz = calculeazaHash(masina.numeSofer, hash.dim);
	if (hash.v[poz] == NULL) {//nu avem coliziune
		Nod* nou = (Nod*)malloc(sizeof(Nod));
		nou->info = masina;
		nou->urm = NULL;
		hash.v[poz] = nou;
	}
	else { //avem coliziune
		adaugaMasinaInLista(&hash.v[poz], masina);
	}
}

HashTable citireMasiniDinFisier(const char* numeFisier, int dimensiune) {
	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
	//prin apelul repetat al functiei citireMasinaDinFisier()
	// aceste masini sunt inserate intr-o tabela de dispersie initializata aici
	//ATENTIE - la final inchidem fisierul/stream-ul
	FILE* file = fopen(numeFisier, "r");
	HashTable ht = initializareHashTable(dimensiune);

	while (!feof(file)) {
		inserareMasinaInTabela(ht, citireMasinaDinFisier(file));
	}
	fclose(file);
	return ht;
}

void afisareTabelaDeMasini(HashTable ht) {
	//sunt afisate toate masinile cu evidentierea clusterelor realizate
	for (int i = 0; i < ht.dim; i++) {
		printf("\nCluster %d\n", i + 1);
		afisareListaMasini(ht.v[i]);
	}
}

void dezalocareTabelaDeMasini(HashTable* ht) {
	//sunt dezalocate toate masinile din tabela de dispersie
}

float* calculeazaPreturiMediiPerClustere(HashTable ht, int* nrClustere) {
	//calculeaza pretul mediu al masinilor din fiecare cluster.
	//trebuie sa returnam un vector cu valorile medii per cluster.
	//lungimea vectorului este data de numarul de clustere care contin masini
	return NULL;
}

Masina getMasinaDupaCheie(HashTable ht, const char* nume /*valoarea pentru masina cautata*/) {
	Masina m;
	m.id = -1;
	//cauta masina dupa valoarea atributului cheie folosit in calcularea hash-ului
	//trebuie sa modificam numele functiei 
	int hash = calculeazaHash(nume, ht.dim);
	if (ht.v[hash]) {
		Nod* p = ht.v[hash];
		while (p && strcmp(nume, p->info.numeSofer)!= 0 ) {
			p = p->urm;
		}
		if (p) {
			m = p->info;
			m.model = malloc((strlen(p->info.model) + 1));
			strcpy_s(m.model, strlen(p->info.model) + 1, p->info.model);

			m.numeSofer = malloc((strlen(p->info.numeSofer) + 1));
			strcpy_s(m.numeSofer, strlen(p->info.numeSofer) + 1, p->info.numeSofer);
		}
	}
	return m;
}

int main() {
	HashTable ht = citireMasiniDinFisier("masini.txt", 5);
	afisareTabelaDeMasini(ht);

	Masina m = getMasinaDupaCheie(ht, "Gigel");
	printf("Cautam masina lui Gigel: \n");
	if (m.id != -1) {
		afisareMasina(m);
		free(m.model);
		free(m.numeSofer);
	}
	else {
		printf("Nu a fost gasit");
	}
	return 0;
}
