#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    
    if (argc != 2) 
    {
        printf("Uso: %s <palavra>\n", argv[0]);
        return 1;
    }

    int tamanho = strlen(argv[1]);
    char* palavra = malloc((tamanho + 1) * sizeof(char)); // +1 para o caractere nulo

    strcpy(palavra, argv[1]);

    int eh_palindromo = 1; // Assumindo que a palavra é um palíndromo por padrão

    for (int i = 0; i < tamanho / 2; i++) {
        
        if (palavra[i] != palavra[tamanho - 1 - i]) 
        {
            eh_palindromo = 0; // Se os caracteres não coincidirem, não é um palíndromo
            break;
        }
    }

    if (eh_palindromo) 
    {
        printf("Essa palavra é um palíndromo!\n");
    } 
    else 
    {
        printf("Não é um palíndromo.\n");
    }

    free(palavra); // Liberar a memória alocada

    return 0;
}
