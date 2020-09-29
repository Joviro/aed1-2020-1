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

int buscaInimigo (LISTA *lista, int chave){
    INIMIGO* l = lista->inicio;
    while(l != NULL){

        if(l->ini.chave == chave) return 1;

        l = l->proximo;
    }
    return 0;
}

int insere(LISTA* lista, int chave, int anterior){

    int busca_Chave = buscaInimigo(lista, chave);
    int busca_Anterior = buscaInimigo(lista, anterior);
    if(anterior == -1) busca_Anterior = 1;

    if(busca_Chave == 1 || busca_Anterior == 0){
        return 0;
    }

    INIMIGO* end = lista->inicio;

    if(end == NULL || anterior == -1){

      INIMIGO* inimigo_Novo = (INIMIGO*) malloc (sizeof(INIMIGO));
      lista->inicio = inimigo_Novo;
      inimigo_Novo->ini.chave = chave;
      inimigo_Novo->proximo = NULL;
      return 1;
    }
    else{

        while(end->ini.chave != anterior){

            end = end->proximo;

        }

        INIMIGO* inimigo_Novo = (INIMIGO*) malloc (sizeof(INIMIGO));
        if(end->proximo == NULL) inimigo_Novo->proximo = NULL;
        else inimigo_Novo->proximo = end->proximo;
        end->proximo = inimigo_Novo;
        inimigo_Novo->ini.chave = chave;
        return 1;
    }
}


int remover(LISTA* lista, TIPOCHAVE chave){

    int busca_Chave = buscaInimigo(lista, chave);
    if(busca_Chave == 0) return 0;

    INIMIGO* anterior = lista->inicio;
    INIMIGO* inimigo = lista->inicio;

    while(inimigo->ini.chave != chave){

        anterior = inimigo;
        inimigo = inimigo->proximo;

    }

    if(inimigo == lista->inicio){

        lista->inicio = inimigo->proximo;
        free(inimigo);
        return 1;
    }

    else{

        anterior->proximo = inimigo->proximo;
        free(inimigo);
        return 1;

    }
}

int quantidade(LISTA* lista, TIPOCHAVE chave_1, TIPOCHAVE chave_2){

    int busca_Chave_1 = buscaInimigo(lista, chave_1);
    int busca_Chave_2 = buscaInimigo(lista, chave_2);

    if(busca_Chave_1 == 0 || busca_Chave_2 == 0){
        return -1;
    }

    else{
        int distancia_1 = 0, distancia_2 = 0;
        int quantidade = 0;
        INIMIGO* ponteiro_1 = lista->inicio;
        INIMIGO* ponteiro_2 = lista->inicio;

        while(ponteiro_1->ini.chave != chave_1){

            ponteiro_1 = ponteiro_1->proximo;
            distancia_1++;

        }

        while(ponteiro_2->ini.chave != chave_2){

            ponteiro_2 = ponteiro_2->proximo;
            distancia_2++;

        }

        if(distancia_1 > distancia_2){

            while(ponteiro_1->ini.chave != ponteiro_2->ini.chave){

                ponteiro_2 = ponteiro_2->proximo;
                quantidade++;

            }
        }

        else{

            while(ponteiro_1->ini.chave != ponteiro_2->ini.chave){

                ponteiro_1 = ponteiro_1->proximo;
                quantidade++;
            }
         }
        return quantidade - 1;
    }
}

void mostrar_Lista(LISTA* lista){

    INIMIGO* end = lista->inicio;
    if(end == NULL){
        printf("lista vazia\n");
        return;
    }
    else{

        printf ("lista ");
        while (end != NULL){
            printf ("%d ", end->ini.chave);
            end = end->proximo;
        }
    }
    printf ("\n");
}



int main (){
	char menu;
	int inimigo, loop = 1, inimigos_loop, anterior;
	anterior = -1;
	menu = ' ';

	LISTA* lista = (LISTA*) malloc (sizeof(LISTA));
	iniciarLista(lista);

	//printf("Quantos inimigos teremos inicialmente?\n");
	scanf("%i", &inimigos_loop);
	//Insere os primeiros elementos:
	for(int x = 0; x < inimigos_loop; x++){
        //printf("Qual o valor do inimigo numero %i: \n",loop);
        scanf("%i", &inimigo);
        insere(lista, inimigo, anterior);
        anterior = inimigo;
        loop++;
    }

	while(menu != 'F'){
		//printf("Bem vindo ao menu:\nDigite I para adicionar um elemento\nDigite R para remover um elemento\nDigite C para mostrar os valores em um intervalo de elementos\nDigite M para mostrar todos os elementos da fila\nDigite F para finalizar o programa\n\n");

		scanf("%c", &menu);

        // printf("MENU: %c\n", &menu);


		if(menu == 'I'){
	   		// printf("Digite a chave do elemento e qual será o elemento anterior a ele: \n");
	   		int chave, anterior;
	   		scanf("%i %i",&chave,&anterior);
	   		int x = insere(lista, chave, anterior);
            if(x == 1) printf("inserido %i\n",chave);
		}
		else if(menu == 'R'){
            // printf("Digite a chave do elemento que deseja remover: \n");
            int chave;
            scanf("%i",&chave);
            int x = remover(lista,chave);
            if(x == 1) printf("removido %i\n",chave);
		}


		else if(menu == 'C'){
            // printf("Digite a chave do elemento que deseja remover: \n");
            int chave_1, chave_2;
            scanf("%i %i",&chave_1,&chave_2);
            int x = quantidade(lista,chave_1,chave_2);
            if(x != -1) printf("quantidade %i\n",x);

		}


		else if(menu == 'M'){

			mostrar_Lista(lista);
		}
		//else printf("Nao existe essa operaçao. Tente novamente!\n");

	}

    printf("fim\n");

    return 0;
}
