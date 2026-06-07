#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Função para cadastrar o curso
void cadcurso(Curso *curso)
{
 printf("Informe o nome do curso: ");
  fgets(curso->nomedcurso, 80, stdin);
   curso->nomedcurso[strcspn(curso->nomedcurso, "\n")] = '\0';
 getchar();
 printf("Informe o tempo máximo do curso: ");
 scanf("%d", &(curso -> tempomax));
 printf("Informe o tempo mínimo do curso: ");
 scanf("%d", &(curso -> tempomin));
getchar();
curso -> totaaluno = 0;
curso -> ini = NULL;
}

  Aluno* crialu(int matricula, char nome[] , int ano)        
  {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
  if (novoAluno == NULL)
  {
    printf("ERROR\n");
  return NULL;
}
novoAluno->matricula = matricula;
strcpy(novoAluno->nome, nome);
novoAluno->ano = ano;
novoAluno->proximo = NULL;
return novoAluno;
}

void addaluno(Curso *curso, int matricula, char nome[], int ano)
{
Aluno* novoAluno = crialu(matricula, nome, ano);
if (novoAluno == NULL)
{
    printf("Erro ao alocar mémoria");
    return;
}
novoAluno->proximo = curso->ini;
curso->ini = novoAluno;
curso -> totaaluno++;
printf("Aluno cadastrado com sucesso!!\n");
}

void removaluno(Curso *curso, int matricula)
{
    Aluno *atualu = curso->ini, *anterior = NULL;
    while (atualu != NULL && atualu->matricula != matricula) {
        anterior = atualu;
        atualu = atualu->proximo;
    }

    if (atualu == NULL) {
        printf("Aluno não encontrado!\n");
        return;
    }

    if (anterior == NULL) {
        curso->ini = atualu->proximo;
    } else {
        anterior->proximo = atualu->proximo;
    }

    free(atualu);
    curso->totaaluno--;
    printf("Aluno removido com sucesso!\n");
}


Aluno* buscaalu(Curso *curso, int matricula)
{
Aluno *atualu = curso -> ini;
while(atualu != NULL){
  if(atualu -> matricula == matricula){
  return atualu;
}
atualu = atualu -> proximo;
}
return NULL;
}
// Função para exibir os dados do curso e dos alunos
void exiDados(Curso *curso)
{
  printf("DADOS DO CURSO\n");    
  printf("Nome do curso: %s\n", curso -> nomedcurso);
  printf("Tempo máximo de curso: %d\n", curso -> tempomax);
  printf("Tempo mínimo de curso: %d\n", curso -> tempomin);
  printf("Total de alunos do curso: %d\n", curso -> totaaluno);

printf("Alunos Matriculados: \n");
  Aluno *atualu = curso -> ini;

  while (atualu != NULL) {
    printf("Matrícula: %d, Nome: %s, Ano de Ingresso: %d\n",
           atualu->matricula, atualu->nome, atualu->ano);
    atualu = atualu->proximo;
}
}

void limpalista(Curso *curso)
{
Aluno* atualu = curso -> ini;
while (atualu != NULL) {
  Aluno *temp = atualu;
  atualu = atualu->proximo;
  free(temp);
}
curso->ini = NULL;
}