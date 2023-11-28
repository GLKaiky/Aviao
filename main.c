#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int Listar_Passagens();
int Cadastro_de_Passagens();
void pesquisar();
void Excluir();

// Struct de passagens
typedef struct passagens
{
    char codAeroporto_Origem[100];
    char codAeroporto_Destino[100];
    char CidadeOrigem[100];
    char CidadeDestino[100];
    char Data[15];
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
// Ultimo ID
int UltimoID()
{
    FILE *arquivo = fopen("passagens.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return -1; // Retorna um valor indicando erro
    }

    int quantidadedelinhas;
    fscanf(arquivo, "%d", &quantidadedelinhas);

    if (quantidadedelinhas == 0)
    {
        fclose(arquivo);
        return 0; // Retorna 0 se não houver passagens registradas
    }

    int ultimoID = 0; // Define um valor inicial para o último ID

    // Busca o último ID percorrendo o arquivo até o final
    while (!feof(arquivo))
    {
        passagens P;
        fscanf(arquivo, " %d;%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];R$%*lf", &P.ID);
        ultimoID = P.ID; // Atualiza o último ID encontrado
    }

    fclose(arquivo);
    return ultimoID;
}
// limitar tamanho da string
void limitarTamanho(char *str, int tamanho)
{
    if (strlen(str) > tamanho)
    {
        str[tamanho] = '\0'; // Adiciona um terminador para cortar a string no tamanho desejado
    }
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

passagens Cad_Mod(int ID)
{
    passagens P;

    P.ID = ID;
    do
    {
        getchar();
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

    // valor da passagem
    puts("Digite o valor da passagem em R$");

    while (scanf("%lf", &P.ValorPassagem) != 1)
    {
        printf("Digite apenas números para o valor.\n");
        printf("Digite o valor da passagem em R$: ");
        while (getchar() != '\n'); // Limpa o buffer de entrada
    }

    return P;
}

int main()
{

    FILE *arquivo = fopen("passagens.txt", "r+");
    int linha = ContaLinha() - 2;
    if (linha < 0)
    {
        linha = 0;
    }

    printf("%d\n", linha);
    fseek(arquivo, 0, SEEK_SET);
    fprintf(arquivo, "%d\n", linha);
    fclose(arquivo);

    arquivo = fopen("passagens.txt", "r+");
    int A = UltimoID();
    fseek(arquivo, 3, SEEK_SET);
    fprintf(arquivo, "%d\n", A);
    fclose(arquivo);

    char opcao[100];

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

        if (atoi(opcao) < 1 || atoi(opcao) > 6 || ApenasNumeros(opcao) == 0)
        {
            puts("Apenas as opcoes de 1 a 6");
            puts("Digite novamente:");
        }

    }
    while (atoi(opcao) < 1 || atoi(opcao) > 6 || ApenasNumeros(opcao) == 0);

    int opcao1 = atoi(opcao);

    switch (opcao1)
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
        Editar();
        break;
    case 5:
        Excluir();
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

    P.ID = ContaLinha() - 1;
    int Y = UltimoID();

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

int Listar_Passagens2()
{
    FILE *arquivo = fopen("passagens.txt", "r");

    char linhas[1000];

    puts("---------------------------------------------------------");
    while (fgets(linhas, sizeof(linhas), arquivo) != NULL)
    {
        printf("%s", linhas);
    }
    puts("---------------------------------------------------------");

    fclose(arquivo);
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
    FILE *arquivo = fopen("passagens.txt", "r");

    int quantidadeLinhas = 0;
    int ultimoID = 0;
    fscanf(arquivo, "%d", &quantidadeLinhas); // Lendo o primeiro numero do arquivo
    fscanf(arquivo, "%d", &ultimoID);         // Lê o ID da última passagem

    if (quantidadeLinhas <= 0 || ultimoID <= 0)
    {
        printf("Arquivo vazio ou mal formatado.\n");
        fclose(arquivo);
        main();
        printf("\n");
    }

    passagens P[quantidadeLinhas];
    int indice = 0;

    while (fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];R$%lf\n", &P[indice].ID,
                  P[indice].codAeroporto_Origem, P[indice].codAeroporto_Destino,
                  P[indice].CidadeOrigem, P[indice].CidadeDestino, P[indice].Data,
                  P[indice].Hora_Partida, P[indice].Hora_Chegada, &P[indice].ValorPassagem) == 9)
    {
        indice++;
    }

    fclose(arquivo);

    int idExcluir;

    Listar_Passagens2();

    int verificador = 0;
    do
    {
        printf("Digite o ID da passagem que deseja excluir: ");
        scanf("%d", &idExcluir);

        for (int i = 0; i < quantidadeLinhas; i++)
        {
            if (P[i].ID == idExcluir)
            {
                puts("Encontrado");
                verificador = 1;
                printf("%d;%s;%s;%s;%s;%s;%s;%s;R$%.2lf\n", P[i].ID,
                       P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
                       P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
                       P[i].Hora_Partida, P[i].Hora_Chegada, P[i].ValorPassagem);
            }
        }
        if (verificador == 0)
        {
            puts("Não encontrado, tente novamente");
        }

    }
    while (verificador == 0);

    char SN[4];
    getchar();
    do
    {

        puts("Deseja excluir esta passagem? Sim ou Nao");
        fgets(SN, 100, stdin);
        LetrasMaiusculas(SN);
        TiraN(SN);

        if (strcmp(SN, "NAO") == 0)
        {
            main();
        }

        if (strcmp(SN, "SIM") != 0)
        {
            puts("Apenas Sim ou Nao");
        }
    }
    while (strcmp(SN, "SIM") != 0);

    FILE *arquivoEscrita = fopen("passagens.txt", "w");

    fprintf(arquivoEscrita, "%d\n", quantidadeLinhas - 1); // Escreve a nova quantidade de linhas
    fprintf(arquivoEscrita, "%d\n", ultimoID);

    for (int i = 0; i < indice; i++)
    {
        if (P[i].ID != idExcluir)
        {
            fprintf(arquivoEscrita, "%d;%s;%s;%s;%s;%s;%s;%s;R$%.2lf\n", P[i].ID,
                    P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
                    P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
                    P[i].Hora_Partida, P[i].Hora_Chegada, P[i].ValorPassagem);
        }
        else
        {
            puts("Excluindo...");
            printf("%d;%s;%s;%s;%s;%s;%s;%s;R$%.2lf\n", P[i].ID,
                   P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
                   P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
                   P[i].Hora_Partida, P[i].Hora_Chegada, P[i].ValorPassagem);
        }
    }

    fclose(arquivoEscrita);
    puts("Retornando ao menu");
    main();
}

void Editar()
{

    FILE *arquivo = fopen("passagens.txt", "r");

    int quantidadeLinhas = 0;
    int ultimoID = 0;
    fscanf(arquivo, "%d", &quantidadeLinhas); // Lendo o primeiro numero do arquivo
    fscanf(arquivo, "%d", &ultimoID);         // Lê o ID da última passagem

    if (quantidadeLinhas <= 0 || ultimoID <= 0)
    {
        printf("Arquivo vazio ou mal formatado.\n");
        fclose(arquivo);
        main();
        printf("\n");
    }

    passagens P[quantidadeLinhas];

    int indice = 0;

    while (fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];R$%lf\n", &P[indice].ID,
                  P[indice].codAeroporto_Origem, P[indice].codAeroporto_Destino,
                  P[indice].CidadeOrigem, P[indice].CidadeDestino, P[indice].Data,
                  P[indice].Hora_Partida, P[indice].Hora_Chegada, &P[indice].ValorPassagem) == 9)
    {
        indice++;
    }

    fclose(arquivo);

    int idEditar;

    Listar_Passagens2();

    int verificador = 0;
    do
    {
        printf("Digite o ID da passagem que deseja editar: ");
        scanf("%d", &idEditar);

        for (int i = 0; i < quantidadeLinhas; i++)
        {
            if (P[i].ID == idEditar)
            {
                puts("Encontrado");
                verificador = 1;
            }
        }

        if (verificador == 0)
        {
            puts("Nao encontrado, tente novamente");
        }
    }
    while (verificador == 0);

    FILE *arquivoEscrita = fopen("passagens.txt", "w");

    fprintf(arquivoEscrita, "%d\n", quantidadeLinhas);
    fprintf(arquivoEscrita, "%d\n", ultimoID);

    for (int i = 0; i < indice; i++)
    {
        if (P[i].ID != idEditar)
        {
            fprintf(arquivoEscrita, "%d;%s;%s;%s;%s;%s;%s;%s;R$%.2lf\n", P[i].ID,
                    P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
                    P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
                    P[i].Hora_Partida, P[i].Hora_Chegada, P[i].ValorPassagem);
        }
        else if (P[i].ID == idEditar)
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

    fclose(arquivoEscrita);
    puts("Editado com sucesso!");
    puts("Retornando ao menu");
    getchar();
    main();
}

void pesquisar()
{
    if (UltimoID() == 0)
    {
        puts("Arquivo vazio, favor preencher...Voltando ao menu");
        main();
    }

    char SN[3];
    int A;
    int linhas = ContaLinha() - 1;
    int teste = linhas;

    FILE *arquivo = fopen("passagens.txt", "r");

    int quantidadedelinhas;
    int UltimoID;
    fscanf(arquivo, "%d", &quantidadedelinhas);
    fscanf(arquivo, "%d", &UltimoID);
    passagens P[linhas];
    passagens G;

    for (int i = 0; i < linhas; i++)
    {
        fscanf(arquivo, " %d; %[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];R$%lf", &P[i].ID,
               P[i].codAeroporto_Origem, P[i].codAeroporto_Destino,
               P[i].CidadeOrigem, P[i].CidadeDestino, P[i].Data,
               P[i].Hora_Partida, P[i].Hora_Chegada, &P[i].ValorPassagem);
    }

    fclose(arquivo);

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
