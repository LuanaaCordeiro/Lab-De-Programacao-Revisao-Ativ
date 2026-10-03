#include <stdio.h>
#include <stdlib.h>

int eh_par(int n)
{
    if (n % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int inverte_numero(int n)
{
    int invertido = 0;
    while (n > 0)
    {
        int digito = n % 10;
        invertido = (invertido * 10) + digito;
        n = n / 10;
    }

    return invertido;
}

void processar_vetor(int origem[], int destino[], int tamanho)
{

    for (int i = 0; i < tamanho; i++)
    {
        if (eh_par(origem[i]) == 1)
        {
            destino[i] = inverte_numero(origem[i]);
        }
        else
        {
            destino[i] = (3 * origem[i]) + 1;
        }
    }
}

int main()
{
    int origem[8];
    int destino[8];
    int tamanho = 8;

    printf("Digite 8 numeros inteiros e positivos: ");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &origem[i]);

        if (eh_par(origem[i]) == 1)
        {
            printf(" O numero %d eh par \n", origem[i]);
        }
        else
        {
            printf(" O numero %d eh impar \n", origem[i]);
        }
    }

    processar_vetor(origem, destino, tamanho);

    printf("Original\tTransformado\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d\t\t%d\n", origem[i], destino[i]);
    }
    return 0;
}