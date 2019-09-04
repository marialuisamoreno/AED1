#include <stdio.h>
#include <stdlib.h>

float soma (float *b, float *c)
{
    float e;
    e = *b + *c;
    return e;
}

float quad (float *a)
{
    float d;
    d = (*a)*(*a);
    return d;
}
int main()
{
    float a, b, c;

    scanf("%f %f %f", &a, &b, &c);

    printf("\nQuadrado do primeiro: %f\nSoma dos outros dois: %f\n", quad(&a), soma(&b, &c));
    return 0;
}