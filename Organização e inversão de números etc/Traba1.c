 #include <stdio.h>
 #include <stdlib.h>
 #include <locale.h>
 
 //Leitura dos vetores
    void leNumposi (int *NumPosi, int vetor)
   {
      for (int i = 0; i < vetor; i++)
     {
       scanf("%d", &NumPosi[i]);

      }
   }
 //Multiplicação dos vetores por 2
    void dobraNum (int *NumPosi, int vetor)
   {
     for (int i = 0; i < vetor; i++)
      {
       NumPosi[i] *= 2;
      }

   }
 //Função para a exibição do vetores na ordem normal
    void MosNum (int *NumPosi, int tamanho) 
   {
     printf("[");
      for (int i = 0; i < tamanho; i++) 
      {
         printf("%d", NumPosi[i]);
            if (i < tamanho - 1) 
            {
             printf("_");
            }
      }
    printf("]\n");
   }
int main()
{
 int vetor;

    setlocale(LC_ALL, "portuguese");
 printf("Digite a quantidade de vetores que você deseja: ");
    scanf ("%d", &vetor );

     int *NumPosi = (int *)malloc(vetor * sizeof(int));
        if (NumPosi == NULL)
         {
          printf("Error");
          return 1;
         }
    printf("Digite os números dos vetor: ");
    leNumposi (NumPosi, vetor);

    dobraNum(NumPosi, vetor);
    
    //Impressão dos vetores na ordem normal
    printf("Resultado dos vetores na ordem normal: ");
    MosNum (NumPosi, vetor);

     //Impressão dos vetores na ordem inversa
        printf("Resultado dos vetores na ordem inversa: [");
         for (int i = vetor -1; i >= 0; i--)
         {
           printf("%d", NumPosi[i]);
          if(i>0)
            {   
             printf("_");
            }
         }   
 printf("]\n");
 //Liberando memória alocado para os vetores
 free(NumPosi);
    return 0;
}
 //Vinicius Almeida Fajardo