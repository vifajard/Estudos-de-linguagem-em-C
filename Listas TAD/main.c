#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "Lista.h"
#include "Lista.c"

int main()
{
setlocale(LC_ALL, "Portuguese");
Curso curso;
  curso.ini = NULL;
cadcurso(&curso);

   int menu;
    do
    {
     //Menu principal
     printf("\nMENU PRINCIPAL\n");
      printf("Digite - 1 - para cadastrar o estudante\n");
       printf("Digite - 2 - para remover o estudante\n");
       printf("Digite - 3 - para fazer iniciar a busca por um aluno\n");
        printf("Digite - 4 - para exibir os alunos do curso\n");
         printf("Digite - 0 - para sair\n");
          printf("Escolha uma das opções listadas acima:");
           scanf("%d", &menu);
        getchar();

        if (menu == 1)
        {
           int matricula, ano;
           char nome[50];
            printf("Informe o número de mátricula do estudante: ");
            scanf("%d", &matricula);
            getchar();
            printf("Insira o nome do estudante: ");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            printf("Informe o ano de ingresso: ");
            scanf("%d", &ano);
            addaluno(&curso, matricula, nome, ano);
        }
        else if (menu == 2)
        {
         int matricula;
            printf("Informe o número de mátricula do estudante:\n");
         scanf("%d", &matricula);
         removaluno(&curso, matricula);
        }
        else if (menu == 3)
        {
         int matricula;
            printf("Informe o número de mátricula do aluno para iniciar a busca: \n");
         scanf("%d", &matricula);
         Aluno *aluno = buscaalu (&curso, matricula);
         if (aluno != NULL){
         printf("Aluno encontrado: \nMatricula:%d, \nNome:%s, \nAno de ingresso:%d", aluno -> matricula, aluno -> nome, aluno -> ano);
        }
        else{
            printf("ERROR:(Aluno não encontrado ou registrado)\n");
        }
        }
        else if (menu == 4){
            exiDados(&curso);
        }
else if (menu!= 0){
    printf("Opção digitada inváilida, por favor digite uma das citadas acima: \n");
}

    }
    while (menu != 0);

    limpalista(&curso);
    printf("Programa finalizado!");
    return 0;
}
//Vincius Almeida Fajardo
