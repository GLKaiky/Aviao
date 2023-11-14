#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int Cadastro_de_Passagens();

//Struct de passagens
typedef struct passagens{
    char codAeroporto_Origem[3];
    char codAeroporto_Destino[3];
    char CidadeOrigem[100];
    char CidadeDestino[100];
    char Data[10];
    char Hora_Partida[5];
    char Hora_Chegada[5];
    double ValorPassagem;
} passagens;
//Fim Struct

//Funções Uteis

//Deixar letras maiusculas
void LetrasMaiusculas(char str[]){
    for(int i = 0; i<strlen(str); i++){
        str[i] = toupper(str[i]);
    }
}

//Tirar \n da String
void TiraN(char str[]){
    int A = strlen(str);
    str[A] = '\0';
}

//Filtro

int ApenasLetras(char *str) {
    while (*str) {
        if (!isalpha(*str)) {
            return 0;  // Contém caracteres que não são letras
        }
        str++;
    }
    return 1;  // Contém apenas letras
}


int main()
{
    int opcao;

    printf("Cadastro de Passagens, bem vindo\n");
    puts("Selecione uma opcao para prosseguir:");

    printf("1-Listar todas as passagens\n");
    printf("2-Pesquisar por uma passagem\n");
    printf("3-Cadastrar uma passagem\n");
    printf("4-Editar uma passagem\n");
    printf("5-Excluir uma passagem\n");
    puts("6-Sair do programa\n");

    scanf("%d", &opcao);

    switch(opcao){
    case 1:
        Cadastro_de_Passagens();
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    }
}

int Cadastro_de_Passagens(){
    passagens P;
    FILE* arquivo = fopen("passagens.txt", "a");
    getchar();//Limpar o buffer

    do{
    puts("Digite o Codigo do Areoporto de Origem (apenas letras)");
    fgets(P.codAeroporto_Origem,4,stdin);

    if (ApenasLetras(P.codAeroporto_Origem) == 0){
        printf("Codigo do Aeroporto deve conter apenas letras.\n");
        getchar();
    }

    }while(ApenasLetras(P.codAeroporto_Origem) == 0);

    LetrasMaiusculas(P.codAeroporto_Origem);
    TiraN(P.codAeroporto_Origem);

    fprintf(arquivo, "%s;", P.codAeroporto_Origem);

    getchar();

    do{

    puts("Digite o Codigo do Aeroporto de Destino (apenas letras)");
    fgets(P.codAeroporto_Destino, 4, stdin);

    if(ApenasLetras(P.codAeroporto_Destino) == 0){
        printf("Codigo do Aeroporto deve conter apenas letras.\n");
        getchar();
    }

    }while(ApenasLetras(P.codAeroporto_Destino) == 0);

    LetrasMaiusculas(P.codAeroporto_Destino);
    TiraN(P.codAeroporto_Destino);

    fprintf(arquivo,"%s", P.codAeroporto_Destino);

}
