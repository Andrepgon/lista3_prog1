#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    int tamanho = strlen(argv[1]);
    char* palavra = malloc((tamanho + 1) * sizeof(char));
    strcpy(palavra, argv[1]);

    for(int i = 0; i < tamanho; i++)
    {
        printf("%c", palavra[tamanho - 1 - i]);
    }
    printf("\n");
    return 0;
}
