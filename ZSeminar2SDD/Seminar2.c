/*#include<stdio.h>
#include<malloc.h>

struct Masina {
	int id;
	int nrLocuri;
	char* marca;
	float capacitateC;
	char normaPoluare;
};

struct Masina initializareMasina(int id, int nrLocuri, const char* marca,
	float capacitateC, char normaPoluare) {
	struct Masina m;
	m.id = id;
	m.nrLocuri = nrLocuri;
	if (marca == NULL) {
		m.marca = NULL;
	}
	else {
		m.marca = (char*)malloc(strlen(marca) + 1);
		strcpy_s(m.marca, strlen(marca) + 1, marca);
	}
	m.capacitateC = capacitateC;
	m.normaPoluare = normaPoluare;
	return m;
}

void afisareMasina(struct Masina m) {
	printf("Id: %d \n NrLocuri %d \n Marca %s \n Capacitate %.2f \n NormaPoluare %c\n",
		m.id, m.nrLocuri, m.marca, m.capacitateC, m.normaPoluare);
}

void afisareVectorMasini(struct Masina* vector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++) {
		afisareMasina(vector[i]);
	}
}

struct Masina* copiazaPrimeleElemente(struct Masina* vector, int nrElemente, int nrElementeCopiate) {
	////copiem intr-un vector nou pe care il vom returna primele nrElementeCopiate
	if (nrElementeCopiate > nrElemente) {
		nrElementeCopiate = nrElemente;
	}
	struct Masina* vectorNou = NULL;
	vectorNou = (struct Masina*)malloc(nrElementeCopiate * sizeof(struct Masina));
	for (int i = 0; i < nrElementeCopiate; i++) {
		vectorNou[i] = initializareMasina(vector[i].id, vector[i].nrLocuri, vector[i].marca, vector[i].capacitateC, vector[i].normaPoluare);
	}

	return vectorNou;
}

void copiazaMasiniCuCCMare(struct Masina* vector, char nrElemente, float prag,
	struct Masina** vectorNou, int* dimensiune) {
	*dimensiune = 0;
	for (char i = 0; i < nrElemente; i++) {
		if (prag < vector[i].capacitateC) {
			(*dimensiune)++;
		}
	}
	if (*dimensiune > 0) {
		int j = 0;
		*vectorNou = (struct Masina*)malloc((*dimensiune) * sizeof(struct Masina));
		for (int i = 0; i < nrElemente; i++) {
			if (prag < vector[i].capacitateC) {
				(*vectorNou)[j] = vector[i];
				(*vectorNou)[j].marca = (char*)malloc((strlen(vector[i].marca) + 1)* sizeof(char));
				strcpy_s((*vectorNou)[j].marca, strlen(vector[i].marca) + 1, vector[i].marca);
				j++;
			}
		}
	}
}

struct Masina getPrimaMasinaDupaMarca(struct Masina* vector, int nrElemente, const char* conditie) {
	for (int i = 0; i < nrElemente; i++) {
		if (strcmp(vector[i].marca, conditie) == 0) {
			return vector[i];
		}
	}
	return initializareMasina(1, 0, NULL, 0, '0');
}



void dezalocare(struct Masina** vector, int* nrElemente) {
	for (int i = 0; i < *nrElemente; i++) {
		free((*vector)[i].marca);
	}
	free(*vector);
	*vector = NULL;
	*nrElemente = 0;
}

int main() {
	struct Masina* vector;
	int nrElemente = 3;
	vector = (struct Masina*)malloc(nrElemente * sizeof(struct Masina));

	vector[0] = initializareMasina(1, 2, "Logan", 4000, 'A');
	vector[1] = initializareMasina(2, 3, "BMW", 5000, 'B');
	vector[2] = initializareMasina(3, 4, "Dacia", 2590, 'C');

	afisareVectorMasini(vector, nrElemente);

	printf("VectorNou copiat \n");
	struct Masina* vectorMasiniCopiate;
	int nrElementeCopiate = 2;
	vectorMasiniCopiate = copiazaPrimeleElemente(vector, nrElemente, nrElementeCopiate);
	afisareVectorMasini(vectorMasiniCopiate, nrElementeCopiate);

	dezalocare(&vectorMasiniCopiate, &nrElementeCopiate);

	printf("Afisare masini cu capacitatea mai mare");
	copiazaMasiniCuCCMare(vector, nrElemente, 4100, &vectorMasiniCopiate, &nrElementeCopiate);
	afisareVectorMasini(vectorMasiniCopiate, nrElementeCopiate);
	dezalocare(&vectorMasiniCopiate, &nrElementeCopiate);

	
	struct Masina m1 = getMasinaDupaMarca(vector, nrElemente, "BMW");
	printf("Masina dupa marca:");
	afisareMasina(m1);


	dezalocare(&vector, &nrElemente);


	return 0;
}*/

