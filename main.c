//Bibliotecas inclusas e utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "wallison.h"

//Menção das Funções
int Listar_Passagens();
int Cadastro_de_Passagens();
void pesquisar();
void Editar();
void Excluir();


//Função do tipo passagens responsavel por preencher a struct e editar o arquivo
passagens Cad_Mod(int ID)
{
    getchar();//Limpar o buffer
    passagens P;//Chamar struct

    P.ID = ID;//Receber o parametro ID passado na função de edição

    //Registro do codigo de aeroporto
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
    }
    while (ApenasLetras(P.codAeroporto_Origem) == 0 || verificarTam(P.codAeroporto_Origem, 3) == 0);//Condições

    LetrasMaiusculas(P.codAeroporto_Origem);

    // Registro do Codigo do Aeroporto de Destino

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

    }
    while (ApenasLetras(P.codAeroporto_Destino) == 0 || verificarTam(P.codAeroporto_Destino, 3) == 0);//Condições

    LetrasMaiusculas(P.codAeroporto_Destino);

    //Cadastro da Cidade de Origem

    do
    {
        puts("Digite a Cidade de Origem (apenas letras)");
        fgets(P.CidadeOrigem, 101, stdin);
        TiraN(P.CidadeOrigem);

        if (ApenasLetras(P.CidadeOrigem) == 0)
        {
            printf("Nome da cidade pode conter apenas letras, sem caracteres ou numeros.\n");
        }
    }
    while (ApenasLetras(P.CidadeOrigem) == 0);//Condições

    LetrasMaiusculas(P.CidadeOrigem);

    //Cadastro da Cidade de Destino

    do
    {
        puts("Digite a Cidade de Destino (apenas Letras)");
        fgets(P.CidadeDestino, 101, stdin);
        TiraN(P.CidadeDestino);

        if (ApenasLetras(P.CidadeDestino) == 0)
        {
            printf("Nome da cidade pode conter apenas letras, sem caracteres ou numeros.\n");
        }
    }
    while (ApenasLetras(P.CidadeDestino) == 0);//Condições

    LetrasMaiusculas(P.CidadeDestino);

    //Cadastro da Data

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

        int A = atoi(P.Data);//Converte strings em numeros inteiros

        if (A > 31 || A < 1)//Verifica se o dia está entre 1 e 31
        {
            puts("Numeros entre 1 e 31");
            puts("Digite o dia da viagem");
        }

        if(strlen(P.Data)==1)
        {
            sprintf(P.Data, "%02d", atoi(P.Data));//Formatação para caso seja digitado apenas um digito como 1,2,3...seja adicionado um 0 para ficar 01,02,03
        }
    }
    while (ApenasNumeros(P.Data) == 0 || atoi(P.Data) > 31 || atoi(P.Data) < 1);//Condições

    P.Data[2] = '/';//Adiciona uma barra na segunda posição da string de Data para formatação

    puts("Digite o mês da viagem (dois digitos): ");
    do
    {

        fgets(P.Data + 3, 10, stdin); // Lê dois dígitos para o mês
        TiraN(P.Data + 3); // +3 para avançar no array da string

        if (ApenasNumeros(P.Data + 3) == 0)//Filtro para ter apenas numeros
        {
            puts("Digite apenas numeros");
            puts("Digite o mes da viagem");
        }

        int mes = atoi(P.Data + 3);
        if (mes > 12 || mes < 1)//Limita o mes entre 1 e 12
        {
            puts("Mês deve estar entre 1 e 12");
            puts("Digite o mes da viagem (dois digitos)");
        }

        if(strlen(P.Data+3) == 1)
        {
            sprintf(P.Data + 3, "%02d", atoi(P.Data + 3));//Formatação para caso seja digitado apenas um digito como 1,2,3...seja adicionado um 0 para ficar 01,02,03
        }

    }
    while (ApenasNumeros(P.Data + 3) == 0 || atoi(P.Data + 3) > 12 || atoi(P.Data) < 1);//Condições

    P.Data[5] = '/';//Barra para proxima data

    puts("Digite o ano da viagem (quatro dígitos): ");
    do
    {

        fgets(P.Data + 6, 10, stdin);
        TiraN(P.Data + 6);

        if (ApenasNumeros(P.Data + 6) == 0)
        {
            puts("Digite apenas numeros");
            puts("Digte o ano da viagem");
        }

        int ano = atoi(P.Data + 6);
        if (ano > 2050)//Verificar se o ano é valido
        {
            puts("Ano indisponivel ainda");
        }else if(ano < 1000){
            puts("4 Digitos");
        }

    }
    while (ApenasNumeros(P.Data + 6) == 0 || atoi(P.Data + 6) > 2050 || atoi(P.Data + 6) < 1000);//Condições

    //Registro Hora da partida

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

        int hr = atoi(P.Hora_Partida);//Transformar string em numero inteiro
        if (hr > 23 || hr < 0)
        {
            puts("Digite uma hora válida");
            puts("Digite a hora da partida");
        }

        if (strlen(P.Hora_Partida) == 1)
        {
            sprintf(P.Hora_Partida, "%02d", atoi(P.Hora_Partida));//Formatação para caso seja digitado apenas um digito como 1,2,3...seja adicionado um 0 para ficar 01,02,03
        }

    }
    while (ApenasNumeros(P.Hora_Partida) == 0 || atoi(P.Hora_Partida) > 23 || atoi(P.Hora_Partida) < 0 );//Condições

    P.Hora_Partida[2] = ':';//Adiciona 2 pontos após as horas digitadas

    puts("Digite os minutos");
    do
    {

        fgets(P.Hora_Partida + 3, 5, stdin);//Avança e lê o array na posição vazia
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

        if (strlen(P.Hora_Partida + 3) == 1)
        {
            sprintf(P.Hora_Partida + 3, "%02d", atoi(P.Hora_Partida + 3));//Formatação para caso seja digitado apenas um digito como 1,2,3...seja adicionado um 0 para ficar 01,02,03
        }
    }
    while (ApenasNumeros(P.Hora_Partida + 3) == 0 || atoi(P.Hora_Partida + 3) > 59 || atoi(P.Hora_Partida + 3) < 0);//Condições

    //Registro Hora da Chegada

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
        if (hr > 23 || hr < 0)//Limita a horas digitadas entre 00 e 23 no padrão 24 horas
        {
            puts("Digite uma hora válida");
            puts("Digite a hora da Chegada");
        }

        if (strlen(P.Hora_Chegada) == 1)
        {
            sprintf(P.Hora_Chegada, "%02d", atoi(P.Hora_Chegada));//Formatação para caso seja digitado apenas um digito como 1,2,3...seja adicionado um 0 para ficar 01,02,03
        }

    }
    while (ApenasNumeros(P.Hora_Chegada) == 0 || atoi(P.Hora_Chegada) > 23 || atoi(P.Hora_Chegada) < 0);//Condições

    P.Hora_Chegada[2] = ':';//Dois pontos apos o registro das horas

    puts("Digite os minutos");
    do
    {

        fgets(P.Hora_Chegada + 3, 5, stdin);//Avança para a posição disponivel do array
        TiraN(P.Hora_Chegada + 3);

        if (ApenasNumeros(P.Hora_Chegada + 3) == 0)
        {
            puts("Digite apenas numeros");
            puts("Digite os minutos");
        }

        int hr = atoi(P.Hora_Chegada + 3);
        if (hr > 59 || hr < 0)//Limita minutos a 0 e 59 minutos
        {
            puts("Digite minutos validos");
            puts("Digite os minutos");
        }

        if (strlen(P.Hora_Chegada + 3) == 1)
        {
            sprintf(P.Hora_Chegada + 3, "%02d", atoi(P.Hora_Chegada + 3));
        }

    }
    while (ApenasNumeros(P.Hora_Chegada + 3) == 0 || atoi(P.Hora_Chegada + 3) > 59 || atoi(P.Hora_Chegada + 3) < 0);

    //Registro valor da passagem
    puts("Digite o valor da passagem em R$");

    while (scanf("%lf", &P.ValorPassagem) != 1)//Limitador para que seja digitados apenas numeros
    {
        printf("Digite apenas números para o valor.\n");
        printf("Digite o valor da passagem em R$: ");
        while (getchar() != '\n'); // Limpa o buffer de entrada
    }

    return P;//Retorna a struct foramtada para a função Editar
}

