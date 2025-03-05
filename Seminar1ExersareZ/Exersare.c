/*#include<stdio.h>
#include<stdlib.h>

struct Masina {
	int id; //4b
	int anFabricatie; //4b
	char* sofer; ///8b
	float kilometriiParcursi; ///4b
	char initialaProducator; //1b
};

struct Masina initializareMasina(int id, int anFabricatie,
	const char* sofer, float kilometriiParcursi, char initialaProducator) {
	struct Masina m;
	m.id = id;
	m.anFabricatie = anFabricatie;
	m.sofer = (char*)malloc(strlen(sofer) + 1);
	strcpy_s(m.sofer, strlen(sofer) + 1, sofer);
	m.kilometriiParcursi = kilometriiParcursi;
	m.initialaProducator = initialaProducator;
	return m;
	//strcpy_s verifica mai intai daca exista suficient spatiu in buffer-ul
	//destinatie, daca nu are suficient spatiu stcpy_s returneaza 
	//o eroare si nu face copierea, evitand problemele de buffer overflow
}

void afisare(struct Masina m)
{
	printf("ID: %d \n", m.id);
	printf("An fabricatie: %d \n", m.anFabricatie);
	printf("Sofer: %s \n", m.sofer);
	printf("Kilometrii parcursi: %f \n", m.kilometriiParcursi);
	printf("Initiala producator: %c \n", m.initialaProducator);
}

void modificaSofer(struct Masina* m, const char* soferNou) {
	if (strlen(soferNou) > 2)
	{
		if (m->sofer != NULL)
		{
			free(m->sofer);
		}
		m->sofer = (char*)malloc(strlen(soferNou) + 1);
		strcpy_s(m->sofer, strlen(soferNou) + 1, soferNou);
	}
}

void dezalocare(struct Masina* m)
{
	if (m->sofer != NULL)
	{
		free(m->sofer);
		m->sofer = NULL;
	}
}

int main()
{
	struct Masina masina;
	masina = initializareMasina(1, 2004, "Robert", 2000, 'P');
	afisare(masina);
	modificaSofer(&masina, "Ion");
	afisare(masina);


	dezalocare(&masina);
	return 0;
}*/


/*#include<stdio.h>
#include<stdlib.h>

struct Masina {
	int id;
	int anFabricatie;
	char* sofer;
	float km;
	char initiala;
};

struct Masina initializareMasina(int id, int anFabricatie, 
	const char* sofer, float km, char initiala)
{
	struct Masina m;
	m.id = id;
	m.anFabricatie = anFabricatie;
	m.sofer = (char*)malloc(strlen(sofer) + 1);
	strcpy_s(m.sofer, strlen(sofer) + 1, sofer);
	m.km = km;
	m.initiala = initiala;
	return m;
}

void afisareMasina(struct Masina m)
{
	printf("ID: %d \n", m.id);
	printf("An: %d \n", m.anFabricatie);
	printf("Sofer: %s \n", m.sofer);
	printf("km: %f \n", m.km);
	printf("Initiala: %c \n", m.initiala);
}
void modificaSofer(struct Masina* m, const char* soferNou)
{
	if (strlen(soferNou) > 2)
	{
		if (m->sofer != NULL)
		{
			free(m->sofer);
		}
		m->sofer = (char*)malloc(strlen(soferNou) + 1);
		strcpy_s(m->sofer, strlen(soferNou) + 1, soferNou);
	}
}

void dezalocare(struct Masina* m)
{
	if (m->sofer != NULL)
	{
		free(m->sofer);
		m->sofer = NULL;
	}
}


int main()
{
	struct Masina masina;
	masina = initializareMasina(1, 2010, "Emil", 1000, 'A');
	afisareMasina(masina);
	modificaSofer(&masina, "Alex");
	afisareMasina(masina);
	dezalocare(&masina);
	return 0;
}*/

/*#include<stdio.h>
#include<stdlib.h>

struct Masina {
	int id;
	int nrLocuri;
	char* marca;
	float capacitateC;
	char normaPoluare;
};

struct Masina initializareMasina(int id, int nrLocuri,
	const char* marca, float capacitateC, char normaPoluare)
{
	struct Masina m;
	m.id = id;
	m.nrLocuri = nrLocuri;
	m.marca = (char*)malloc(strlen(marca) + 1);
	strcpy_s(m.marca, strlen(marca) + 1, marca);
	m.capacitateC = capacitateC;
	m.normaPoluare = normaPoluare;
	return m;
}

void afisare(struct Masina m)
{
	printf(" Id masina: %d\n Nr. locuri: %d\n Capacitate: %.2f\n Marca: %s\n NormaPoluare: %c",
		m.id, m.nrLocuri, m.capacitateC, m.marca, m.normaPoluare);
}

void modificaNrLocuri(struct Masina* m, int nrLocuriNou)
{
	if (nrLocuriNou > 0)
	{
		m->nrLocuri = nrLocuriNou;
	}
}

void dezalocare(struct Masina* m)
{
	if (m->marca != NULL)
	{
		free(m->marca);
		m->marca = NULL;
	}
}

int main()
{
	struct Masina masina;
	masina = initializareMasina(1, 5, "Dacia", 1.5, '4');
	afisare(masina);
	modificaNrLocuri(&masina, 4);
	afisare(masina);
	dezalocare(&masina);
	return 0;
}*/

#include<stdio.h>
#include<stdlib.h>

struct Masina {
	int id;
	int nrKm;
	char* model;
	float pret;
	char tipMotor;
};

struct Masina initializareMasina(int id, int nrKm, const char* model,
	float pret, char tipMotor)
{
	struct Masina m;
	m.id = id;
	m.nrKm = nrKm;
	m.model = (char*)malloc(strlen(model) + 1);
	strcpy_s(m.model, strlen(model) + 1, model);
	m.pret = pret;
	m.tipMotor = tipMotor;
	return m;
}

void afisareMasina(struct Masina m)
{
	printf(" Id %d\n Km %d\n Model %s\n Pret %.2f\n TipMotor %c\n",
		m.id, m.nrKm, m.model, m.pret, m.tipMotor);
}

void modificaPret(struct Masina* m, float pretNou)
{
	if (pretNou > 0)
	{
		m->pret = pretNou;
	}
}

void modificaModel(struct Masina* m, const char* modelNou)
{
	if (strlen(modelNou) > 1)
	{
		if (m->model != NULL)
		{
			free(m->model);
		}

		m->model = (char*)malloc(strlen(modelNou) + 1);
		strcpy_s(m->model, strlen(modelNou) + 1, modelNou);
	}
}

void dezalocare(struct Masina* m)
{
	if (m->model != NULL)
	{
		free(m->model);
		m->model = NULL;
	}
}

int main()
{
	struct Masina masina;
	masina = initializareMasina(1, 50000, "Logan", 3000.50, 'B');
	afisareMasina(masina);
	modificaPret(&masina, 50000);
	afisareMasina(masina);
	modificaModel(&masina, "BMW");
	afisareMasina(masina);
	dezalocare(&masina);
	return 0;
}