/*#include<stdio.h>
#include<malloc.h>

struct Masina {
	int id;
	int nrLocuri;
	char* marca;
	float capacitateC;
	char normaPoluare;
};

struct Masina initializareMasina(int id, int nrLocuri, const char* marca,
	float capacitateC, char normaPoluare) {
	struct Masina m;
	m.id = id;
	m.nrLocuri = nrLocuri;
	if (marca == NULL) {
		m.marca = NULL;
	}
	else {
		m.marca = (char*)malloc(strlen(marca) + 1);
		strcpy_s(m.marca, strlen(marca) + 1, marca);
	}
	m.capacitateC = capacitateC;
	m.normaPoluare = normaPoluare;
	return m;
}

void afisareMasina(struct Masina m) {
	printf("ID %d \n NrLocuri %d \n Marca %s \n Capacitate %.2f \n NormaPoluare %c \n",
		m.id, m.nrLocuri, m.marca, m.capacitateC, m.normaPoluare);
}

void afisareVectorMasina(struct Masina* vector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++) {
		afisareMasina(vector[i]);
	}
}

struct Masina* copiazaPrimeleMasini(struct Masina* vector, int nrElemente, int nrElementeCopiate) {
	if (nrElementeCopiate > nrElemente) {
		nrElementeCopiate = nrElemente;
	}
	struct Masina* vectorNou = NULL;
	vectorNou = (struct Masina*)malloc(nrElementeCopiate * sizeof(struct Masina));
	for (int i = 0; i < nrElementeCopiate; i++) {
		vectorNou[i] = initializareMasina(vector[i].id, vector[i].nrLocuri, vector[i].marca,
			vector[i].capacitateC, vector[i].normaPoluare);
	}
	return vectorNou;
}

void copiazaMasiniaCuCCMaiMare(struct Masina* vector, char nrElemente,
	float prag, struct Masina** vectorNou, int* dimensiune) {
	(*dimensiune) = 0;
	for (char i = 0; i < nrElemente; i++) {
		if (prag < vector[i].capacitateC) {
			(*dimensiune)++;
		}
	}
	
	if(*dimensiune > 0) {
		int j = 0; 
		*vectorNou = (struct Masina*)malloc((*dimensiune) * sizeof(struct Masina));
		for (int i = 0; i < nrElemente; i++) {
			if (prag < vector[i].capacitateC) {
				(*vectorNou)[j] = vector[i];
				(*vectorNou)[j].marca =(char*)malloc(sizeof(char) * (strlen(vector[i].marca) + 1));
				strcpy_s((*vectorNou)[j].marca, strlen(vector[i].marca) + 1, vector[i].marca);
				j++;
			}
		}

	}
}

struct Masina getUltimaPozitieDupaMarca(struct Masina* vector, int nrElemente,
	const char* conditie) {
	for (int i = nrElemente -1; i >= 0; i--) {
		if (strcmp(vector[i].marca, conditie) == 0) {
			return vector[i];
		}
	}
	return initializareMasina(0, 0, NULL, 0, '0');
}

struct Masina getPrimaMasinaDupaMarca(struct Masina* vector, int nrElemente, const char* conditie) {
	for (int i = 0; i < nrElemente; i++) {
		if (strcmp(vector[i].marca, conditie) == 0) {
			return vector[i];
		}
	}
	return initializareMasina(1, 0, NULL, 0, '0');
}

void dezalocare(struct Masina** vector, int* nrElemente) {
	for (int i = 0; i < *nrElemente; i++) {
		free((*vector)[i].marca);
	}
	free(*vector);
	*vector = NULL;
	*nrElemente = 0;
}

int main() {
	struct Masina* vector;
	int nrElem = 3;
	vector = (struct Masina*)malloc(nrElem * sizeof(struct Masina));

	vector[0] = initializareMasina(1, 3, "Dacia", 40, '5');
	vector[1] = initializareMasina(2, 5, "Honda", 30, '6');
	vector[2] = initializareMasina(3, 4, "Dacia", 50, '3');

	afisareVectorMasina(vector, nrElem);

	printf("Masini copiate: \n");

	struct Masina* vectorCopiat;
	int nrElemCopiate = 2;
	vectorCopiat = (struct Masina*)malloc(nrElemCopiate * sizeof(struct Masina));

	vectorCopiat = copiazaPrimeleMasini(vector, nrElem, nrElemCopiate);
	afisareVectorMasina(vectorCopiat, nrElemCopiate);
	dezalocare(&vectorCopiat, &nrElemCopiate);

	printf("Masini cu CC mai mare\n");
	copiazaMasiniaCuCCMaiMare(vector, nrElem, 33, &vectorCopiat, &nrElemCopiate);
	afisareVectorMasina(vectorCopiat, nrElemCopiate);
	dezalocare(&vectorCopiat, &nrElemCopiate);

	printf("Afisare masina dupa marca: \n");
	struct Masina m1;
	m1 = getPrimaMasinaDupaMarca(vector, nrElem, "Dacia");
	afisareMasina(m1);


	dezalocare(&vector, &nrElem);

	return 0;
}*/

