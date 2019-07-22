#include <stdio.h>
#include <stdlib.h>

int S, potencia, mant, num, contMantissa, iMant, expoente;
float n;
int M[23], expBIN;
int binaryNum[8], j;

int decToBinary(int lido);

void main() {
    potencia = 0;
    printf("Digite o numero a ser representado na norma IEEE754\n");
    scanf("%f", &n);

    if (n > 1) {
        while (n >= 1) {
            n = n / 2;
            potencia = potencia+1;
            S = 1;
        }
    }
    else if (n > 0 && n < 1)
    {
        while (n >= 1) {
            n = n*2;
            potencia = potencia-1;
            S = 1;
        }
    }
    else if (n < 0) {
        S = 0;
    }
    expoente = 127 + potencia; //OBS
    //printf(&expoente);
    //Mantissa
    mant = n - 1;
    //printf(&mant);
    contMantissa = 0;
    while (contMantissa <= 22) {
        if (num < 1) {
            num = mant * 2;
            iMant = 0;
        }
        else {
            num = 1 - num;
            iMant = 1;
        }

        contMantissa = contMantissa + 1;
        M[contMantissa] = iMant;
        }

    expBIN = decToBinary(expoente);

    printf("SINAL:\n", &S);
    printf("EXPOENTE:\n", &expBIN);
    printf("MANTISSA:\n", &M);
}

int decToBinary(int lido)
{
    int i = 0;
    while (n > 0) {

        binaryNum[i] = lido % 2;
        lido = lido / 2;
        i++;
    }

    for (j = i - 1; j >= 0; j--)
        //cout << binaryNum[j];

    return binaryNum[j];
}


