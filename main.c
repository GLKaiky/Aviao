#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int Listar_Passagens();
int Cadastro_de_Passagens();
void pesquisar();
// Struct de passagens
typedef struct passagens
{
    char codAeroporto_Origem[100];
    char codAeroporto_Destino[100];
    char CidadeOrigem[100];
    char CidadeDestino[100];
    char Data[10];
    char Hora_Partida[100];
    char Hora_Chegada[100];
    double ValorPassagem;
    int ID;

} passagens;
// Fim Struct

// Fun��es Uteis

// Verificar tamanho com retorno

int verificarTam(char str[], int tam)
{
    int A = strlen(str);
    if (A > tam || A < tam)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Deixar letras maiusculas
void LetrasMaiusculas(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = toupper(str[i]);
    }
}

// Tirar \n da String
void TiraN(char str[])
{
    int A = strlen(str);
    str[A - 1] = '\0';
}

// contar linhas do arquivo

int ContaLinha()
{
    FILE *arquivo = fopen("passagens.txt", "r");

    int linhas = 0;

    char caractere;
    while ((caractere = fgetc(arquivo)) != EOF)
    {
        if (caractere == '\n')
        {
            linhas++;
        }
    }

    fclose(arquivo);

    return linhas;
}

// Filtro

int ApenasLetras(char *str)
{
    while (*str)
    {
        if (!isalpha(*str))
        {
            return 0; // Cont�m caracteres que n�o s�o letras
        }
        str++;
    }
    return 1; // Cont�m apenas letras
}

int ApenasNumeros(char *str)

