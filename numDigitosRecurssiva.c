#include <stdio.h>

int numDigitos(int x)
{   
    if (x == 0)
    {
        return 1;
    }
    if (x < 10 && x > -10) 
    {
        return 1;
    }
    return 1 + numDigitos(x/10); 
}