/*#include<stdio.h>
#include<malloc.h>

struct Masina {
	int id;
	int anFabricatie;
	char* sofer;
	float kilometriiParcursi;
	char initialaProducator;
};

struct Masina initializareMasina(int id, int anFabricatie, const char* sofer,
	float kilometriiParcursi, char initialaProducator) {
	struct Masina m;
	m.id = id;
	m.anFabricatie = anFabricatie;
	if (sofer == NULL) {
		m.sofer = NULL;
	}
	else {
		m.sofer = (char*)malloc(strlen(sofer) + 1);
		strcpy_s(m.sofer, strlen(sofer) + 1, sofer);
	}
	m.kilometriiParcursi = kilometriiParcursi;
	m.initialaProducator = initialaProducator;
	return m;
}

void afisareMasina(struct Masina m) {
	printf(" ID %d \n AnFabricatie %d \n Sofer %s \n KilometriiParcursi %2.f \n InitialaProd %c \n",
		m.id, m.anFabricatie, m.sofer, m.kilometriiParcursi, m.initialaProducator);
}

void afisareVectorMasina(struct Masina* vector, int nrElemente) {
	if (vector != NULL && nrElemente > 0) {
		for (int i = 0; i < nrElemente; i++) {
			afisareMasina(vector[i]);
		}
	}
}

struct Masina* copiazaPrimeleElemente(struct Masina* vector, int nrElemente, int nrElementeCopiate) {
	if (nrElementeCopiate > nrElemente) {
		nrElementeCopiate = nrElemente;
	}
	struct Masina* vectorNou = NULL;
	vectorNou = malloc(nrElementeCopiate * sizeof(struct Masina));
	for (int i = 0; i < nrElementeCopiate; i++) {
		vectorNou[i] = initializareMasina(vector[i].id, vector[i].anFabricatie, vector[i].sofer, vector[i].kilometriiParcursi, vector[i].initialaProducator);
	}
	return vectorNou;
}

void copiazaMasiniCuMultiKM(struct Masina* vector, char nrElemente, 
	float prag, struct Masina** vectorNou, int* dimensiune) {
	(*dimensiune) = 0;
	for (char i = 0; i < nrElemente; i++) {
		if (prag < vector[i].kilometriiParcursi) {
			(*dimensiune)++;
		}
	}
	if (*dimensiune > 0)
	{
		int j = 0;
		(*vectorNou) = (struct Masina*)malloc((*dimensiune) * sizeof(struct Masina));
		for (int i = 0; i < nrElemente; i++) {
			if (prag < vector[i].kilometriiParcursi)
			{
				(*vectorNou)[j] = vector[i];
				(*vectorNou)[j].sofer = malloc(sizeof(char) * (strlen(vector[i].sofer) + 1));
				strcpy_s((*vectorNou)[j].sofer, strlen(vector[i].sofer) + 1, vector[i].sofer);
				j++;
			}
		}
	}

}

struct Masina getPrimaMasinaDupaSofer(struct Masina* vector, int nrElemente, const char* conditie) {
	if (vector != NULL && nrElemente > 0)
	{
		for (int i = 0; i < nrElemente; i++) {
			if (strcmp(vector[i].sofer, conditie) == 0)
			{
				return vector[i];
			}
		}
		return initializareMasina(0, 0, NULL, 0, '0');
	}
}

void dezalocare(struct Masina** vector, int* nrElemente) {
	if ((*vector) != NULL & (*nrElemente) > 0) {
		for (int i = 0; i < (*nrElemente); i++) {
			free((*vector)[i].sofer);
		}
		free(*vector);
		*vector = NULL;
		*nrElemente = 0;
	}
}

int main() {
	struct Masina* vector;
	int nrElemente = 3;
	vector = (struct Masina*)malloc(nrElemente * sizeof(struct Masina));
	vector[0] = initializareMasina(1, 2010, "Marian", 2100, 'F');
	vector[1] = initializareMasina(2, 2008, "Cristi", 1500.6, 'A');
	vector[2] = initializareMasina(3, 2017, "Marian", 7500, 'M');

	afisareVectorMasina(vector, nrElemente);

	printf("Vector copiat \n");
	struct Masina* vectorNou;
	int nrElementeCopiate = 2;
	vectorNou = copiazaPrimeleElemente(vector, nrElemente, nrElementeCopiate);
	afisareVectorMasina(vectorNou, nrElementeCopiate);
	dezalocare(&vectorNou, &nrElementeCopiate);

	printf("Masini cu km mai mari\n");
	copiazaMasiniCuMultiKM(vector, nrElemente, 2000, &vectorNou, &nrElementeCopiate);
	afisareVectorMasina(vectorNou, nrElementeCopiate);
	dezalocare(&vectorNou, &nrElementeCopiate);

	struct Masina m1;
	printf("Masina dupa sofer \n");
	m1 = getPrimaMasinaDupaSofer(vector, nrElemente, "Marian");
	afisareMasina(m1);

	dezalocare(&vector, &nrElemente);
	return 0;
}*/

