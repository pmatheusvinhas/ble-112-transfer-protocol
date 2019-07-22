#include <stdio.h>
#include <conio.h>

unsigned int ieee754(float entrada);

void main(void)
{
    float numero;
    unsigned int resultado,i;

    printf("\n\n*****Digite o numero a ser representado na norma IEEE754: ");
    scanf("%f", &numero);
    resultado = ieee754(numero);
    printf("\n%X",resultado);
}

unsigned int ieee754(float entrada)
{
    float entrada_float;
    unsigned int entrada_inteiro,expoente,mantissa,saida,potencia;

    //DEFINIÇÃO DO SINAL
    if(entrada < 0)
    {
        saida = 0x80000000;
        entrada_inteiro = -entrada;
        entrada_float = (-entrada) - entrada_inteiro;
    }
    else
    {
        saida = 0x00000000;
        entrada_inteiro = entrada;
        entrada_float = entrada - entrada_inteiro;
    }

    //CALCULO DO EXPOENTE E MANTISSA INTEIRA
    expoente = 0;
    if(entrada_inteiro)
    {
        potencia = 1;
        mantissa = 0;
        while(entrada_inteiro/2)
        {
            if(entrada_inteiro % 2)
                mantissa += potencia;
            entrada_inteiro /= 2;
            expoente++;
            potencia *= 2;
        }

        saida += ((expoente + 0x7F) << 23);

        if(!potencia)
            potencia = 0x400000;
        else
        {
            potencia /= 2;
            potencia = 0x400000 / potencia;
            mantissa *= potencia;
            potencia /= 2;
        }
    }
    else
    {
        while(!entrada_inteiro)
        {
            expoente++;
            entrada_float *= 2;
            entrada_inteiro = entrada_float;
        }
        saida += ((-expoente + 0x7F) << 23);
        mantissa = 0;
        potencia = 0x400000;
        entrada_float -= entrada_inteiro;
    }

    //CALCULO DA MANTISSA DECIMAL
    while(potencia)
    {
        entrada_float *= 2;
        entrada_inteiro = entrada_float;
        if(entrada_inteiro)
        {
            mantissa += potencia;
            entrada_float -= entrada_inteiro;
        }
        potencia /= 2;
    }
    saida += mantissa;

    return saida;
}
