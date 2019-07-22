#include <stdio.h>
#include <stdlib.h>

int n, potencia, mant, num, contMantissa, iMant;
int M[23], IEEE754[32];

void main() {

    printf("Digite o numero a ser representado na norma");
    scanf(n);
    //Potencia
    if n > 1
        while (n >= 1)
            n = n / 2;
            potencia = potencia+1;
        end while
    else
        while n >= 1;
            n = n*2;
            potencia = potencia-1;
        end while
    end if

    exp = 127 + potencia

    //Mantissa
    mant = 1 - n
    contMantissa = 0
    i = 0
    while contMantissa <= 23
        if num < 1
            num = mant * 2;
            iMant = 1;
        else
            num = 1 - num;
            iMant = 0;
        end if

        contMantissa = contMantissa + 1;
        i = i+1;
        M[i] = iMant;
    end while

    IEEE754[] = {sig, M[], convertebinario(potencia) }
    printf("Numero no padrao IEEE754 bit:", &IEEE754);
}

int convertebinario(int dec)
{
int i,q[80],r[80];
i=0;
  /*Algoritmo para o cálculo */
  while (dec != 1){     // enquanto o quociente for diferente de 1, o programa continuará calculando
   q[i]= dec / 2;  //array que calcula e armazena os quocientes
   r[i] = dec % 2; //array que calcula e armazena os restos
   dec=q[i];       //atribuindo novo valor para q[i], pra que seja possível a continuação do cálculo
   i++;
   }

/*Imprimindo o último quociente mais os restos de "trás pra frente" (número em binários) */
  while (i>=0){
     if (q[i] == 1) printf("1%d",r[i]);
          else printf("%d",r[i]);
   i--;
   }
return;
}