/*#include<stdio.h>
#include<malloc.h>

struct Masina {
	int id;
	int nrKm;
	char* model;
	float pret;
	char tipMotor;
};

struct Masina initializareMasina(int id, int nrKm, const char* model,
	float pret, char tipMotor) {
	struct Masina m;
	m.id = id;
	m.nrKm = nrKm;
	if (model == NULL) {
		m.model = NULL;
	}
	else {
		m.model = (char*)malloc(strlen(model) + 1);
		strcpy_s(m.model, strlen(model) + 1, model);
	}
	m.pret = pret;
	m.tipMotor = tipMotor;
	return m;
}

void afisareMasina(struct Masina m) {
	printf("ID %d \n NrKm %d \n Model %s \n Pret %.2f \n TipMotor %c \n",
		m.id, m.nrKm, m.model, m.pret, m.tipMotor);
}

void afisareVectorMasina(struct Masina* vector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++) {
		afisareMasina(vector[i]);
	}
}

struct Masina* copiazaPrimeleElemente(struct Masina* vector, int nrElemente,
	int nrElementeCopiate) {
	if (nrElementeCopiate > nrElemente) {
		nrElementeCopiate = nrElemente;
	}
	struct Masina* vectorNou = NULL;
	vectorNou = (struct Masina*)malloc(nrElementeCopiate * sizeof(struct Masina));
	for (int i = 0; i < nrElementeCopiate; i++) {
		vectorNou[i] = initializareMasina(vector[i].id, vector[i].nrKm,
			vector[i].model, vector[i].pret, vector[i].pret, vector[i].tipMotor);
	}
	return vectorNou;
}

void copiazaMasinaIeftine(struct Masina* vector, char nrElemente, float prag,
	struct Masina** vectorNou, int* dimensiune) {
	(*dimensiune) = 0;
	for (char i = 0; i < nrElemente; i++) {
		if (prag > vector[i].pret) {
			(*dimensiune)++;
		}
	}
	int j = 0;
	(*vectorNou) = (struct Masina*)malloc((*dimensiune) * sizeof(struct Masina));
	for (int i = 0; i < nrElemente; i++) {
		if (prag > vector[i].pret) {
			(*vectorNou)[j] = vector[i];
			(*vectorNou)[j].model = malloc(sizeof(char) * strlen(vector[i].model) + 1);
			strcpy_s((*vectorNou)[j].model, (strlen(vector[i].model) + 1), (vector)[i].model);
			j++;
		}
	}
}

struct Masina getPrimulElementConditionat(struct Masina* vector, int nrElemente, const char* conditie) {
	for (int i = 0; i < nrElemente; i++) {
		if (strcmp(vector[i].model, conditie) == 0) {
			return vector[i];
		}
	}
	return initializareMasina(0, 0, NULL, 0, '0');
}

void dezalocareVector(struct Masina** vector, int* nrElemente) {
	for (int i = 0; i < (*nrElemente); i++) {
		if ((*vector)[i].model != NULL) {
			free((*vector)[i].model);
		}
	}
	free(*vector);
	(*vector) = NULL;
	*nrElemente = 0;
}

int main() {
	struct Masina* vector;
	int nrElemente = 3;
	vector = (struct Masina*)malloc(nrElemente * sizeof(struct Masina));
	vector[0] = initializareMasina(10, 100000, "Logan", 1000.4, 'd');
	vector[1] = initializareMasina(11, 1000, "Passat", 2500.4, 'b');
	vector[2] = initializareMasina(12, 25464, "Cyber Truck", 1000.0, 'e');

	afisareVectorMasina(vector, nrElemente);
	
	printf("Vector copiat:\n");
	struct Masina* vectorNou;
	int nrElemeneteCopiate = 2;
	vectorNou = (struct Masina*)malloc(nrElemeneteCopiate * sizeof(struct Masina));
	vectorNou = copiazaPrimeleElemente(vector, nrElemente, nrElemeneteCopiate);
	afisareVectorMasina(vectorNou, nrElemeneteCopiate);
	dezalocareVector(&vectorNou, &nrElemeneteCopiate);

	printf("Copiaza masini mai ieftine: \n");
	copiazaMasinaIeftine(vector, nrElemente, 1500, &vectorNou, &nrElemeneteCopiate);
	afisareVectorMasina(vectorNou, nrElemeneteCopiate);
	dezalocareVector(&vectorNou, &nrElemeneteCopiate);

	printf("Returneaza prima masina cu o conditie\n");
	struct Masina m1;
	m1 = getPrimulElementConditionat(vector, nrElemente, "Passat");
	afisareMasina(m1);


	dezalocareVector(&vector, &nrElemente);
	return 0;
}*/

