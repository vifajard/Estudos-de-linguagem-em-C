#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define T 4
//Função para preencher a matriz
void fazematri (int ma[T][T])
    {
        for (int x = 0; x < T; x++)
        {
         for (int y = 0; y < T; y++)
            {
             scanf("%d", &ma[x][y]);
            }
        }
    }
    //Multiplicação da matriz
    void vezma (int ma[T][T], int resu[T][T], int num )
    {
     for (int x = 0; x < T; x++)
        {
          for (int y = 0; y < T; y++)
            {
             resu[x][y] = ma[x][y] *num;
            }
        }
    }
    //Exibição da matriz
    void mostrama (int ma[T][T])
    {
     for (int x = 0; x < T; x++)
        {
         for (int y = 0; y < T; y++) 
            {
             printf("%d\t", ma[x][y]);
 
            }
         printf("\n");
        }
    }

 int main(){
    setlocale (LC_ALL, "portuguese");

        int ma[T][T], resu[T][T], num;
         printf("\nDigite um número inteiro: ");
         scanf("%d", &num);
    

     printf("\nDigite os números da matriz: \n");
      fazematri(ma);
    
         vezma(ma, resu, num);
    
          printf("\nA sua matriz original é: \n");
          mostrama(ma);
    
     printf("\nO resultado da matriz multiplicado pelo número %d é: \n", num);
     mostrama(resu);
    
 return 0;

 }
 //Vinicius Almeida Fajardo