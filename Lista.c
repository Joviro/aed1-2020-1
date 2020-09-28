#include <stdio.h>
#include <stdlib.h>
typedef int TIPOCHAVE;

typedef struct{
	TIPOCHAVE chave;
} NOME;

typedef struct aux{
	NOME ini;
	struct aux* proximo;
} INIMIGO;

typedef struct{
	INIMIGO* inicio;

}LISTA;

void iniciarLista (LISTA *lista){
    lista->inicio = NULL;
}

void insere(LISTA* lista, int inimigo){


}

INIMIGO buscaInimigo (LISTA *lista, TIPOCHAVE chave, INIMIGO *ant){
    ant = NULL;
    INIMIGO *atual;
    atual = lista->inicio;
}

//void insere(LISTA* lista, int inimigo){}
void exclui(){}

void quantidade_intervalo(){}

void quantidade(LISTA *lista){
    INIMIGO *end = lista->inicio;
    int tam = 0;
    printf ("lista ");
    while (end != NULL){
        printf ("%d", end->ini.chave);
        tam++;
        end = end->proximo;
    }
    printf ("\n");
}



int main (){
	char menu;
	int inimigo,loop = 1, inimigos_loop;
	menu = 'Z';

	LISTA l;
	LISTA* lista = &l;
	iniciarLista(lista);

	printf("Quantos inimigos teremos inicialmente?\n");
	scanf("%i", &inimigos_loop);
	//Insere os primeiros elementos:
	for(int x = 0; x < inimigos_loop; x++){
        printf("Qual o valor do inimigo numero %i: \n",loop);
        scanf("%i", &inimigo);
        insere(lista, inimigo);
        loop++;
        }

	while(menu != 'F'){


	if(menu == 'A');


	}
    printf("fim\n");

    return 0;
}

