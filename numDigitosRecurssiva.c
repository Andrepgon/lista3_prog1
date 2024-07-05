#include <stdio.h>

int numDigitos(int x) {
    // Caso base: se x está entre -9 e 9, incluindo 0, tem um dígito
    if (x < 10 && x > -10) {
        return 1;
    }
    // Chamada recursiva
    return 1 + numDigitos(x / 10);
}

int main() {
    int numero = 12345;
    printf("O número %d tem %d dígitos.\n", numero, numDigitos(numero));
    return 0;
}
