#include<stdio.h>
#include<stdlib.h>

struct Masina {
	int id;
	int anFabricatie;
	char* sofer;//un sir de carctere -> 8 octeti pe arhitectura x64
	float kilometriiParcursi;
	char initialaProducator;//doar un caracter -> 1 octet = 8biti(0 si 1) = valMaxima=255 ->
};

struct Masina initializare(int id, int anFabricatie, const char* sofer, float kilometriiParcursi,
	char initialaProducator) {
	struct Masina m;
	m.id = id;
	m.anFabricatie = anFabricatie;
	m.sofer = (char*)malloc(strlen(sofer) + 1);//cast explicit pt ca malloc returneaza void*
	//(nr de caractere + terminator de sir) * sizeof(char)
	strcpy_s(m.sofer, strlen(sofer) + 1, sofer); //strcpy_s masoara cat sa copieze fata de strcpy
	m.kilometriiParcursi = kilometriiParcursi;
	m.initialaProducator = initialaProducator;
	return m;
}

void afisare(struct Masina m) {
	printf("ID: %d \n", m.id);
	printf("An fabricatie: %d \n", m.anFabricatie); //functie cu numar variabil de parametrii pe care ii aratam prin %, nr minim de 1 param
	printf("Soferi: %s \n", m.sofer);
	printf("Kilometrii Parcursi: %f \n", m.kilometriiParcursi);
	printf("Initiala producator: %c \n", m.initialaProducator);
}

//explicare dc *
void modifica_Sofer(struct Masina* m, const char* nouSofer) {
	if (strlen(nouSofer) > 2) {
		//mai intai dezalocam memoria daca exista
		if (m->sofer != NULL)
		{
			free(m->sofer);
		}
		m->sofer = (char*)malloc(strlen(nouSofer) + 1);
		strcpy_s(m->sofer, strlen(nouSofer) + 1, nouSofer);
	}
}

void dezalocare(struct Masina* m) {
	if (m->sofer != NULL)
	{
		free(m->sofer);
		m->sofer = NULL;
	}
}

int main() {
	struct Masina masina;
   	masina =  initializare(1,2004,"Robert", 2000, 'P');//"P" -> considera un sir (ocupa 2 octeti)
	//de facut debug
	afisare(masina);
	modifica_Sofer(&masina, "Alex");
	afisare(masina);
	dezalocare(&masina);
	afisare(masina);
	return 0;
}

//nu sunt referinte in C -> trimitem prin pointer