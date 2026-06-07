#include <stdio.h>
#include <stdlib.h>

int main()
{
int voto = 0;
int bul = 0;
int cha = 0;
int squi = 0;
int pi = 0 ;
int branco = 0 ;
int nulo = 0 ;
int votovali = 0 ; 
int vototota = 0;
char vencedor [20];
int votoven;
float porpi, porsqui, porbul, porcha;
printf ("Bem vindo às eleições da cidade de Kanto!\n");
do
{
 printf ("Escolha o seu candidato:\n");
 printf ("1 - Bulbassauro\n");
 printf ("4 - Charmander\n");
 printf ("7 - Squirtle\n");
 printf ("25 - Pikachu\n");
 printf ("0 - Voto em Branco\n");
 printf ("Para votar nulo digite qualquer número diferente dos acima\n");
 printf (" Ou digite -42 para sair da votação\n");
 scanf ("%d" , &voto);

if (voto == -42)
    {
        break;
    }
else if (voto == 1)
    {
     bul++;
     votovali++;
    }
else if (voto == 4)
    {
     cha++;
     votovali++;
    }
else if (voto == 7)
    {
     squi++;
     votovali++;
    }
else if (voto == 25)
    {
     pi++;
     votovali++;
    }
else if (voto == 0)
    {
     branco++;
    }
else 
{
    nulo++;
}
vototota++;

} while (vototota < 2000);
{
if (votovali > 0) {
    porbul = (bul * 100.0) / votovali;
    porcha = (cha * 100.0) / votovali;
    porsqui = (squi * 100.0) / votovali;
    porpi = (pi * 100.0) / votovali;
} else {
    porbul = porcha = porsqui = porpi = 0.0;
}

}
    printf("\nResultados da eleição:\n");
    printf("Bulbassauro: %d votos (%.2f%%)\n", bul, porbul);
    printf("Charmander: %d votos (%.2f%%)\n", cha, porcha);
    printf("Squirtle: %d votos (%.2f%%)\n", squi, porsqui);
    printf("Pikachu: %d votos (%.2f%%)\n", pi, porpi);
    printf("Votos em Branco: %d\n", branco);
    printf("Votos Nulos: %d\n", nulo);

votoven = bul;
strcpy(vencedor, "Bulbassauro");

if (cha > votoven) {
    votoven = cha;
    strcpy(vencedor, "Charmander");
}
if (squi > votoven) {
    votoven = squi;
    strcpy(vencedor, "Squirtle");
}
if (pi > votoven) {
    votoven = pi;
    strcpy(vencedor, "Pikachu");
}

printf ("O candidato vencedor e o %s com total de %d votos validos\n", vencedor, votoven);

 return 0;

}