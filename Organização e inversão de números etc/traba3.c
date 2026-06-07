#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define T 5
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
 //Calculo da diagonal principal e soma da secundária
 void diagocal (int ma[T][T], int *resu, int *so)
    {
     *resu = 1;
     *so = 0;
    for (int x = 0; x < T; x++) 
        {
         *resu *= ma[x][x];
         *so += ma[x][T - 1 - x];
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
  int ma[T][T], resu, so;

  printf("\nDigite os números da matriz: \n");
      fazematri(ma);

      diagocal(ma, &resu, &so);
      printf("\nA matriz insirida é: \n");
     mostrama(ma);

     printf("O resultado da diagonal principal é: %d\n", resu);
    printf("Resultado da soma da diagonal secundária é: %d\n", so);




    return 0;
}
 //Vinicius Almeida Fajardo