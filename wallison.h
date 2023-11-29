
// Struct de passagens

typedef struct passagens
{
    char codAeroporto_Origem[100]; //As strings foram deixadas de tamanho grande para tratamento de erros de digitação
    char codAeroporto_Destino[100];
    char CidadeOrigem[100];
    char CidadeDestino[100];
    char Data[15];
    char Hora_Partida[100];
    char Hora_Chegada[100];
    double ValorPassagem;
    int ID;

} passagens;

// Funções Uteis

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

// Contar linhas do arquivo

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

// Ultimo ID registrado no arquivo
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
// Limitar tamanho da string
void limitarTamanho(char *str, int tamanho)
{
    if (strlen(str) > tamanho)
    {
        str[tamanho] = '\0'; // Adiciona um terminador para cortar a string no tamanho desejado
    }
}

// Filtros

//Verificar se o que foi digitado tem apenas letras
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

//Verificar se o que foi digitado tem apenas numeros
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

int Listar_Passagens2()//Listagem de passagens modificada para a função de excluir
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

