#include <stdio.h>
#include <math.h>

// Função recursiva para calcular a raiz quadrada usando o método de Newton
double newton(int valor, double chute, double limite) {
    double resultado = chute - (((pow(chute, 2)) - valor) / (2 * chute));
    
    // Critério de parada: se a diferença entre a aproximação atual e a próxima é menor que limite
    if (fabs(chute - resultado) < limite) {
        return resultado;
    }
    // Chamada recursiva com a nova aproximação
    return newton(valor, resultado, limite);
}

int main() {
    int valor;
    double chute;
    double limite = pow(10, -6);

    printf("Digite o numero que tera a raiz encontrada: ");
    if (scanf("%d", &valor) != 1 || valor <= 0) {
        printf("Erro: entrada inválida. O valor deve ser um número positivo.\n");
        return 1;
    }

    printf("Digite o seu chute: ");
    if (scanf("%lf", &chute) != 1 || chute <= 0) {
        printf("Erro: entrada inválida. O chute inicial deve ser um número positivo e maior que zero.\n");
        return 1;
    }

    double resultado = newton(valor, chute, limite);

    printf("A raiz aproximada de %d é: %lf\n", valor, resultado);

    return 0;
}
