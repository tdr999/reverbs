#include <stdio.h>
#include <math.h>
#include "prototype.h"
#include "prototype.c"
//pierdut precizie dar trecut tou pe 16 biti mai usor de lucrat

int main()
{
    printf("%d\n", WORD16(0.999));
    return 0;

}