int main()
{

    FILE *arquivo = fopen("passagens.txt", "r+");//Abre o arquivo para leitura e escrita
    int linha = ContaLinha() - 2;//Recebe as linhas contadas para a quantidade de passagens registradas desprezando as 2 primeiras linhas
    if (linha < 0)
    {
        linha = 0;//Caso nao tenha registros linha será impressa com 0
    }

    printf("%d\n", linha);//Imprime no topo do programa
    fseek(arquivo, 0, SEEK_SET);//Move o ponteiro do arquivo para a primeira linha
    fprintf(arquivo, "%d\n", linha);//Imprime a quantidade de passagens
    fclose(arquivo);//Fecha o arquivo

    arquivo = fopen("passagens.txt", "r+");//Abre novamente para o registro do ID
    int A = UltimoID();
    fseek(arquivo, 3, SEEK_SET);//Move o ponteiro do arquivo para a segunda linha
    fprintf(arquivo, "%d\n", A);//Imprime o id
    fclose(arquivo);//Fechar o arquivo

    char opcao[100];//String de opção grande para tratamento de erros de digitação

    printf("Cadastro de Passagens, bem vindo\n");
    puts("Selecione uma opcao para prosseguir:");

    printf("1-Listar todas as passagens\n");
    printf("2-Pesquisar por uma passagem\n");
    printf("3-Cadastrar uma passagem\n");
    printf("4-Editar uma passagem\n");
    printf("5-Excluir uma passagem\n");
    puts("6-Sair do programa\n");

    do
    {
        fgets(opcao, sizeof(opcao), stdin);
        TiraN(opcao);

        if (atoi(opcao) < 1 || atoi(opcao) > 6 || ApenasNumeros(opcao) == 0)//Atoi transforma Strings em Numeros
        {
            puts("Apenas as opcoes de 1 a 6");
            puts("Digite novamente:");
        }

    }
    while (atoi(opcao) < 1 || atoi(opcao) > 6 || ApenasNumeros(opcao) == 0);//Condições para ser digitado apenas numeros entre 1 e 6

    int opcao1 = atoi(opcao);// Opção 1 recebe um inteiro da string opcao

    switch (opcao1)//Menu de opções
    {
    case 1:
        Listar_Passagens();//Listagem de passagens
        break;
    case 2:
        pesquisar();//Pesquisa de passagens
        break;
    case 3:
        Cadastro_de_Passagens();//Cadastro de passagens
        break;
    case 4:
        Editar();//Edicao de passagens
        break;
    case 5:
        Excluir();//Excluir passagens
        break;
    case 6:
        puts("Finalizando...");
        exit(0);//Sair do programa
        break;
    }
}

