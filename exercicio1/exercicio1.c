#include <stdio.h>
#include <stdlib.h>

void identificar_extremos(float temperaturas[], int tamanho, float *maximo, float *minimo)
{

    int encontrado = 0;

    for (int i = 0; i < 10; i++)
    {

        if (temperaturas[i] >= -10 && temperaturas[i] <= 60)
        {

            if (encontrado == 0)
            {
                encontrado = 1;
                *maximo = temperaturas[i];
                *minimo = temperaturas[i];
            }
            else

            {
                if (*minimo > temperaturas[i])
                {
                    *minimo = temperaturas[i];
                }

                if (temperaturas[i] > *maximo)
                {
                    *maximo = temperaturas[i];
                }
            }
        }
    }

    printf("A maior temperatura eh: %f\n", *maximo);
    printf("A menor temperatura eh: %f\n", *minimo);
}

float calcular_medidas_validas(float temperaturas[], float tamanho, int *qtd_validas)
{

    for (int i = 0; i < 10; i++)
    {

        if (temperaturas[i] >= -10 && temperaturas[i] <= 60)
        {

            (*qtd_validas)++;
            tamanho = tamanho + temperaturas[i];
        }
    }

    if (*qtd_validas == 0)
    {

        return -1;
    }

    float media = tamanho / *qtd_validas;
    return media;
}

int main()
{
    float temperaturas[10];
    int i;
    int tamanho = 0;
    int qtd_validas = 0;
    float maxima = 0;
    float minima = 0;

    for (i = 0; i < 10; i++)
    {
        printf("Digite a temperatura: ");
        scanf("%f", &temperaturas[i]);
    }

    ;
    printf("A media das temperaturas foi: %f \n", calcular_medidas_validas(temperaturas, tamanho, &qtd_validas));
    printf("A quantidade de temperaturas válidas foram: %d", qtd_validas);
    identificar_extremos(temperaturas, tamanho, &maxima, &minima);

    if (maxima > 45 || minima < 0)
    {
        printf("TEMPERATURA CRITICA");
    }
    else
    {
        printf("CONDICAO OPERACIONAL NORMAL");
    }

    return 0;
}