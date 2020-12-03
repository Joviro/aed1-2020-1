#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


// Iremos criar uma lista e depois adicioná-la ao arquivo.
// Será organizado em: Datas, os novos serão postos no seu rank organizado por horário.

#define MAX 10000


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

// EXCLUIR

void mostra_Lista(LISTA* lista){
    AGENDA* end = lista->inicio;
    int x;

    if(end == NULL){
        printf("Lista vazia\n");
        return;
    }

    while(end != NULL){

        printf("Data: %i/%i/%i Horario: %i:%i Rank: %i ",end->reg.dia, end->reg.mes, end->reg.ano, end->reg.horario_1, end->reg.horario_2, end->reg.rank);
        
        printf("Conteudo: ");        

        for(x = 0; x < 100; x++){
            if(end->reg.conteudo[x] != ' ') printf("%c",end->reg.conteudo[x]);;
        }

        printf("Categoria: ");        
        
        for(x = 0; x < 20; x++){
            if(end->reg.categoria[x] != ' ') printf("%c",end->reg.categoria[x]);;
        }

        printf("Comentario: ");        
        
        for(x = 0; x < 100; x++){
            if(end->reg.comentario[x] != ' ') printf("%c",end->reg.comentario[x]);;
        }

        printf("\n");

        end = end->proximo;
     }
     return;
}


// ...

void exclui_Agendamentos(LISTA* lista,int dia, int mes, int ano, int horario_1, int horario_2){

    AGENDA* end = lista->inicio;
    AGENDA* exclui = lista->inicio;

    while(exclui->reg.dia != dia || exclui->reg.mes != mes || exclui->reg.ano != ano || exclui->reg.horario_1 != horario_1 || exclui->reg.horario_2 != horario_2){

        end = exclui;
        exclui = exclui->proximo;
    }

    if(exclui == lista->inicio){
        lista->inicio = exclui->proximo;
    }

    else{

        end->proximo = exclui->proximo;
    }

    free(exclui);
}


void adiciona_Agendamento(LISTA* lista, char conteudo[100], char categoria[20], char comentario[100], int horario_1, int horario_2, int rank, int dia, int mes, int ano){

    AGENDA* end = lista->inicio;
    AGENDA* novo = lista->inicio;
    AGENDA* agenda = (AGENDA*) malloc (sizeof(AGENDA));
    int i, j;
    
    for(i = 0; i < 100; i++){

        agenda->reg.conteudo[i] = conteudo[i];
        agenda->reg.comentario[i] = comentario[i];

    }

    for(j = 0; j < 20; j++){

        agenda->reg.categoria[j] = categoria[j];

    }
    agenda->reg.horario_1 = horario_1;
    agenda->reg.horario_2 = horario_2;
    agenda->reg.rank = rank;
    agenda->reg.dia = dia;
    agenda->reg.mes = mes;
    agenda->reg.ano = ano;


    if(end == NULL){
 
        lista->inicio = agenda;
        agenda->proximo = NULL;
        return;
    }

    else{
        while(end != NULL && end->reg.dia <= dia && end->reg.mes <= mes && end->reg.ano <= ano && end->reg.horario_1 <= horario_1 && end->reg.horario_2 <= horario_2 ){
            novo = end;
            end = end->proximo;
        }

        if(end == lista->inicio){
            lista->inicio = agenda;
            agenda->proximo = novo;
        }
            
        
        else{
        agenda-> proximo = novo->proximo;    
        novo->proximo = agenda;
       
        }
    }



    return;
}

int validaUnico(LISTA* lista,int dia, int mes, int ano, int horario_1, int horario_2){

    AGENDA* end = lista->inicio;
    while(end != NULL){

        if(end->reg.ano == ano && end->reg.mes == mes && end->reg.dia == dia && end->reg.horario_1 == horario_1 && end->reg.horario_2 == horario_2 ) return 1;
        end = end->proximo;
    }

    return 0;
}


