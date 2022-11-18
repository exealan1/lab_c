#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
		char *Continente;
		int mes;
		}continente;

continente *conti;

void vaciar(char temp[]);
void copiar(char temp[], int i);

int main(){
	int i,j;
	char aux;
	char temp[50];
	int cont = 0;
	printf("Bienvenido al programa: \n");
	FILE *f;
	f = fopen("Continente.txt","r");
	if(f == NULL) {
		printf("No se ha podido abrir el fichero. \n");
		exit(1);
	}

	while (!feof(f)){
		fgets(temp,50,f);
		cont++;
	}

	rewind(f);

	conti = (continente*)malloc(cont*sizeof(continente));
	if (conti == NULL) {
		printf("No se ha reservar el espacio. \n");
		exit(1);
	}

	for (i = 0; !feof(f); i++){
		vaciar(temp);
		for (j = 0; aux != '-'; j++) {
			aux = fgetc(f);
			if (aux != '-'){
				temp[j] = aux;
			}
		}
		copiar(temp,i);
		fgets(temp,4,f);
		conti[i].mes = atoi(temp);
		printf("Continente: %s mes %i. \n", conti[i].Continente, conti[i].mes);
	}

	system("pause");
	return 0;
}

void vaciar(char temp[]){
	int i;

	for (i = 0; i < 50; i++){
		temp[i] = '\0';
	}
}

void copiar(char temp[], int i){
	int N = strlen(temp) + 1;
	conti[i].Continente = (char*)malloc(N*sizeof(char));
	if (conti[i].Continente == NULL){
		printf("No se ha podido reservar memoria. \n");
		exit(1);
	}
	strcpy(conti[i].Continente,temp);
}