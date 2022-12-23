#include <stdio.h>

int main ()

{

    long l;
    
    short s = (8 * sizeof(l));
    
    printf("Word size of this machine is %hi bits\n", s);
    
    return 0;
}