int validaAtributos(LISTA* lista,int dia,int mes,int ano,int horario_1,int horario_2,int rank, int caso){
    
    int correto = 1;


    if(validaUnico(lista, dia, mes, ano, horario_1, horario_2) == 1 && caso == 0){

        printf("<Erro de Sobrescrita> ------Ja existe um agendamento nesse dia e hora! Tente novamente!------\n");

        return 2 * 3 * 5;
    }

    if(validaUnico(lista, dia, mes, ano, horario_1, horario_2) != 1 && caso == 1){

        printf("<Erro de Exclusao> ------Nao existe um agendamento nesse dia e hora! Tente novamente!------\n");

        return 2 * 3 * 5;
    }

    if(dia > 31 || dia < 1){

        printf("<Erro de formato> ------O dia esta no formato errado. Os dias sao contados de 1 ate 31, dependendo do mes.------\n");
        correto = correto * 2;
    }

    else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){

        if(dia == 31){

            printf("<Erro de formato> ------O dia esta no formato errado. O mes %i vai so ate dia 30.------\n",mes);
            correto = correto * 2;

        }
    }

    else if(mes == 2){
        if(dia > 29){

            printf("<Erro de formato> ------O dia esta no formato errado. O mes %i vai so ate dia 29 (em anos bissextos).------\n",mes);
            correto = correto * 2;

        }

    }


    if(ano < 2021 || ano > 2110){

        printf("<Erro de formato> ------O ano esta no formato errado. O ano deve ser maior que 2021 e menor que 2110.------\n");
        correto = correto * 2;

    }

    if(horario_1 > 23 || horario_1 < 0){

        printf("<Erro de formato> ------As horas estao no formato errado. As horas sao contadas de 0 ate 23.------\n");
        correto = correto * 3;
    }
    if(horario_2 < 0 || horario_2 > 59){

        printf("<Erro de formato> ------Os minutos estao no formato errado. Os minutos sao contados de 0 ate 59.------\n");
        correto = correto * 3;
    }

    if(mes > 12 || mes < 1){

        printf("<Erro de formato> ------O mes esta no formato errado. Os meses sao contados de 1 ate 12.------\n");
        correto = correto * 2;

    }



    if(rank > 10 || rank < 0){

        printf("<Erro de formato> ------O rank esta no formato errado. O rank sao contados de 0 ate 10.------\n");
        correto = correto * 5;

    }

    return correto;
}


void adiciona_Arquivo(LISTA* lista){
    AGENDA *end = lista->inicio;
    
    int x;

    while (end->proximo != NULL){
        FILE *f;
        char nome_do_arquivo[100];
        sprintf (nome_do_arquivo, "Agendamentos/agendamento %d/%d/%d %d:%d.txt", end->reg.dia, end->reg.mes, end->reg.ano, end->reg.horario_1, end->reg.horario_2);

        if (f = fopen (nome_do_arquivo, "ab") == NULL){
            printf ("erro na criação/abertura do arquivo!\n");
            system ("pause");
            return;
        }
        /*while(end != NULL && end->reg.dia <= f.dia && end->reg.mes <= f.mes && end->reg.ano <= f.ano && end->reg.horario_1 <= f.horario_1 && end->reg.horario_2 <= f.horario_2){

            f = f->proximo;

        }*/    
        fprintf (f, "%s", end->reg.conteudo);
        fprintf (f, "%s", end->reg.categoria);
        fprintf (f, "%s", end->reg.comentario);
        fprintf (f, "%i", end->reg.horario_1);
        fprintf (f, "%i", end->reg.horario_2);
        fprintf (f, "%i", end->reg.rank);
        fprintf (f, "%i", end->reg.dia);
        fprintf (f, "%i", end->reg.mes);
        fprintf (f, "%i", end->reg.ano);
        end = end->proximo;
        fclose (f);
        //file = file->inicio;
    }

    printf ("agendamentos salvos com sucesso !\n");
    return;

}