#include<stdio.h>
#include<malloc.h>

struct Masina {
	int id;
	char* model;
	float tonaj;
	char serie;
};

struct Masina initializareMasina(int id, const char* model, float tonaj, char serie) {
	struct Masina m;
	m.id = id;
	if (model == NULL) {
		m.model = NULL;
	}
	else {
		m.model = (char*)malloc(strlen(model) + 1);
		strcpy_s(m.model, strlen(model) + 1, model);
	}
	m.tonaj = tonaj;
	m.serie = serie;
	return m;
}

void afisareMasina(struct Masina m) {
	printf(" Id %d \n Model %s \n Tonaj %.2f \n Serie %c \n",
		m.id, m.model, m.tonaj, m.serie);
}

void afisareVectorMasina(struct Masina* vector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++) {
		afisareMasina(vector[i]);
	}
}

struct Masina* copiazaPrimeleMasini(struct Masina* vector, int nrElemente, 
	int nrElementeCopiate) {
	if (nrElementeCopiate > nrElemente) {
		nrElementeCopiate = nrElemente;
	}
	struct Masina* vectorNou = NULL;
	vectorNou = (struct Masina*)malloc(nrElementeCopiate * sizeof(struct Masina));
	for (int i = 0; i < nrElementeCopiate; i++) {
		vectorNou[i] = initializareMasina(vector[i].id, vector[i].model,
			vector[i].tonaj, vector[i].serie);
	}
	return vectorNou;
	
}

