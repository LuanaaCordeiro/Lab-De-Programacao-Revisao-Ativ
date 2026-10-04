#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int opcao;
    int horas;
    int preco = 0;

    int qtd_carros = 0, qtd_motos = 0, qtd_camionetes = 0;
    int receita_carros = 0, receita_motos = 0, receita_camionetes = 0;

    do
    {

        printf("============ SISTEMA DE ESTACIONAMENTO - UFC RUSSAS ============\n");
        printf("1 - Registrar Entrada e Cobrança de Veiculo\n");
        printf("2 - Exbirir Relatório de Arrecadacao do Turno\n");
        printf("3 - Zerar Registros do Turno\n");
        printf("0 - Encerrar Programa\n");
        printf("================================================================\n");
        scanf("%d", &n);

            switch (n)
            {
            case 1:
                printf("Digite a quantidade de horas que voce ficou: ");
                scanf("%d", &horas);

                printf("----- Digite o seu tipo de veiculo -----\n");
                printf("1 - Carro: R$15 hora\n");
                printf("2 - Moto: R$8 hora\n");
                printf("3 - Camionete: R$25 hora\n");
                scanf("%d", &opcao);

                if (opcao == 1)
                {
                    preco = 15 * horas;
                    qtd_carros++;
                    receita_carros += preco;
                    printf("=> REGISTRO FEITO! Valor a pagar: R$ %d\n", preco);
                }
                else if (opcao == 2)
                {
                    preco = 8 * horas;
                    qtd_motos++;
                    receita_motos += preco;
                    printf("=> REGISTRO FEITO! Valor a pagar: R$ %d\n", preco);
                }
                else if (opcao == 3)
                {
                    preco = 25 * horas;
                    qtd_camionetes++;
                    receita_camionetes += preco;
                    printf("=> REGISTRO FEITO! Valor a pagar: R$ %d\n", preco);
                }
                else
                {
                    printf("Este numero eh invalido!");
                }
                break;

            case 2:

                int faturamento_total = receita_carros + receita_motos + receita_camionetes;
                int total_veiculos = qtd_carros + qtd_motos + qtd_camionetes;
                float valor_medio = 0.0;

                if (total_veiculos > 0)
                {
                    valor_medio = (float)faturamento_total / total_veiculos;
                }

                printf("Quantidade de carros atendidos: %d \n", qtd_carros);
                printf("Faturamento com carros: %d\n", receita_carros);

                printf("Quantidade de motos atendidas: %d\n", qtd_motos);
                printf("Faturamento com motos: %d\n", receita_motos);

                printf("Quantidade de camionetes atendidas: %d\n", qtd_camionetes);
                printf("Faturamento com camionetes: %d\n", receita_camionetes);

                printf("Faturamento TOTAL do turno: R$ %d\n", faturamento_total);
                printf("Total de veiculos atendidos: %d\n", total_veiculos);
                printf("Valor medio cobrado por veiculo: R$ %.2f\n", valor_medio);
                break;

            case 3:
                qtd_carros = 0;
                qtd_motos = 0;
                qtd_camionetes = 0;

                receita_carros = 0;
                receita_motos = 0;
                receita_camionetes = 0;

                printf("\n=> SUCESSO: Todos os registros do turno foram zerados!\n");
                break;

            case 0:
                printf("\nEncerrando o sistema. Ate logo!\n");
                break;

            default:
                printf("\nOPCAO INVALIDA\n");
                break;
            }
    } while (n != 0);

    return 0;
}