int Cadastro_de_Passagens()//Cadastro de passagens
{

    char parada[3];//Condição de parada para repetição da função no final

    passagens P;//Chamada da struct
    FILE *arquivo = fopen("passagens.txt", "a");//Abertura do arquivo para escrita sem apagar o que foi escrito

    P.ID = ContaLinha() - 1;//Id contado a partir da subtração de 1 linha para sempre contar linearmente 1,2,3,4,5...

    int Y = UltimoID();//Condição para evitar erros com o ultimo ID e o ID ser ignorado

    do
    {
        if (P.ID <= Y)
        {
            P.ID++;
        }
    }
    while (P.ID <= Y);

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
        }
        while (ApenasLetras(P.codAeroporto_Origem) == 0 || verificarTam(P.codAeroporto_Origem, 3) == 0);

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

        }
        while (ApenasLetras(P.codAeroporto_Destino) == 0 || verificarTam(P.codAeroporto_Destino, 3) == 0);

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
        }
        while (ApenasLetras(P.CidadeOrigem) == 0);

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
        }
        while (ApenasLetras(P.CidadeDestino) == 0);

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

            if(strlen(P.Data)==1)
            {
                sprintf(P.Data, "%02d", atoi(P.Data));
            }
        }
        while (ApenasNumeros(P.Data) == 0 || atoi(P.Data) > 31 || atoi(P.Data) < 1);

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

            if(strlen(P.Data+3) == 1)
            {
                sprintf(P.Data + 3, "%02d", atoi(P.Data + 3));
            }

        }
        while (ApenasNumeros(P.Data + 3) == 0 || atoi(P.Data + 3) > 12 || atoi(P.Data) < 1);

        P.Data[5] = '/';

        puts("Digite o ano da viagem (quatro dígitos): ");
        do
        {

            fgets(P.Data + 6, 10, stdin);
            TiraN(P.Data + 6);

            if (ApenasNumeros(P.Data + 6) == 0)
            {
                puts("Digite apenas numeros");
                puts("Digte o ano da viagem");
            }

            int ano = atoi(P.Data + 6);
            if (ano > 2050)
            {
                puts("Ano indisponivel ainda");
            }

        }
        while (ApenasNumeros(P.Data + 6) == 0 || atoi(P.Data + 6) > 2050 || atoi(P.Data + 6) < 1000);

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

            if (strlen(P.Hora_Partida) == 1)
            {
                sprintf(P.Hora_Partida, "%02d", atoi(P.Hora_Partida));
            }

        }
        while (ApenasNumeros(P.Hora_Partida) == 0 || atoi(P.Hora_Partida) > 23 || atoi(P.Hora_Partida) < 0 );

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

            if (strlen(P.Hora_Partida + 3) == 1)
            {
                sprintf(P.Hora_Partida + 3, "%02d", atoi(P.Hora_Partida + 3));
            }
        }
        while (ApenasNumeros(P.Hora_Partida + 3) == 0 || atoi(P.Hora_Partida + 3) > 59 || atoi(P.Hora_Partida + 3) < 0);

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

            if (strlen(P.Hora_Chegada) == 1)
            {
                sprintf(P.Hora_Chegada, "%02d", atoi(P.Hora_Chegada));
            }

        }
        while (ApenasNumeros(P.Hora_Chegada) == 0 || atoi(P.Hora_Chegada) > 23 || atoi(P.Hora_Chegada) < 0);

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

            if (strlen(P.Hora_Chegada + 3) == 1)
            {
                sprintf(P.Hora_Chegada + 3, "%02d", atoi(P.Hora_Chegada + 3));
            }

        }
        while (ApenasNumeros(P.Hora_Chegada + 3) == 0 || atoi(P.Hora_Chegada + 3) > 59 || atoi(P.Hora_Chegada + 3) < 0);

        fprintf(arquivo, "%s;", P.Hora_Chegada);

        // valor da passagem
        puts("Digite o valor da passagem em R$");

        while (scanf("%lf", &P.ValorPassagem) != 1)
        {
            printf("Digite apenas números para o valor.\n");
            printf("Digite o valor da passagem em R$: ");
            while (getchar() != '\n'); // Limpa o buffer de entrada
        }
        fprintf(arquivo, "R$%.2lf", P.ValorPassagem);
        fprintf(arquivo, "\n");

        puts("Cadastrada com sucesso!");
        getchar();

        puts("Gostaria de registrar mais uma passagem?");
        fgets(parada, 4, stdin);

        LetrasMaiusculas(parada);

        getchar();
        P.ID++;
    }
    while (strcmp(parada, "SIM") == 0);
    fclose(arquivo);

    puts("Voltando ao menu");
    main();
}



