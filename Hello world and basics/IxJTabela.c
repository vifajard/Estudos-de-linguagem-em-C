#include <stdio.h>
#include <stdlib.h>
int notas = 3;
int alunos = 5;
float tabela [5] [3];
int i, j;

int main()
{
float tabela [alunos] [notas];

for(i = 0; i < alunos; i++){
for (j = 0; j < notas; j++ ){
printf ("Digite a nota %d do aluno %d\n", j + 1, i + 1);
scanf("%f", &tabela[i][j]);
}
}
printf ("\nNotas dos Alunos\n");
for(i = 0; i < alunos; i++){
printf("Aluno %d", i + 1 );
  for(j = 0; j < notas; j++){
printf ("%6.2f", tabela[i][j]);
}
printf("\n");
}
return 0;
}