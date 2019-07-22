#include <stdio.h>
#include <conio.h>

void main(void) {
    float numero,resultado;
    unsigned int i;

    printf("\n\n*****Digite o numero a ser representado na norma IEEE754: ");
    scanf("%f", &numero);
    //resultado = (numero^0xFFFFFFFF)+1;
    resultado = numero*(-1);
    //resultado = !numero;
    printf("\n%f",resultado);
}