int Listar_Passagens()
{
    FILE *arquivo = fopen("passagens.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return main();
    }

    char linhas[1000];
    int linhaAtual = 0;

    puts("---------------------------------------------------------");
    while (fgets(linhas, sizeof(linhas), arquivo) != NULL)
    {
        if (linhaAtual != 1)
        {
            // Ignora a segunda linha (linhaAtual == 1)
            printf("%s", linhas);
        }
        linhaAtual++;
    }
    puts("---------------------------------------------------------");

    fclose(arquivo);
    return main();
}

void Excluir()
{
    FILE *arquivo = fopen("passagens.txt", "r");//Abertura do arquivo para leitura

    int quantidadeLinhas = 0;
    int ultimoID = 0;
    fscanf(arquivo, "%d", &quantidadeLinhas); // Lendo o primeiro numero do arquivo
    fscanf(arquivo, "%d", &ultimoID);         // Lê o ID da última passagem

    if (quantidadeLinhas <= 0 || ultimoID <= 0)//Verificar se o arquivo esta preenchido
    {
        printf("Arquivo vazio ou mal formatado.\n");
        fclose(arquivo);
        main();
        printf("\n");
    }

    passagens P[quantidadeLinhas];//Chamada da struct
    int indice = 0;

    while (fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];R$%lf\n", &P[indice].ID,
                  P[indice].codAeroporto_Origem, P[indice].codAeroporto_Destino,
                  P[indice].CidadeOrigem, P[indice].CidadeDestino, P[indice].Data,
                  P[indice].Hora_Partida, P[indice].Hora_Chegada, &P[indice].ValorPassagem) == 9)
    {
        indice++;
    }//Registro dos elementos do arquivo na struct respectivamente

    fclose(arquivo);//Fechar o arquivo

    int idExcluir;//Variavel para listar o ID de exclusão

    Listar_Passagens2();//Listar as passagens disponiveis

    int verificador = 0;//Verificador para ver a existencia da passagem
    do
    {
        printf("Digite o ID da passagem que deseja excluir: ");
        scanf("%d", &idExcluir);//Registra o id que deseja excluir

        for (int i = 0; i < quantidadeLinhas; i++)//Procurar pelo id para mostrar qual foi encontrado
        {
            if (P[i].ID == idExcluir)
            {
                puts("Encontrado");
                verificador = 1;//modifica verificador
                printf("%d;%s;%s;%s;%s;%s;%s;%s;R$%.2lf\n", P[i].ID,
                       P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
                       P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
                       P[i].Hora_Partida, P[i].Hora_Chegada, P[i].ValorPassagem);
            }
        }
        if (verificador == 0)//Caso verificador continue 0 nao foi encontrado
        {
            puts("Não encontrado, tente novamente");
        }

    }
    while (verificador == 0);

    char SN[4];//Variavel para sim ou nao
    getchar();//Limapar o buffer
    do
    {

        puts("Deseja excluir esta passagem? Sim ou Nao");//Condição para autorizar exclusão
        fgets(SN, 100, stdin);//Fgets de 100 para tratamento de erro de digitação
        LetrasMaiusculas(SN);
        TiraN(SN);

        if (strcmp(SN, "NAO") == 0)//Caso seja não, retorna a main
        {
            main();
        }

        if (strcmp(SN, "SIM") != 0)//Caso digite algo diferente de sim pedira para ser digitado apenas sim ou nao
        {
            puts("Apenas Sim ou Nao");
        }
    }
    while (strcmp(SN, "SIM") != 0);//condição

    FILE *arquivoEscrita = fopen("passagens.txt", "w");//Abre o arquivo apagando tudo o que foi registrado la dentro

    fprintf(arquivoEscrita, "%d\n", quantidadeLinhas - 1); // Escreve a nova quantidade de linhas
    fprintf(arquivoEscrita, "%d\n", ultimoID);//Escreve o ultimo ID

    for (int i = 0; i < indice; i++)//Reescrita do arquivo
    {
        if (P[i].ID != idExcluir)//Caso a struct nao tenha o ID que deseja ser excluido, será impresso normalmente no arquivo
        {
            fprintf(arquivoEscrita, "%d;%s;%s;%s;%s;%s;%s;%s;R$%.2lf\n", P[i].ID,
                    P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
                    P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
                    P[i].Hora_Partida, P[i].Hora_Chegada, P[i].ValorPassagem);
        }
        else//Se nao ele sera ignorado pela leitura e prosseguirá sem ele
        {
            puts("Excluindo...");
            printf("%d;%s;%s;%s;%s;%s;%s;%s;R$%.2lf\n", P[i].ID,
                   P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
                   P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
                   P[i].Hora_Partida, P[i].Hora_Chegada, P[i].ValorPassagem);
        }
    }

    fclose(arquivoEscrita);//Fecha o arquivo
    puts("Retornando ao menu");//Retorna ao menu
    main();
}

