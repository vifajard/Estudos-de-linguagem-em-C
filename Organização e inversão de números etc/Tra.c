#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ALUNOS 50 
#define ATIVIDADE_MAX 100

typedef struct 
{
 char categoria;
  char descricao[100];
   int horas;
} Atividade;

typedef struct 
{
 int matricula;
  char nome[50];
   int ano;
    int qtddeatividades;
     Atividade atividade[ATIVIDADE_MAX];
} Aluno;

typedef struct 
{
 char nomedcurso[80];
  int cargaHoraTota;
   int cargaMin;
    int qtdAlunos;
     Aluno alunos[MAX_ALUNOS];  
} Curso;

// Função para cadastrar o curso
void cadcurso(Curso *curso) 
{
 printf("Informe o nome do curso: ");
  fgets(curso->nomedcurso, 80, stdin);
   curso->nomedcurso[strcspn(curso->nomedcurso, "\n")] = '\0';

 printf("\nInforme a carga horária total do curso: ");
  scanf("%d", &curso->cargaHoraTota);

 printf("\nInforme a carga horária mínima do curso: ");
  scanf("%d", &curso->cargaMin);
 getchar();

    curso->qtdAlunos = 0;
}

// Função para cadastrar um aluno
void cadAluno(Curso *curso) 
{
    if (curso->qtdAlunos >= MAX_ALUNOS) 
    {
     printf("Erro: Número máximo de alunos atingido!\n");
      return;
    }

  Aluno nalu;
    
  printf("\nInforme o nome do estudante: ");
   fgets(nalu.nome, 50, stdin);
    nalu.nome[strcspn(nalu.nome, "\n")] = '\0';

  printf("\nInforme o número de matrícula do aluno: ");
   scanf("%d", &nalu.matricula);
    getchar();

  printf("\nInforme o ano de ingresso do aluno: ");
   scanf("%d", &nalu.ano);
    getchar();

    nalu.qtddeatividades = 0;
     curso->alunos[curso->qtdAlunos] = nalu;
    curso->qtdAlunos++;

    printf("\nCadastro realizado com sucesso!\n");
}

// Função para cadastrar uma atividade
void cadAtivi(Atividade *ativi) 
{
 printf("\nInforme a categoria da atividade (P-Palestra, C-Curso, V-Trabalho Volunário, S-Seminário, T-Treinamento): ");
 scanf(" %c", &ativi->categoria);
 getchar();

 printf("\nDescrição da atividade: ");
  fgets(ativi->descricao, sizeof(ativi->descricao), stdin);
 ativi->descricao[strcspn(ativi->descricao, "\n")] = '\0';

 printf("\nInforme a quantidade de horas: ");
  scanf("%d", &ativi->horas);
 getchar(); 

 printf("\nAtividade cadastrada com sucesso!\n");
}

// Função para exibir os dados do curso e dos alunos
void exiDados(Curso curso) 
{
 printf("\n=== Dados do Curso ===\n");
  printf("Nome do curso: %s\n", curso.nomedcurso);
   printf("Carga horária total: %d horas\n", curso.cargaHoraTota);
    printf("Carga horária mínima complementar: %d horas\n", curso.cargaMin);
     printf("Número de alunos matriculados: %d\n", curso.qtdAlunos);

    for (int i = 0; i < curso.qtdAlunos; i++) 
    {
      Aluno aluno = curso.alunos[i];
       printf("\nAluno: %s (Matrícula: %d, Ingresso: %d)\n", aluno.nome, aluno.matricula, aluno.ano);

      int totalHoras = 0;
        for (int j = 0; j < aluno.qtddeatividades; j++) 
        {
         Atividade atividade = aluno.atividade[j];
          printf("- [%c] %s (%d horas)\n", atividade.categoria, atividade.descricao, atividade.horas);
         totalHoras += atividade.horas;
        }

         printf("Total de horas cumpridas: %d\n", totalHoras);
        if (totalHoras >= curso.cargaMin) 
        {
         printf("Situação: APROVADO nas atividades complementares!!\n");
        } else 
        {
         printf("Situação: NÃO CUMPRIU a carga horária mínima!!\n");
        }
    }
}
//Função para organizar os alunos por número de mátricula
void InsertionCoin (Curso *curso)
{
    for (int i = 1; i < curso -> qtdAlunos; i++)
    {

     Aluno chave = curso->alunos[i];
      int j = i - 1;
       while (j >= 0 && curso -> alunos[j].matricula > chave.matricula)
        {
            
         curso -> alunos[j + 1] = curso -> alunos[j];
          j--;
        }

        curso -> alunos[j + 1] = chave;

    }

}

int main() 
{
 Curso curso;
  cadcurso(&curso);

   int menu;
    do 
    {
     //Menu principal
     printf("\nMENU PRINCIPAL\n");
      printf("Digite - 1 - para cadastrar o estudante\n");
       printf("Digite - 2 - para cadastrar atividades para o estudante\n");
        printf("Digite - 3 - para exibir os resultados do curso\n");
         printf("Digite - 0 - para sair\n");
          printf("Escolha uma opção listada acima:  ");
           scanf("%d", &menu);
        getchar();

        if (menu == 1) 
        {
            cadAluno(&curso);
        } 
        else if (menu == 2) 
        {
         int matricula, encontrado = 0;
          printf("\nDigite a matrícula do aluno: ");
           scanf("%d", &matricula);
          getchar();

             for (int i = 0; i < curso.qtdAlunos; i++) 
            {
                 if (curso.alunos[i].matricula == matricula) 
                {  
                     if (curso.alunos[i].qtddeatividades < ATIVIDADE_MAX) 
                    {
                     cadAtivi(&curso.alunos[i].atividade[curso.alunos[i].qtddeatividades]);
                      curso.alunos[i].qtddeatividades++;
                    } 
                    else 
                    {
                     //Exibição para caso exceda o número de alunos
                      printf("\nNúmero máximo de atividades excedido!\n");
                    }
                     encontrado = 1;
                      break;
                }
            }

            if (!encontrado) 
            {
             //Exibição para caso não tenha um aluno com o número de mátricula informado
             printf("\nAluno não encontrado ou não registrado!\n");
            }
        } 
        else if (menu == 3) 
        {
          InsertionCoin(&curso);
          exiDados(curso);
        }

    } 
    while (menu != 0);

    return 0;
}
//Vincius Almeida Fajardo