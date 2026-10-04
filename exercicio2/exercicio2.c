#include <stdio.h>
#include <stdlib.h>

void relatorio_diario(float vendas[4][5])
{
    float soma_diaria[5] = {0};
    float total_rede = 0.0;

    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            soma_diaria[j] = soma_diaria[j] + vendas[i][j];
        }
        total_rede = total_rede + soma_diaria[j];

        printf("Faturamento de R$ %.2f\n", soma_diaria[j]);
    }

    float media_diaria = total_rede / 5.0;
    printf("\nMedia diaria geral da rede: R$ %.2f\n", media_diaria);

    printf("Dias que superaram a media geral:\n");
    for (int j = 0; j < 5; j++)
    {
        if (soma_diaria[j] > media_diaria)
        {
            printf("- Dia %d\n", j);
        }
    }
}

float matriz[4][5];

int filial_campea(float vendas[4][5])
{

    int filial_campea = 0;
    float maior_faturamento = 0;

    for (int i = 0; i < 4; i++)
    {
        float soma_filial = 0;
        for (int j = 0; j < 5; j++)
        {
            soma_filial = soma_filial + vendas[i][j];
        }

        if (soma_filial > maior_faturamento)
        {
            filial_campea = i;
            maior_faturamento = soma_filial;
        }
    }

    return filial_campea;
}

void preencher_vendas(float vendas[4][5])
{

    int i, j;

    for (i = 0; i < 4; i++)
    {

        for (j = 0; j < 5; j++)
        {
            while (1)
            {
                printf("Digite o faturamento: ");
                scanf("%f", &vendas[i][j]);

                if (vendas[i][j] >= 0)
                {
                    break;
                }
                printf("ERRO: O valor nao pode ser negativo. Tente novamente.\n");
            }
        }
    }
}

main()
{
    float vendas[4][5];

    preencher_vendas(vendas);

    printf("A filial campea foi a Filial: %d\n\n", filial_campea(vendas););

    relatorio_diario(vendas);

    return 0;
}