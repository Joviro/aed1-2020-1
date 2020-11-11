#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


// Iremos criar uma lista e depois adicioná-la ao arquivo.
// Será organizado em: Datas, os novos serão postos no seu rank organizado por horário.


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

void insere(LISTA* lista, int cor){
 
    ANAO* end = lista->inicio;
 
    if(end == NULL){
 
      ANAO* anao_Novo = (ANAO*) malloc (sizeof(ANAO));
      lista->inicio = anao_Novo;
      anao_Novo->coloracao.cor_Chapeu = cor;
      anao_Novo->proximo = NULL;
      return;
    }
    else{
 
        while(end->proximo != NULL){
 
            end = end->proximo;
 
        }
 
        ANAO* anao_Novo = (ANAO*) malloc (sizeof(ANAO));
        anao_Novo->proximo = NULL;
        end->proximo = anao_Novo;
        anao_Novo->coloracao.cor_Chapeu = cor;
        return;
    }
}

void adiciona_Agendamento(LISTA* l, char conteudo[100], char categoria[20], char comentario[100], int horario_1, int horario_2, int rank, int dia, int mes, int ano){

    

    return 0;
}

int validaAtributos(int dia,int mes,int ano,int horario_1,int horario_2,int rank){
    int correto = 1;

    if(horario_1 > 23 || horario_1 < 0){

        printf("As horas estao no formato errado. As horas sao contadas de 0 ate 23.\n");
        correto = correto * 3;
    }
    if(horario_2 < 0 || horario_2 > 59){

        printf("Os minutos estao no formato errado. Os minutos sao contados de 0 ate 59.\n");
        correto = correto * 3;
    }

    if(mes > 12 || mes < 1){

        printf("O mes esta no formato errado. Os meses sao contados de 1 ate 12.\n");
        correto = correto * 2;

    }

    if(dia > 31 || dia < 1){

        printf("O dia esta no formato errado. Os dias sao contados de 1 ate 31, dependendo do mes.\n");
        correto = correto * 2;
    }

    else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){

        if(dia == 31){

            printf("O dia esta no formato errado. O mes %i vai so ate dia 30.\n",mes);
            correto = correto * 2;

        }
    }

    else if(mes == 2){
        if(dia > 29){

            printf("O dia esta no formato errado. O mes %i vai so ate dia 29 (em anos bissextos).\n",mes);
            correto = correto * 2;

        }

    }


    if(ano < 2021 || ano > 2110){

        printf("O ano esta no formato errado. O ano deve ser maior que 2021 e menor que 2110.\n");
        correto = correto * 2;

    }


    if(rank > 10 || rank < 0){

        printf("O rank esta no formato errado. O rank sao contados de 0 ate 10.\n");
        correto = correto * 5;

    }

    return correto;
}


void adiciona_Arquivo(LISTA* lista){

}



int main (){

    char menu = 'A';
    LISTA* l = (LISTA*) malloc(sizeof(LISTA));
    l->inicio = NULL;
    char conteudo[100];
    char categoria[20];
    char lixos[20];
    char comentario[100];
    char res[3] = "aba";
    char lixo;
    int horario_1, horario_2;
    int rank;
    int dia, mes, ano;
    int correto = 0;  
   
    while(1){

        printf("\nBem vindo ao menu!\nDigite:\n1 - para adicionar um agendamento.\n2 - para remover um agendamento.\n...\n5 - para o formato das funcoes.\n0 - para encerrar o progama.\n");
        scanf("%c",&menu);

        if(menu == '1'){

                while(correto != 1){

                    if(correto % 2 == 0){
                        printf("Qual a data do agendamento?\n");
                        scanf("%i %c %i %c %i",&dia,&lixo,&mes,&lixo,&ano);
                    }
                    if(correto % 3 == 0){    
                        printf("Qual o horario do agendamento?\n");
                        scanf("%i %c %i",&horario_1,&lixo,&horario_2);
                    }
                    if(correto % 5 == 0){
                     printf("Qual o rank do agendamento?\n");
                     scanf("%i",&rank);
                    } 
                    correto = validaAtributos(dia,mes,ano,horario_1,horario_2,rank);
                }

                gets(lixos);

                printf("Qual a categoria do agendamento?\n");
                gets(categoria);

                printf("Qual o conteudo do agendamento?\n");
                gets(conteudo);

                printf("Deseja adicionar um comentario?\n");
                gets(res);

                while(strcmp(res,"Sim")!=0  && strcmp(res,"Nao")!=0){
                    printf("Valor invalido! Digite \"Sim\" para adicionar um comentario ou \"Nao\" para nao adicionar.\n");
                    gets(res);
                }
                if(strcmp(res,"Sim") == 0){
                    printf("Digite o comentario:\n");
                    gets(comentario);
                    adiciona_Agendamento(l, conteudo, categoria, comentario, horario_1, horario_2, rank, dia, mes, ano);
                }
                else{
                    adiciona_Agendamento(l, conteudo, categoria, "<>", horario_1, horario_2, rank, dia, mes, ano);
                }   
            
            printf("\n\nAgendamento adicionado com sucesso!\n\n"); 
        }

        else if(menu == '5'){

            printf("--------------------------------------------------------------------------------------------------------------\nA data deve ser da forma: dia/mes/ano.\nO horario deve ser da forma: horas:minutos.\nO rank e crescente na ordem de 0 ate 10.\nA categoria e uma frase curta que resume do que o agendamento se trata (Exemplos: Familia, Amigos, Festa...).\nO conteudo e o agendamento em si (Exemplos: Entrevista de emprego na empresa X, levar curriculo...).\nPor fim, o comentario vai da sua escolha.\n--------------------------------------------------------------------------------------------------------------\n");

        }

        
        else if(menu == '0'){
            adiciona_Arquivo(l);
            printf("Ate mais!\n");  
            return 0;
        }

        else printf("Numero invalido\n");

        gets(lixos);
    } 

    return 0;
}
