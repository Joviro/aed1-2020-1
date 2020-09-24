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


void insere(LISTA* lista, int inimigo){}
void exclui(){}
void quantidade_intervalo(){}
void quantidade(){}



int main (){

	char menu, inimigos_loop;
	int inimigo,loop = 1;
	menu = 'Z';

	LISTA* lista;
	lista->inicio = NULL;

	printf("Quantos inimigos teremos inicialmente?\n");
	scanf("%i", &inimigos_loop);

	//Insere os primeiros elementos:
	for(int x = 0; x < inimigos_loop; x++){
        printf("Qual o valor do inimigo numero %i: \n",loop);
        scanf("%i", inimigo);
        insere(lista, inimigo);
        loop++;
	}

	for(int x = 0; x < inimigos_loop; x ++){

        insere(lista, inimigo);

	}

	while(menu != 'F'){



	}

    printf("fim\n");

    return 0;
}
