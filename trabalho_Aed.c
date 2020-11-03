#include <stdio.h>
#include <stdlib.h>


// Iremos transformar o arquivo em lista e depois colocaremos a lista em forma de arquivo novamente.
// Será organizado em: Datas, os novos serão postos abaixo do último do seu rank.



typedef struct{

	char conteudo[100];
    char categoria[20];
    char comentario[100];
    int horario_1, horario_2;
    int rank;
    int dia, mes, ano;

}REGISTRO ;

typedef struct aux{

	REGISTRO reg;
	struct aux* proximo;

} AGENDA;


typedef struct{
	
    AGENDA* inicio;

}LISTA;


int adiciona_Agendamento(LISTA* l, char conteudo[100], char categoria[20], char comentario[100], int horario_1, int horario_2, int rank, int dia, int mes, int ano){

    return 0;
}


void adiciona_Arquivo(){

}



int main (){

    int menu = 100;
    LISTA* l = (LISTA*) malloc(sizeof(LISTA));
    l->inicio = NULL;
    char conteudo[100];
    char categoria[20];
    char comentario[100];
    int horario_1, horario_2;
    int rank;
    int dia, mes, ano;
    // adicionar os agendamentos presentes no arquivo à lista.
    adiciona_Arquivo();  
   
    while(1){

        printf("\nBem vindo ao menu!\nDigite:\n1 - para adicionar um agendamento.\n2 - para remover um agendamento.\n...\n0 - para encerrar o progama.\n");
        scanf("%i",&menu);

        if(menu == 1){

            printf("Qual o dia do agendamento? %i %i");    
            adiciona_Agendamento(l, conteudo, categoria, comentario, horario_1, horario_2, rank, dia, mes, ano); 
        }
        //...
        else if(menu == 0){
            printf("Ate mais!\n");  
            return 0;
        }    
        else printf("Numero invalido\n");

    } 

    return 0;
}
