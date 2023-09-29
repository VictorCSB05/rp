#include <stdio.h>
#include <math.h>

int main() {
    int opcao;

    do {
        int tam1, tam2;

        printf("\nMenu de opcoes\n");
        printf("Soma (1)\n");
        printf("Produto (2)\n");
        printf("Calcular o valor do polinômio (3)\n");
        printf("Sair (0)\n");
        printf("Digite o número da opcao desejada: ");

        scanf("%d", &opcao);

        if (opcao == 1 || opcao == 2) {
            printf("Qual o grau do primeiro polinomio \n");
            scanf("%d", &tam1);
            int vetora[tam1 + 1];

            for (int i = 0; i <= tam1; i++) {
                printf("Digite os numeros do primeiro polinomio: ");
                scanf("%d", &vetora[i]);
            }

            printf("Qual o grau do segundo polinomio? \n");
            scanf("%d", &tam2);
            int vetorb[tam2 + 1];

            for (int c = 0; c <= tam2; c++) {
                printf("Digite os numeros do segundo polinomio: ");
                scanf("%d", &vetorb[c]);
            }

            printf("Primeiro polinomio: ");
            for (int j = tam1; j >= 0; j--) {
                printf("%d", vetora[j]);
                if (j != 0) {
                    printf("x^%d + ", j);
                    if (vetora[j - 1] >= 0) {
                        printf(" ");
                    }
                }
            }

            printf("\nSegundo polinomio: ");
            for (int j = tam2; j >= 0; j--) {
                printf("%d", vetorb[j]);
                if (j != 0) {
                    printf("x^%d + ", j);
                    if (vetorb[j - 1] >= 0) {
                        printf(" ");
                    }
                }
            }

            int tamresult = (tam1 > tam2) ? tam1 : tam2;
            int result[tamresult + 1];

            for (int i = 0; i <= tamresult; i++) {
                result[i] = 0;
            }

            if (opcao == 1) {
                for (int i = 0; i <= tamresult; i++) {
                    result[i] = (i <= tam1 ? vetora[i] : 0) + (i <= tam2 ? vetorb[i] : 0);
                }

                printf("\nResultado da soma: ");
            } else if (opcao == 2) {
                for (int i = 0; i <= tam1; i++) {
                    for (int j = 0; j <= tam2; j++) {
                        result[i + j] += vetora[i] * vetorb[j];
                    }
                }

                printf("\nResultado do produto: ");
            }

            for (int j = tamresult; j >= 0; j--) {
                printf("%d", result[j]);
                if (j != 0) {
                    printf("x^%d +", j);
                    if (result[j - 1] >= 0) {
                        printf(" ");
                    }
                }
            }

            printf("\n");
        } else if (opcao == 3) {
            int grau;

            printf("Digite o grau do polinômio: ");
            scanf("%d", &grau);

            int coeficientes[grau + 1];
            for (int i = 0; i <= grau; i++) {
                printf("Digite o coeficiente do termo de grau %d: ", i);
                scanf("%d", &coeficientes[i]);
            }

            printf("Polinômio: ");
            for (int j = grau; j >= 0; j--) {
                printf("%d", coeficientes[j]);
                if (j != 0) {
                    printf("x^%d ", j);
                    if (coeficientes[j - 1] >= 0) {
                        printf("+ ");
                    }
                }
            }

            int x;
            printf("\nDigite o valor de x: ");
            scanf("%d", &x);

            int valor = 0;
            for (int i = 0; i <= grau; i++) {
                valor += coeficientes[i] * (int)pow(x, i);
            }

            printf("\nValor do polinômio para x = %d é: %d\n", x, valor);
        } else if (opcao != 0) {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 0);
}
