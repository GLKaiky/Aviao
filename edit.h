//Função do tipo passagens responsavel por preencher a struct e editar o arquivo
passagens Cad_Mod(int ID)
{
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
        }
        else if(ano < 1000)
        {
            puts("Digite o ano com 4 Digitos\n");
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
