#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void converteParaMaiusculas(char* texto)
{
    for(int i = 0; texto[i] != '\0'; i++)
    {
        if(texto[i] >= 97 && texto[i] <= 122) //se o a palavra for uma letra minúscula do alfabeto, ela será convertida para uma maiúscula
        {
            texto[i] = texto[i] - 32;
        }
        printf("%c", texto[i]); // printa a palavra no índice i
    }
    return;
}

int main()
{
    char texto[MAX*10];
    printf("Digite um texto para ser convertido para letras maiusculas: " );
    fgets(texto, sizeof(texto), stdin);
    printf("\n");
    converteParaMaiusculas(texto);
    return 0;
} 