{
    while (*str)
    {
        if (!isdigit(*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}




int main()
{

    FILE* arquivo = fopen("passagens.txt", "r+");
    int linha = ContaLinha()-1;
    if(linha < 0){
        linha = 0;
    }

    printf("%d\n", linha);
    fseek(arquivo, 0, SEEK_SET);
    fprintf(arquivo, "%d\n", linha);

    fclose(arquivo);

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

    switch (opcao)
    {
    case 1:
        Listar_Passagens();
        break;
    case 2:
        pesquisar();
        break;
    case 3:
        Cadastro_de_Passagens();
        break;
    case 4:

        break;
    case 5:

        break;
    case 6:
        puts("Finalizando...");
        exit(0);
        break;
    }
}

int Cadastro_de_Passagens()
{

    char parada[3];

    passagens P;
    FILE *arquivo = fopen("passagens.txt", "a");
    getchar(); // Limpar o buffer

    P.ID = ContaLinha();

    // Codigo de Aeroporto de Origem
    do
    {
        fprintf(arquivo, "%d;", P.ID);
        do
        {
            puts("Digite o Codigo do Areoporto de Origem (apenas letras)");
            fgets(P.codAeroporto_Origem, 100, stdin);
            TiraN(P.codAeroporto_Origem);

            if (ApenasLetras(P.codAeroporto_Origem) == 0)
            {
                printf("Codigo do Aeroporto deve conter apenas letras.\n");
            }

            if (verificarTam(P.codAeroporto_Origem, 3) == 0)
            {
                printf("Digite apenas 3 letras.\n");
            }
        } while (ApenasLetras(P.codAeroporto_Origem) == 0 || verificarTam(P.codAeroporto_Origem, 3) == 0);

        LetrasMaiusculas(P.codAeroporto_Origem);
        fprintf(arquivo, "%s;", P.codAeroporto_Origem);

        // Cod do Aeroporto de Destino

        do
        {

            puts("Digite o Codigo do Aeroporto de Destino (apenas letras)");
            fgets(P.codAeroporto_Destino, 100, stdin);
            TiraN(P.codAeroporto_Destino);

            if (ApenasLetras(P.codAeroporto_Destino) == 0)
            {
                printf("Codigo do Aeroporto deve conter apenas letras.\n");
            }

            if (verificarTam(P.codAeroporto_Destino, 3) == 0)
            {
                printf("Digite apenas 3 letras.\n");
            }

        } while (ApenasLetras(P.codAeroporto_Destino) == 0 || verificarTam(P.codAeroporto_Destino, 3) == 0);

        LetrasMaiusculas(P.codAeroporto_Destino);
        fprintf(arquivo, "%s;", P.codAeroporto_Destino);

        // Cidade de Origem

        do
        {
            puts("Digite a Cidade de Origem (apenas letras)");
            fgets(P.CidadeOrigem, 101, stdin);
            TiraN(P.CidadeOrigem);

            if (ApenasLetras(P.CidadeOrigem) == 0)
            {
                printf("Nome da cidade pode conter apenas letras, sem caracteres ou numeros.\n");
            }
        } while (ApenasLetras(P.CidadeOrigem) == 0);

        LetrasMaiusculas(P.CidadeOrigem);
        fprintf(arquivo, "%s;", P.CidadeOrigem);

        // Cidade de Destino

        do
        {
            puts("Digite a Cidade de Destino (apenas Letras)");
            fgets(P.CidadeDestino, 101, stdin);
            TiraN(P.CidadeDestino);

            if (ApenasLetras(P.CidadeDestino) == 0)
            {
                printf("Nome da cidade pode conter apenas letras, sem caracteres ou numeros.\n");
            }
        } while (ApenasLetras(P.CidadeDestino) == 0);

        LetrasMaiusculas(P.CidadeDestino);
        fprintf(arquivo, "%s;", P.CidadeDestino);

        // Data

        puts("Digite a data, sera registrada no formado dd/mm/YYYY");
        puts("Digite o dia da viagem");

        do
        {
            fgets(P.Data, 10, stdin);
            TiraN(P.Data);
            if (ApenasNumeros(P.Data) == 0)
            {
                puts("Digite apenas numeros");
                puts("Digite o dia da viagem");
            }

            int A = atoi(P.Data);

            if (A > 31 || A < 1)
            {
                puts("Numeros entre 1 e 31");
                puts("Digite o dia da viagem");
            }
        } while (ApenasNumeros(P.Data) == 0 || atoi(P.Data) > 31 || atoi(P.Data) < 1);

        P.Data[2] = '/';

        puts("Digite o mês da viagem (dois digitos): ");
        do
        {
            
            fgets(P.Data + 3, 10, stdin); // Lê dois dígitos para o mês
            TiraN(P.Data + 3);

            if (ApenasNumeros(P.Data + 3) == 0)
            {
                puts("Digite apenas numeros");
                puts("Digite o mes da viagem");
            }

            int mes = atoi(P.Data + 3);
            if (mes > 12 || mes < 1)
            {
                puts("Mês deve estar entre 1 e 12");
                puts("Digite o mes da viagem (dois digitos)");
            }

        } while (ApenasNumeros(P.Data + 3) == 0 || atoi(P.Data + 3) > 12 || atoi(P.Data) < 1);

        P.Data[5] = '/';


        puts("Digite o ano da viagem (quatro dígitos): ");
        do{
            
            fgets(P.Data + 6, 10, stdin);
            TiraN(P.Data + 6);

            if(ApenasNumeros(P.Data + 6) == 0){
                puts("Digite apenas numeros");
                puts("Digte o ano da viagem");
            }

            int ano = atoi(P.Data + 6);
            if(ano > 2050){
                puts("Ano indisponivel ainda");
            }

        }while(ApenasNumeros(P.Data + 6) == 0 || atoi(P.Data + 6) > 2050 || atoi(P.Data + 6) < 1000);

        fprintf(arquivo, "%s;", P.Data);

        // Hora da partida

        puts("Digite a Hora da partida (sera escrito HH:mm)");

        do
        {

            puts("Digite as horas");
            fgets(P.Hora_Partida, 5, stdin);
            TiraN(P.Hora_Partida);

            if (ApenasNumeros(P.Hora_Partida) == 0)
            {
                puts("Digite apenas numeros");
                puts("Digite a Hora da partida");
            }

            int hr = atoi(P.Hora_Partida);
            if (hr > 23 || hr < 0)
            {
                puts("Digite uma hora válida");
                puts("Digite a hora da partida");
            }

        } while (ApenasNumeros(P.Hora_Partida) == 0 || atoi(P.Hora_Partida) > 23 || atoi(P.Hora_Partida) < 0);

        P.Hora_Partida[2] = ':';

        puts("Digite os minutos");
        do
        {

            fgets(P.Hora_Partida + 3, 5, stdin);
            TiraN(P.Hora_Partida + 3);

            if (ApenasNumeros(P.Hora_Partida + 3) == 0)
            {
                puts("Digite apenas numeros");
                puts("Digite os minutos");
            }

            int hr = atoi(P.Hora_Partida + 3);
            if (hr > 59 || hr < 0)
            {
                puts("Digite minutos validos");
                puts("Digite os minutos");
            }
        } while (ApenasNumeros(P.Hora_Partida + 3) == 0 || atoi(P.Hora_Partida + 3) > 59 || atoi(P.Hora_Partida + 3) < 0);

        fprintf(arquivo, "%s;", P.Hora_Partida);

        // Hora da Chegada

        puts("Digite a Hora da Chegada (sera escrito hh:mm)");

        do
        {

            puts("Digite as horas");
            fgets(P.Hora_Chegada, 5, stdin);
            TiraN(P.Hora_Chegada);

            if (ApenasNumeros(P.Hora_Chegada) == 0)
            {
                puts("Digite apenas numeros");
                puts("Digite a Hora da Chegada");
            }

            int hr = atoi(P.Hora_Chegada);
            if (hr > 23 || hr < 0)
            {
                puts("Digite uma hora válida");
                puts("Digite a hora da Chegada");
            }

        } while (ApenasNumeros(P.Hora_Chegada) == 0 || atoi(P.Hora_Chegada) > 23 || atoi(P.Hora_Chegada) < 0);

        P.Hora_Chegada[2] = ':';

        puts("Digite os minutos");
        do
        {

            fgets(P.Hora_Chegada + 3, 5, stdin);
            TiraN(P.Hora_Chegada + 3);

            if (ApenasNumeros(P.Hora_Chegada + 3) == 0)
            {
                puts("Digite apenas numeros");
                puts("Digite os minutos");
            }

            int hr = atoi(P.Hora_Chegada + 3);
            if (hr > 59 || hr < 0)
            {
                puts("Digite minutos validos");
                puts("Digite os minutos");
            }
        } while (ApenasNumeros(P.Hora_Chegada + 3) == 0 || atoi(P.Hora_Chegada + 3) > 59 || atoi(P.Hora_Chegada + 3) < 0);

        fprintf(arquivo, "%s;", P.Hora_Chegada);

        // valor da passagem
        puts("Digite o valor da passagem em R$");

        while (scanf("%lf", &P.ValorPassagem) != 1)
        {
            scanf("%lf", &P.ValorPassagem);
            if (scanf("%lf", &P.ValorPassagem) == 0)
            {
                puts("Digite apenas numeros para o valor");
                puts("Digite o valor da passagem em R$");
            }
        }

        fprintf(arquivo, "R$%.2lf", P.ValorPassagem);
        fprintf(arquivo, "\n");

        getchar();

        puts("Gostaria de registrar mais uma passagem?");
        fgets(parada, 4, stdin);

        LetrasMaiusculas(parada);

        getchar();

    } while (strcmp(parada, "SIM") == 0);
    fclose(arquivo);
    puts("Voltando ao menu");
    main();
}

int Listar_Passagens()
{
    FILE *arquivo = fopen("passagens.txt", "r");

    char linhas[1000];


    puts("--------------------------------------------------------");
    while (fgets(linhas, sizeof(linhas), arquivo) != NULL)
    {
        printf("%s", linhas);
    }
    puts("---------------------------------------------------------");

    fclose(arquivo);
    return main();
}

void pesquisar()
{
    char SN[3];
    int A;
    int linhas = ContaLinha();
    int teste = linhas;

    FILE *arquivo = fopen("passagens.txt", "r");


    passagens P[linhas];
    passagens G;

    for (int i = 0; i < linhas; i++) {
        fscanf(arquivo, " %d; %[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];R$%lf", &P[i].ID,
        P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
        P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
        P[i].Hora_Partida, P[i].Hora_Chegada, &P[i].ValorPassagem);
    }

    fclose(arquivo);

     puts("Por qual maneira você deseja pesquisar?");
     puts("1-Aeroporto de Origem");
     puts("2-Aeroporto de Destino");
     puts("3-Cidade de Origem");
     puts("4-Cidade de Destino");

     scanf("%d", &A);
     switch(A){

        //Pesquisa por aeroporto de origem
        case 1:

        do{
        getchar();
            do
        {
            puts("Digite o Codigo do Areoporto de Origem (apenas letras)");
            fgets(G.codAeroporto_Origem, 100, stdin);
            TiraN(G.codAeroporto_Origem);

            if (ApenasLetras(G.codAeroporto_Origem) == 0)
            {
                printf("Codigo do Aeroporto deve conter apenas letras.\n");
            }

            if (verificarTam(G.codAeroporto_Origem, 3) == 0)
            {
                printf("Digite apenas 3 letras.\n");
            }
        } while (ApenasLetras(G.codAeroporto_Origem) == 0 || verificarTam(G.codAeroporto_Origem, 3) == 0);

        LetrasMaiusculas(G.codAeroporto_Origem);

        for(int i = 0; i<linhas; i++){
            if(strcmp(G.codAeroporto_Origem, P[i].codAeroporto_Origem) == 0){
                printf("Encontrado:\n");
                printf("%d;%s;%s;%s;%s;%s;%s;%s;%.2lf\n",P[i].ID,
                P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
                P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
                P[i].Hora_Partida, P[i].Hora_Chegada, P[i].ValorPassagem);
            }else{
                teste--;
            }
        }

        if(teste == 0){

            do{
            puts("Não encontrado, tentar novamente? Sim ou Nao");
            fgets(SN, 4, stdin);
            LetrasMaiusculas(SN);

            if(strcmp(SN, "NAO") == 0){
                break;
            }

            if(strcmp(SN, "SIM") != 0 && strcmp(SN, "NAO") != 0){
                puts("Apenas sim ou nao");
            }
            
            teste = linhas;

            }while(strcmp(SN, "SIM") != 0 && strcmp(SN, "NAO") != 0);

        }else{

            do{
            puts("Fazer outro teste?");
            fgets(SN, 4, stdin);
            LetrasMaiusculas(SN);
            
            if(strcmp(SN, "NAO") == 0){
                break;
            }
            if(strcmp(SN, "SIM") != 0 && strcmp(SN, "NAO") != 0){
                puts("Apenas sim ou nao");
            }

            }while(strcmp(SN, "SIM") != 0 && strcmp(SN, "NAO") !=0);
        }

        teste = linhas;

        }while(strcmp(SN, "SIM") == 0);

        break;

        case 2:

        //Pesquisa por aeroporto de destino

        do{
            getchar();
        do
        {
            puts("Digite o Codigo do Aeroporto de Destino (apenas letras)");
            fgets(G.codAeroporto_Destino, 100, stdin);
            TiraN(G.codAeroporto_Destino);

            if (ApenasLetras(G.codAeroporto_Destino) == 0)
            {
                printf("Codigo do Aeroporto deve conter apenas letras.\n");
            }

            if (verificarTam(G.codAeroporto_Destino, 3) == 0)
            {
                printf("Digite apenas 3 letras.\n");
            }

        } while (ApenasLetras(G.codAeroporto_Destino) == 0 || verificarTam(G.codAeroporto_Destino, 3) == 0);

        LetrasMaiusculas(G.codAeroporto_Destino);
        fprintf(arquivo, "%s;", G.codAeroporto_Destino);

        teste = linhas;

        for(int i = 0; i<linhas; i++){
            if(strcmp(G.codAeroporto_Destino, P[i].codAeroporto_Destino) == 0){
                printf("Encontrado:\n");
                printf("%d;%s;%s;%s;%s;%s;%s;%s;%.2lf\n",P[i].ID,
                P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
                P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
                P[i].Hora_Partida, P[i].Hora_Chegada, P[i].ValorPassagem);
            }else{
                teste--;
            }
        }

       if(teste == 0){

            do{
            puts("Não encontrado, tentar novamente? Sim ou Nao");
            fgets(SN, 4, stdin);
            LetrasMaiusculas(SN);

            if(strcmp(SN, "NAO") == 0){
                break;
            }

            if(strcmp(SN, "SIM") != 0 && strcmp(SN, "NAO") != 0){
                puts("Apenas sim ou nao");
            }
            
            teste = linhas;

            }while(strcmp(SN, "SIM") != 0 && strcmp(SN, "NAO") != 0);

        }else{

            do{
            puts("Fazer outro teste?");
            fgets(SN, 4, stdin);
            LetrasMaiusculas(SN);
            
            if(strcmp(SN, "NAO") == 0){
                break;
            }
            if(strcmp(SN, "SIM") != 0 && strcmp(SN, "NAO") != 0){
                puts("Apenas sim ou nao");
            }

            }while(strcmp(SN, "SIM") != 0 && strcmp(SN, "NAO") !=0);
        }

        teste = linhas;

        }while(strcmp(SN, "SIM") == 0);

        break;

        //Pesquisa por cidade de origem

        case 3:
            do{
            getchar();
            do
            {
                puts("Digite a Cidade de Origem (apenas letras)");
                fgets(G.CidadeOrigem, 101, stdin);
                TiraN(G.CidadeOrigem);

                if (ApenasLetras(G.CidadeOrigem) == 0)
                {
                    printf("Nome da cidade pode conter apenas letras, sem caracteres ou numeros.\n");
                }
            } while (ApenasLetras(G.CidadeOrigem) == 0);

            LetrasMaiusculas(G.CidadeOrigem);
            fprintf(arquivo, "%s;", G.CidadeOrigem);

        teste = linhas;

        for(int i = 0; i<linhas; i++){
            if(strcmp(G.CidadeOrigem, P[i].CidadeOrigem) == 0){
                printf("Encontrado:\n");
                printf("%d;%s;%s;%s;%s;%s;%s;%s;%.2lf\n",P[i].ID,
                P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
                P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
                P[i].Hora_Partida, P[i].Hora_Chegada, P[i].ValorPassagem);
            }else{
                teste--;
            }
        }

       if(teste == 0){

            do{
            puts("Não encontrado, tentar novamente? Sim ou Nao");
            fgets(SN, 4, stdin);
            LetrasMaiusculas(SN);

            if(strcmp(SN, "NAO") == 0){
                break;
            }

            if(strcmp(SN, "SIM") != 0 && strcmp(SN, "NAO") != 0){
                puts("Apenas sim ou nao");
            }
            
            teste = linhas;

            }while(strcmp(SN, "SIM") != 0 && strcmp(SN, "NAO") != 0);

        }else{

            do{
            puts("Fazer outro teste?");
            fgets(SN, 4, stdin);
            LetrasMaiusculas(SN);
            
            if(strcmp(SN, "NAO") == 0){
                break;
            }
            if(strcmp(SN, "SIM") != 0 && strcmp(SN, "NAO") != 0){
                puts("Apenas sim ou nao");
            }

            }while(strcmp(SN, "SIM") != 0 && strcmp(SN, "NAO") !=0);
        }

        teste = linhas;

        }while(strcmp(SN, "SIM") == 0);

        break;

        //Pesquisa por cidade de destino

        case 4:
            do{
            getchar();
            do
            {
                puts("Digite a Cidade de Destino (apenas letras)");
                fgets(G.CidadeDestino, 101, stdin);
                TiraN(G.CidadeDestino);

                if (ApenasLetras(G.CidadeDestino) == 0)
                {
                    printf("Nome da cidade pode conter apenas letras, sem caracteres ou numeros.\n");
                }
            } while (ApenasLetras(G.CidadeDestino) == 0);

            LetrasMaiusculas(G.CidadeDestino);
            fprintf(arquivo, "%s;", G.CidadeDestino);

        teste = linhas;

        for(int i = 0; i<linhas; i++){
            if(strcmp(G.CidadeDestino, P[i].CidadeDestino) == 0){
                printf("Encontrado:\n");
                printf("%d;%s;%s;%s;%s;%s;%s;%s;%.2lf\n",P[i].ID,
                P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
                P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
                P[i].Hora_Partida, P[i].Hora_Chegada, P[i].ValorPassagem);
            }else{
                teste--;
            }
        }

       if(teste == 0){
            
            do{
            puts("Não encontrado, tentar novamente? Sim ou Nao");   
            fgets(SN, 4, stdin);
            LetrasMaiusculas(SN);

            if(strcmp(SN, "NAO") == 0){
                break;
            }

            if(strcmp(SN, "SIM") != 0 && strcmp(SN, "NAO") != 0){
                puts("Apenas sim ou nao");
            }
            
            teste = linhas;

            }while(strcmp(SN, "SIM") != 0 && strcmp(SN, "NAO") != 0);

        }else{

            do{
            puts("Fazer outro teste?");
            fgets(SN, 4, stdin);
            LetrasMaiusculas(SN);
            
            if(strcmp(SN, "NAO") == 0){
                break;
            }
            
            if(strcmp(SN, "SIM") != 0 && strcmp(SN, "NAO") != 0){
                puts("Apenas sim ou nao");
            }

            }while(strcmp(SN, "SIM") != 0 && strcmp(SN, "NAO") !=0);
        }

        teste = linhas;

        }while(strcmp(SN, "SIM") == 0);

        break;

     }
     puts("\nVoltando para o menu\n");
     main();
}