void ler_abrir_arquivo(int dia, int mes, int ano, int horario_1, int horario_2){
    FILE *f;
    int i;
    char aux, exibe_arquivo[MAX], nome_do_arquivo[100];
    sprintf (nome_do_arquivo, "Agendamentos/agendamentos %d %d %d %d:%d.txt", dia, mes, ano, horario_1, horario_2);
    if (f = fopen (nome_do_arquivo, "rb") == NULL) {
        printf ("não existe agendamentos ou o arquivo salvo não existe\n");
        system ("pause");
        return;
    } else {
        aux = fgetc (f);
        i = 0;
        while (aux != EOF){
            exibe_arquivo[i] = aux;
            printf ("%c", exibe_arquivo[i]);
            i++;
            aux = fgetc (f);
        }
    }
    fclose (f);
    return;
}

void apaga_arquivo(int dia, int mes, int ano, int horario_1, int horario_2){
    FILE *f;
    char nome_do_arquivo[100];
    sprintf (nome_do_arquivo, "Agendamentos/agendamentos %d/%d/%d %d:%d.txt", dia, mes, ano, horario_1, horario_2);

    if (f = fopen (nome_do_arquivo, "rb") == NULL){
        printf ("não existe arquivo a ser apagado\n");
        system ("pause");
        return;
    } else {
        fclose(f);
        printf ("arquivo de agendamento apagado !\n");
        remove (nome_do_arquivo);
        return;
    }
}

void apaga_pasta (){

}