void Editar()
{

    FILE *arquivo = fopen("passagens.txt", "r");//Abertura do arquivo para leitura dele

    int quantidadeLinhas = 0;
    int ultimoID = 0;
    fscanf(arquivo, "%d", &quantidadeLinhas); // Lendo o primeiro numero do arquivo
    fscanf(arquivo, "%d", &ultimoID);         // Lê o ID da última passagem

    if (quantidadeLinhas <= 0 || ultimoID <= 0)//Verifica se tem algo dentro do arquivo
    {
        printf("Arquivo vazio ou mal formatado.\n");
        fclose(arquivo);
        main();
        printf("\n");
    }

    passagens P[quantidadeLinhas];//Criação do array de struct

    int indice = 0;

    while (fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];R$%lf\n", &P[indice].ID,
                  P[indice].codAeroporto_Origem, P[indice].codAeroporto_Destino,
                  P[indice].CidadeOrigem, P[indice].CidadeDestino, P[indice].Data,
                  P[indice].Hora_Partida, P[indice].Hora_Chegada, &P[indice].ValorPassagem) == 9)
    {
        indice++;
    }//Registro da struct

    fclose(arquivo);

    int idEditar;//Variavel para achar o ID para edição

    Listar_Passagens2();//Listagem das passagens modificado

    int verificador = 0;
    do
    {
        printf("Digite o ID da passagem que deseja editar: ");
        scanf("%d", &idEditar);//Scan do ID

        for (int i = 0; i < quantidadeLinhas; i++)
        {
            if (P[i].ID == idEditar)
            {
                puts("Encontrado");
                verificador = 1;
            }//Verificar se ele foi encontrado
        }

        if (verificador == 0)//Caso verificador nao for modificado, nao foi encontrado
        {
            puts("Nao encontrado, tente novamente");
        }
    }
    while (verificador == 0);

    FILE *arquivoEscrita = fopen("passagens.txt", "w");//Abre o arquivo apagando tudo dentro dele

    fprintf(arquivoEscrita, "%d\n", quantidadeLinhas);//Escreve a quanditdade de linhas
    fprintf(arquivoEscrita, "%d\n", ultimoID);//Escreve o ultimo ID registrado

    for (int i = 0; i < indice; i++)
    {
        if (P[i].ID != idEditar)//Caso seja diferente do ID escolhido ele escreve no arquivo a struct normalmente
        {
            fprintf(arquivoEscrita, "%d;%s;%s;%s;%s;%s;%s;%s;R$%.2lf\n", P[i].ID,
                    P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
                    P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
                    P[i].Hora_Partida, P[i].Hora_Chegada, P[i].ValorPassagem);
        }
        else if (P[i].ID == idEditar)//Se não ele ira imprimir a passagem encontrada e irá chamar o CAD_Mod com parametro do ID escolhido para registrar uma passagem atualizada e aí sim imprimir ela no arquivo
        {
            printf("%d;%s;%s;%s;%s;%s;%s;%s;R$%.2lf\n", P[i].ID,
                   P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
                   P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
                   P[i].Hora_Partida, P[i].Hora_Chegada, P[i].ValorPassagem);

            passagens G = Cad_Mod(idEditar);

            fprintf(arquivoEscrita, "%d;%s;%s;%s;%s;%s;%s;%s;R$%.2lf\n", G.ID,
                    G.codAeroporto_Origem, G.codAeroporto_Destino,
                    G.CidadeOrigem, G.CidadeDestino, G.Data,
                    G.Hora_Partida, G.Hora_Chegada, G.ValorPassagem);
        }
    }

    fclose(arquivoEscrita);//Fechamento do arquivo
    puts("Editado com sucesso!");
    puts("Retornando ao menu");//Retorna ao menu
    getchar();
    main();
}