void copiazaMasiniUsoare(struct Masina* vector, int nrElemente, float prag,
	struct Masina** vectorNou, int* dimensiune) {
	(*dimensiune) = 0;
	for (int i = 0; i < nrElemente; i++) {
		if (prag > vector[i].tonaj) {
			(*dimensiune)++;
		}
	}
	(*vectorNou) = (struct Masina*)malloc((*dimensiune) * sizeof(struct Masina));
	int j = 0;
	for (int i = 0; i < nrElemente; i++) {
		if (prag > vector[i].tonaj) {
			(*vectorNou)[j] = vector[i];
			(*vectorNou)[j].model = malloc(sizeof(char) * (strlen(vector[i].model) + 1));
			strcpy_s((*vectorNou)[j].model, (strlen(vector[i].model) + 1), vector[i].model);
			j++;
		}
	}
}

struct Masina getPrimulElementConditionat(struct Masina* vector, int nrElemente, const char* conditie) {
	for (int i = 0; i < nrElemente; i++) {
		if (strcmp(vector[i].model, conditie) == 0) {
			return vector[i];
		}
	}
	return initializareMasina(0, NULL, 0, '0');
}

void dezalocareVector(struct Masina** vector, int* nrElemente) {
	for (int i = 0; i < *nrElemente; i++) {
		free((*vector)[i].model);
	}
	free(*vector);
	(*vector) = NULL;
	*nrElemente = 0;
}

int main() {
	struct Masina* vector;
	int nrElemente = 3;
	vector = (struct Masina*)malloc(nrElemente * sizeof(struct Masina));
	vector[0] = initializareMasina(2, "Mercedes", 2.2, 'S');
	vector[1] = initializareMasina(3, "Audi", 2.6, 'Q');
	vector[2] = initializareMasina(4, "Dacia", 1.8, 'Z');
	afisareVectorMasina(vector, nrElemente);

	printf("Vector cu primele masini \n");
	struct Masina* vectorNou;
	int nrElementeCopiate = 2;
	vectorNou = (struct Masina*)malloc(nrElementeCopiate * sizeof(struct Masina));
	vectorNou = copiazaPrimeleMasini(vector, nrElemente, nrElementeCopiate);
	afisareVectorMasina(vectorNou, nrElementeCopiate);

	printf("Masini usoare \n");
	copiazaMasiniUsoare(vector, nrElemente, 2.3, &vectorNou, &nrElementeCopiate);
	afisareVectorMasina(vectorNou, nrElementeCopiate);
	dezalocareVector(&vectorNou, &nrElementeCopiate);

	printf("Masina dupa criteriu \n");
	struct Masina m1;
	m1 = getPrimulElementConditionat(vector, nrElemente, "Audi");
	afisareMasina(m1);

	dezalocareVector(&vector, &nrElemente);

	return 0;
}