#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define ATIVIDADE_MAX 100

typedef struct
{
   int horas;
} Atividade;

typedef struct
{
 int matricula;
  char nome[50];
   int ano;
   int contadeativida;
    Atividade atividade[ATIVIDADE_MAX];
} Aluno;

//Tipo de registro e ponteiro para o nó utilizados na árvore ABB
typedef  Aluno Regist;
typedef struct No* Apontador;
//Estrutura do nó
typedef struct No
{
Regist Reg;
Apontador Esq, Dir;
}No;

typedef Apontador Dicionario;
//Função para da start na árvore
void start (Dicionario *Dicionario)
{
 *Dicionario = NULL;
}
//Função para inserir um aluno na árvore
void Insere (Regist x, Apontador *y) 
{
 if (*y == NULL)
    {
    *y = (Apontador) malloc (sizeof(No));
     (*y) -> Reg = x;
      (*y) -> Esq = NULL;
       (*y) -> Dir = NULL;
        return;
    }
    if (x.matricula < (*y) ->Reg.matricula)
    {
     Insere (x, & (*y) -> Esq);
      return;
    }
    if (x.matricula > (*y) ->Reg.matricula)
     Insere (x, & (*y) -> Dir);
      else printf ("Erro: Registro já existente \n");
}
//Função para busca um aluno na árvore
Apontador busca(int matricula, Apontador y) 
{
 if (y == NULL) return NULL;
  if (matricula < y->Reg.matricula)
   return busca(matricula, y->Esq);
   else if (matricula > y->Reg.matricula)
    return busca(matricula, y->Dir);
     else
      return y;
}
//Função para encontrar o menor valor para a esquerda
Apontador Minimo(Apontador y) 
{
 while (y->Esq != NULL)
  y = y->Esq;
   return y;
}
//Função para remover um aluno da árvore
Apontador Remove(int matricula, Apontador y) 
{
 if (y == NULL) return NULL;
  if (matricula < y->Reg.matricula)
   y->Esq = Remove(matricula, y->Esq);
    else if (matricula > y->Reg.matricula)
     y->Dir = Remove(matricula, y->Dir);
    else 
    {
     if (y->Esq == NULL) 
        {
         Apontador temp = y->Dir;
          free(y);
           return temp;
        } 
        else if (y->Dir == NULL) 
        {
         Apontador temp = y->Esq;
          free(y);
           return temp;
        }
        Apontador temp = Minimo(y->Dir);
         y->Reg = temp->Reg;
          y->Dir = Remove(temp->Reg.matricula, y->Dir);
    }
    return y;
}
//Função que percorre a árvore em ordem central e imprime a matrícula
void Central(Apontador y) 
{
 if (y == NULL) return;
  Central(y->Esq);
   printf("Matrícula: %d\n", y->Reg.matricula);
    Central(y->Dir);
}
//Função responsável pela exibição dos alunos e atividades 
void ExibirCentral(Apontador y, int cargaMin) 
{
 if (y == NULL) return;
  ExibirCentral(y->Esq, cargaMin);
   printf("\nAluno: %s (Matrícula: %d, Ingresso: %d)\n", y->Reg.nome, y->Reg.matricula, y->Reg.ano);
    int totalHoras = 0;
    for (int i = 0; i < y->Reg.contadeativida; i++) 
        {
         printf("  Atividade %d: %d horas\n", i + 1, y->Reg.atividade[i].horas);
          totalHoras += y->Reg.atividade[i].horas;
        }
        printf("  Total de horas: %d\n", totalHoras);
         printf("  Situação: %s\n", totalHoras >= cargaMin ? "APROVADO" : "NÃO CUMPRIU a carga mínima");

    ExibirCentral(y->Dir, cargaMin);
}
typedef struct
{
 char nomedcurso[80];
  int cargaHoraTota;
   int cargaMin;
     Apontador alunos;  
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

    start(&curso->alunos);
}

// Função para cadastrar um aluno
void cadAluno(Curso *curso)
{
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

    nalu.contadeativida = 0;
    if (busca(nalu.matricula, curso->alunos) != NULL) 
    {
     printf("\nErro: Já existe um aluno com essa matrícula!\n");
    } 
    else 
    {
     Insere(nalu, &curso->alunos);
      printf("\nCadastro realizado com sucesso!\n");
    }
}

// Função para cadastrar uma atividade
void cadAtivi(Atividade *ativi)
{
 printf("\nInforme a quantidade de total de horas complementares realizadas: ");
  scanf("%d", &ativi->horas);
 getchar();

 printf("\nHoras cadastradas com sucesso!\n");
}

// Função para exibir os dados do curso e dos alunos
void exiDados(Curso curso)
{
 printf("\n=== Dados do Curso ===\n");
  printf("Nome do curso: %s\n", curso.nomedcurso);
   printf("Carga horária total: %d horas\n", curso.cargaHoraTota);
    printf("Carga horária mínima complementar: %d horas\n", curso.cargaMin);
     printf("Nomes dos alunos cadastrados\n");
    ExibirCentral(curso.alunos, curso.cargaMin);
    
    printf("Matrículas dos alunos cadastrados\n");
     Central(curso.alunos);
}
int main()
{
 setlocale(LC_ALL, "Portuguese");
  Curso curso;
   cadcurso(&curso);

   int menu;
    do
    {
     //Menu principal
     printf("\nMENU PRINCIPAL\n");
      printf("Digite - 1 - para cadastrar o estudante\n");
       printf("Digite - 2 - para cadastrar atividades para o estudante\n");
        printf ("Digite - 3 - para excluir um estudante\n");
        printf("Digite - 4 - para exibir os resultados do curso\n");
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

             Apontador y= busca(matricula, curso.alunos);
                 
             if (y != NULL) {
        if (y->Reg.contadeativida < ATIVIDADE_MAX) {
            cadAtivi(&y->Reg.atividade[y->Reg.contadeativida]);
            y->Reg.contadeativida++;
        } else {
            printf("\nNúmero máximo de atividades excedido!\n");
        }
    } else {
        printf("\nAluno não encontrado ou não registrado!\n");
    }
        }
        else if (menu == 3){
           int matricula;
            printf ("\nInforme o número de matrícula do estudante:");
            scanf("%d", &matricula);
            getchar();
            curso.alunos = Remove(matricula, curso.alunos);
            printf("Aluno removido com sucesso!!\n");

        }        
        else if (menu == 4)
        {
          exiDados(curso);
        }

    }
    while (menu != 0);

    return 0;
}
//Vinicius Almeida Fajardo