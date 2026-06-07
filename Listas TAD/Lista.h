#ifndef LISTA_H
#define LISTA_H
//Estrutura de aluno
typedef struct Aluno 
   {
    int matricula;
     char nome[50];
      int ano;
       struct Aluno *proximo; //Ponteiro para indicar o próximo aluno
   } Aluno;
//Estrutura de curso
typedef struct Curso
   {
    char nomedcurso[80];
     int tempomax;
      int tempomin;
       int totaaluno;
        Aluno *ini; //Ponteiro para indicar o primeiro aluno da lista
   } Curso;

   void cadcurso(Curso *curso);
    void addaluno(Curso *curso, int matricula, char nome[] , int ano);
     void removaluno(Curso *curso, int matricula);
      Aluno* buscaalu(Curso *curso, int matricula);
       void exiDados(Curso *curso);
        void limpalista(Curso *curso);

#endif
//Vincius Almeida Fajardo