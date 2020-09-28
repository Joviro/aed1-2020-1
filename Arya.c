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

void insere_primeiros(lista, inimigo){

    LISTA* end = lista->inicio;
    if(end == NULL){
    
      INIMIGO* inimigx = (INIMIGO*) malloc (sizeof(INIMIGO));
      lista->inicio = ini;	     
      inimigx->ini.chave = inimigo;
      inimigx->prox = NULL;	    	    
    }
   else{
    INIMIGO* inimigx;
    inimigx = lista->inicio;	   
    while(inimigx != NULL){

         inimigx = inimigx->prox;  
    
    }
   INIMIGO* inimigox = (INIMIGO*) malloc (sizeof(INIMIGO));
   inimigx->proximo = inimigox;
   inimigox->proximo = NULL;
   iminigox->ini.TIPOCHAVE = inimigo;	   
	   
  } 	
}

void insere(LISTA* lista, int chave, int anterior){

     Lista* end = lista->inicio;
     while(end != NULL){
     
     }	

}

void remove(LISTA* lista, TIPOCHAVE c){

}

void quantidade_intervalo(Lista* lista, TIPOCHAVE a, TIPOCHAVE b){

}

void quantidade_total(LISTA* lista){
	
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

INIMIGO buscaInimigo (LISTA *lista, TIPOCHAVE chave, INIMIGO *ant){
    ant = NULL;
    INIMIGO *atual;
    atual = lista->inicio;
}



int main (){
	char menu;
	int inimigo, loop = 1, inimigos_loop;
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
        insere_primeiros(lista, inimigo);	
        loop++;
        }

	while(menu != 'F'){
	printf("Bem vindo ao menu:\nDigite I para adicionar um elemento\nDigite R para remover um elemento\nDigite C para mostrar os valores em um intervalo de elementos\nDigite M para mostrar todos os elementos da fila\nDigite F para finalizar o programa\n\n");		
	scanf("%c", &menu);
	if(menu == 'I'){
	
	   printf("Digite a chave do elemento e qual será o elemento anterior a ele: \n");
	   int chave, anterior;		
	   insere(lista, chave, anterior);		
	}
	else if(menu == 'R');
	else if(menu == 'C');	
	else if(menu == 'M');
	else printf("Não existe essa operação. Tente novamente!\n");
	
	}
	
    printf("fim\n");

    return 0;
}