int main (){

    LISTA* lista = (LISTA*) malloc(sizeof(LISTA));
    lista->inicio = NULL;
    char menu = '6';
    char conteudo[100] = "---";
    char categoria[20] = "---";
    char lixos[20];
    char comentario[100] = "---";
    char res[3] = "aba";
    char lixo;
    int horario_1, horario_2;
    int rank;
    int dia, mes, ano;
    int correto = 0;
    int loop = 0;  
   
    while(1){

        if(loop == 0) printf("*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*\n*Bem-vindo a sua agenda virtual!*\n*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*\n");
        loop = 1;
        printf("\nDigite:\n1 - para adicionar um agendamento na lista.\n2 - para remover um agendamento da lista.\n3 - para mostrar os agendamentos salvos\n4- mostrar os agendamentos que serão adicionados\n5 - para o formato das funcoes.\n6 - para apagar todos os agendamentos salvos.\n0 - para encerrar o programa.\n");
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
                    correto = validaAtributos(lista,dia,mes,ano,horario_1,horario_2,rank,0);
                }

                correto = 0;

                gets(lixos);

                printf("Qual a categoria do agendamento?\n");
                gets(categoria);

                printf("Qual o conteudo do agendamento?\n");
                gets(conteudo);

                printf("Deseja adicionar um comentario?\n");
                gets(res);

                while(strcmp(res,"Sim")!=0  && strcmp(res,"Nao")!=0){
                    printf("<Erro de formato> ------Valor invalido! Digite \"Sim\" para adicionar um comentario ou \"Nao\" para nao adicionar.------\n");
                    gets(res);
                }
                if(strcmp(res,"Sim") == 0){
                    printf("Digite o comentario:\n");
                    gets(comentario);
                }
                
                    adiciona_Agendamento(lista, conteudo, categoria, comentario, horario_1, horario_2, rank, dia, mes, ano);

            printf("\n\nAgendamento adicionado com sucesso!\n\n"); 
        }


        else if(menu == '2'){

            if(lista->inicio != NULL){

                while(correto != 1){

                    if(correto % 2 == 0){
                        printf("Qual a data do agendamento que deseja excluir?\n");
                        scanf("%i %c %i %c %i",&dia,&lixo,&mes,&lixo,&ano);
                    }
                    if(correto % 3 == 0){    
                        printf("Qual o horario do agendamento que deseja excluir?\n");
                        scanf("%i %c %i",&horario_1,&lixo,&horario_2);
                    }
                    correto = validaAtributos(lista, dia, mes, ano, horario_1, horario_2, 0,1);
                }

                correto = 0;
                exclui_Agendamentos(lista, dia, mes, ano, horario_1, horario_2);
                printf("Exclusao realizada com sucesso!\n");
            }

            else printf("Impossivel excluir um elemento com a lista vazia\n");
        }


        else if(menu == '3'){

            printf("Tem certeza que deseja ver os agendamentos salvos? Os agendamentos presentes na lista serão gravados.\n Digite \"Sim\" ou \" Nao\"  \n");
            gets(res);
            while(strcmp(res,"Sim")!=0  && strcmp(res,"Nao")!=0){
                    printf("<Erro de formato> ------Valor invalido! Digite \"Sim\" para mostrar os agendamentos ou \"Nao\" para nao mostrar.------\n");
                    gets(res);
                }
                if(strcmp(res,"Sim") == 0){
                    adiciona_Arquivo(lista);
                    ler_abrir_arquivo(dia, mes, ano, horario_1, horario_2);
                }
                else{
                    printf("Entedido!\n");
                }
        }

        else if(menu == '5'){

            printf("--------------------------------------------------------------------------------------------------------------\nA data deve ser da forma: dia/mes/ano.\nO horario deve ser da forma: horas:minutos.\nO rank e crescente na ordem de 0 ate 10.\nA categoria e uma frase curta que resume do que o agendamento se trata (Exemplos: Familia, Amigos, Festa...).\nO conteudo e o agendamento em si (Exemplos: Entrevista de emprego na empresa X, levar curriculo...).\nPor fim, o comentario vai da sua escolha.\n--------------------------------------------------------------------------------------------------------------\n");
            system("pause");
        }

        
        else if(menu == '0'){

            if(lista->inicio == NULL){}
                  
            else{

                printf("Deseja salvar os agendamentos presentes na fila? Digite \"Sim\" para salvar ou \"Nao\" para nao salvar \n");
                gets(res);
                while(strcmp(res,"Sim")!=0  && strcmp(res,"Nao")!=0){
                    printf("<Erro de formato> ------Valor invalido! Digite \"Sim\" para mostrar os agendamentos ou \"Nao\" para nao mostrar.------\n");
                    gets(res);
                }
                if(strcmp(res,"Sim") == 0){
                    adiciona_Arquivo(lista);
                }
                
            }
            printf("Ate mais!\n");  
            system("pause");
            return 0; 
        }


        else if(menu == '4'){

            mostra_Lista(lista);
            system ("pause");

        }

        else if(menu == '6'){

            printf("Tem certeza que deseja apagar todos os arquivos? Digite \"Sim\" para apagar ou \"Nao\" para nao apagar\n");
            gets(res);
            while(strcmp(res,"Sim")!=0  && strcmp(res,"Nao")!=0){
                printf("<Erro de formato> ------Valor invalido! Digite \"Sim\" para apagar ou \"Nao\" para nao apagar.------\n");
                gets(res);
            }
            if(strcmp(res,"Sim") == 0){
                int dia, mes, ano, horario_1, horario_2;
                sdata:
                printf ("Digite a data e o horário do agendamento que deseje apagar (td na mesma linha, separado por espaços):\n");
                scanf ("%d %d %d %d %d", dia, mes, ano, horario_1, horario_2);
                if (dia < 1 || dia > 31){
                    printf ("Valor/es inválido/s !\n");
                    goto sdata;
                }
                if (mes < 1 || mes > 12){
                    printf ("Valor/es inválido/s !\n");
                    goto sdata;
                }
                if (ano < 2021){
                    printf ("Valor/es Inválidos/s !\n");
                    goto sdata;
                }
                if (horario_1 < 0 || horario_1 > 24){
                    printf ("Valor/es Inválidos/s !\n");
                    goto sdata;
                }
                if (horario_2 < 0 || horario_2 > 59){
                    printf ("Valor/es Inválidos/s !\n");
                    goto sdata;
                }
                apaga_arquivo(dia, mes, ano, horario_1, horario_2);
                printf("Arquivo apagado com sucesso!\n");
            }
            else{
                printf("Arquivo nao apagado\n");
            }
        }



        else{
            printf("Numero invalido\n");
            system ("pause");
        } 

        gets(lixos);
    } 

    return 0;
}
