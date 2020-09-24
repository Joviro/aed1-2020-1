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

TIPOCHAVE insere(LISTA* lista, int inimigo){

}

INIMIGO buscaInimigo (LISTA *lista, TIPOCHAVE chave, INIMIGO *ant){
    *ant = NULL;
    INIMIGO atual;
    atual = lista->inicio;
}

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

	char menu, inimigos_loop;
	int inimigo,loop = 1;
	menu = 'Z';

	LISTA* lista;
	iniciarLista(lista);

	printf("Quantos inimigos teremos inicialmente?\n");
	scanf("%i", &inimigos_loop);

	//Insere os primeiros elementos:
	for(int x = 0; x < inimigos_loop; x++){
        printf("Qual o valor do inimigo numero %i: \n",loop);
        scanf("%i", inimigo);
        insere(lista, inimigo);
        loop++;
	}

	while(menu != 'F'){



	}

    printf("fim\n");

    return 0;
}