void pesquisar()//Função de pesquisa
{
    if (UltimoID() == 0)//Verificar se o arquivo está preenchido
    {
        puts("Arquivo vazio, favor preencher...Voltando ao menu");
        main();
    }

    char SN[3];//Condição para continuidade da função SIM ou NAO
    int A;
    int linhas = ContaLinha() - 1;
    int teste = linhas;

    FILE *arquivo = fopen("passagens.txt", "r");//Abertura do arquivo para leitura

    int quantidadedelinhas;
    int UltimoID;
    fscanf(arquivo, "%d", &quantidadedelinhas);//Scanea a primeira linha do arquivo
    fscanf(arquivo, "%d", &UltimoID);//Scanea a segunda linha
    passagens P[linhas];//Array da struct
    passagens G;//Chamada da struct sem array

    for (int i = 0; i < linhas; i++)
    {
        fscanf(arquivo, " %d; %[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];R$%lf", &P[i].ID,
               P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
               P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
               P[i].Hora_Partida, P[i].Hora_Chegada, &P[i].ValorPassagem);
    }//Scanear o arquivo com o array de struct

    fclose(arquivo);//Fecha o arquivo

    puts("Por qual maneira voce deseja pesquisar?");
    puts("1-ID da passagem");
    puts("2-Aeroporto de Origem");
    puts("3-Aeroporto de Destino");
    puts("4-Cidade de Origem");
    puts("5-Cidade de Destino");

    scanf("%d", &A);
    switch (A)
    {

        int verificar;

    // Pesquisa por ID
    case 1:

        do
        {
            puts("Digite o ID da passagem que deseja pesquisar");
            scanf("%d", &G.ID);
            verificar = 0;

            for (int i = 0; i < linhas; i++)
            {
                if (P[i].ID == G.ID)
                {
                    printf("Encontrado:\n");
                    printf("%d;%s;%s;%s;%s;%s;%s;%s;%.2lf\n", P[i].ID,
                           P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
                           P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
                           P[i].Hora_Partida, P[i].Hora_Chegada, P[i].ValorPassagem);
                    verificar = 1;
                }
            }
            if (verificar == 0)
            {

                getchar();

                do
                {
                    puts("Nao encontrado, tentar novamente? Sim ou Nao");
                    fgets(SN, 100, stdin);
                    LetrasMaiusculas(SN);
                    TiraN(SN);

                    if (strcmp(SN, "NAO") == 0)
                    {
                        break;
                    }

                    if (strcmp(SN, "SIM") == 0)
                    {
                        break;
                    }

                }
                while (strcmp(SN, "NAO") != 0);
            }
            else if (verificar == 1)
            {

                getchar();
                do
                {
                    puts("Fazer outro teste?");
                    fgets(SN, 100, stdin);
                    LetrasMaiusculas(SN);
                    TiraN(SN);

                    if (strcmp(SN, "NAO") == 0)
                    {
                        break;
                    }

                    if (strcmp(SN, "SIM") != 0)
                    {
                        puts("Apenas sim ou nao");
                    }

                    if (strcmp(SN, "SIM") == 0)
                    {
                        break;
                    }

                }
                while (strcmp(SN, "NAO") != 0);
            }

        }
        while (strcmp(SN, "SIM") == 0);

        break;

    // Pesquisa por aeroporto de origem
    case 2:
        getchar();
        do
        {

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
            }
            while (ApenasLetras(G.codAeroporto_Origem) == 0 || verificarTam(G.codAeroporto_Origem, 3) == 0);

            LetrasMaiusculas(G.codAeroporto_Origem);

            for (int i = 0; i < linhas; i++)
            {
                if (strcmp(G.codAeroporto_Origem, P[i].codAeroporto_Origem) == 0)
                {
                    printf("Encontrado:\n");
                    printf("%d;%s;%s;%s;%s;%s;%s;%s;%.2lf\n", P[i].ID,
                           P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
                           P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
                           P[i].Hora_Partida, P[i].Hora_Chegada, P[i].ValorPassagem);
                }
                else
                {
                    teste--;
                }
            }

            if (teste == 0)
            {

                do
                {
                    puts("Nao encontrado, tentar novamente? Sim ou Nao");
                    fgets(SN, 100, stdin);
                    LetrasMaiusculas(SN);

                    TiraN(SN);

                    if (strcmp(SN, "NAO") == 0)
                    {
                        break;
                    }

                    if (strcmp(SN, "SIM") != 0)
                    {
                        puts("Apenas sim ou nao");
                    }

                    if (strcmp(SN, "SIM") == 0)
                    {
                        break;
                    }

                    teste = linhas;

                }
                while (strcmp(SN, "NAO") != 0);
            }
            else
            {

                do
                {
                    puts("Fazer outro teste?");
                    fgets(SN, 100, stdin);
                    LetrasMaiusculas(SN);
                    TiraN(SN);

                    if (strcmp(SN, "NAO") == 0)
                    {
                        break;
                    }
                    if (strcmp(SN, "SIM") != 0)
                    {
                        puts("Apenas sim ou nao");
                    }
                    if (strcmp(SN, "SIM") == 0)
                    {
                        break;
                    }

                }
                while (strcmp(SN, "NAO") != 0);
            }

            teste = linhas;
        }
        while (strcmp(SN, "SIM") == 0);

        break;

    case 3:
        getchar();
        // Pesquisa por aeroporto de destino
        do
        {

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

            }
            while (ApenasLetras(G.codAeroporto_Destino) == 0 || verificarTam(G.codAeroporto_Destino, 3) == 0);

            LetrasMaiusculas(G.codAeroporto_Destino);
            fprintf(arquivo, "%s;", G.codAeroporto_Destino);

            teste = linhas;

            for (int i = 0; i < linhas; i++)
            {
                if (strcmp(G.codAeroporto_Destino, P[i].codAeroporto_Destino) == 0)
                {
                    printf("Encontrado:\n");
                    printf("%d;%s;%s;%s;%s;%s;%s;%s;%.2lf\n", P[i].ID,
                           P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
                           P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
                           P[i].Hora_Partida, P[i].Hora_Chegada, P[i].ValorPassagem);
                }
                else
                {
                    teste--;
                }
            }

            if (teste == 0)
            {

                do
                {
                    puts("Nao encontrado, tentar novamente? Sim ou Nao");
                    fgets(SN, 100, stdin);
                    LetrasMaiusculas(SN);

                    TiraN(SN);

                    if (strcmp(SN, "NAO") == 0)
                    {
                        break;
                    }

                    if (strcmp(SN, "SIM") != 0)
                    {
                        puts("Apenas sim ou nao");
                    }

                    if (strcmp(SN, "SIM") == 0)
                    {
                        break;
                    }

                    teste = linhas;

                }
                while (strcmp(SN, "NAO") != 0);
            }
            else
            {

                do
                {
                    puts("Fazer outro teste?");
                    fgets(SN, 100, stdin);
                    LetrasMaiusculas(SN);
                    TiraN(SN);

                    if (strcmp(SN, "NAO") == 0)
                    {
                        break;
                    }
                    if (strcmp(SN, "SIM") != 0)
                    {
                        puts("Apenas sim ou nao");
                    }
                    if (strcmp(SN, "SIM") == 0)
                    {
                        break;
                    }

                }
                while (strcmp(SN, "NAO") != 0);
            }

            teste = linhas;
        }
        while (strcmp(SN, "SIM") == 0);

        break;

    // Pesquisa por cidade de origem

    case 4:
        getchar();
        do
        {

            do
            {
                puts("Digite a Cidade de Origem (apenas letras)");
                fgets(G.CidadeOrigem, 101, stdin);
                TiraN(G.CidadeOrigem);

                if (ApenasLetras(G.CidadeOrigem) == 0)
                {
                    printf("Nome da cidade pode conter apenas letras, sem caracteres ou numeros.\n");
                }
            }
            while (ApenasLetras(G.CidadeOrigem) == 0);

            LetrasMaiusculas(G.CidadeOrigem);
            fprintf(arquivo, "%s;", G.CidadeOrigem);

            teste = linhas;

            for (int i = 0; i < linhas; i++)
            {
                if (strcmp(G.CidadeOrigem, P[i].CidadeOrigem) == 0)
                {
                    printf("Encontrado:\n");
                    printf("%d;%s;%s;%s;%s;%s;%s;%s;%.2lf\n", P[i].ID,
                           P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
                           P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
                           P[i].Hora_Partida, P[i].Hora_Chegada, P[i].ValorPassagem);
                }
                else
                {
                    teste--;
                }
            }

            if (teste == 0)
            {

                do
                {
                    puts("Nao encontrado, tentar novamente? Sim ou Nao");
                    fgets(SN, 100, stdin);
                    LetrasMaiusculas(SN);

                    TiraN(SN);

                    if (strcmp(SN, "NAO") == 0)
                    {
                        break;
                    }

                    if (strcmp(SN, "SIM") != 0)
                    {
                        puts("Apenas sim ou nao");
                    }

                    if (strcmp(SN, "SIM") == 0)
                    {
                        break;
                    }

                    teste = linhas;

                }
                while (strcmp(SN, "NAO") != 0);
            }
            else
            {

                do
                {
                    puts("Fazer outro teste?");
                    fgets(SN, 100, stdin);
                    LetrasMaiusculas(SN);
                    TiraN(SN);

                    if (strcmp(SN, "NAO") == 0)
                    {
                        break;
                    }
                    if (strcmp(SN, "SIM") != 0)
                    {
                        puts("Apenas sim ou nao");
                    }
                    if (strcmp(SN, "SIM") == 0)
                    {
                        break;
                    }

                }
                while (strcmp(SN, "NAO") != 0);
            }

            teste = linhas;
        }
        while (strcmp(SN, "SIM") == 0);

        break;

    // Pesquisa por cidade de destino

    case 5:
        getchar();
        do
        {

            do
            {
                puts("Digite a Cidade de Destino (apenas letras)");
                fgets(G.CidadeDestino, 101, stdin);
                TiraN(G.CidadeDestino);

                if (ApenasLetras(G.CidadeDestino) == 0)
                {
                    printf("Nome da cidade pode conter apenas letras, sem caracteres ou numeros.\n");
                }
            }
            while (ApenasLetras(G.CidadeDestino) == 0);

            LetrasMaiusculas(G.CidadeDestino);
            fprintf(arquivo, "%s;", G.CidadeDestino);

            teste = linhas;

            for (int i = 0; i < linhas; i++)
            {
                if (strcmp(G.CidadeDestino, P[i].CidadeDestino) == 0)
                {
                    printf("Encontrado:\n");
                    printf("%d;%s;%s;%s;%s;%s;%s;%s;%.2lf\n", P[i].ID,
                           P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
                           P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
                           P[i].Hora_Partida, P[i].Hora_Chegada, P[i].ValorPassagem);
                }
                else
                {
                    teste--;
                }
            }

            if (teste == 0)
            {

                do
                {
                    puts("Nao encontrado, tentar novamente? Sim ou Nao");
                    fgets(SN, 100, stdin);
                    LetrasMaiusculas(SN);

                    TiraN(SN);

                    if (strcmp(SN, "NAO") == 0)
                    {
                        break;
                    }

                    if (strcmp(SN, "SIM") != 0)
                    {
                        puts("Apenas sim ou nao");
                    }

                    if (strcmp(SN, "SIM") == 0)
                    {
                        break;
                    }

                    teste = linhas;

                }
                while (strcmp(SN, "NAO") != 0);
            }
            else
            {

                do
                {
                    puts("Fazer outro teste?");
                    fgets(SN, 100, stdin);
                    LetrasMaiusculas(SN);
                    TiraN(SN);

                    if (strcmp(SN, "NAO") == 0)
                    {
                        break;
                    }
                    if (strcmp(SN, "SIM") != 0)
                    {
                        puts("Apenas sim ou nao");
                    }
                    if (strcmp(SN, "SIM") == 0)
                    {
                        break;
                    }

                }
                while (strcmp(SN, "NAO") != 0);
            }

            teste = linhas;
        }
        while (strcmp(SN, "SIM") == 0);

        break;
    }
    puts("\nVoltando para o menu\n");
    main();
}
