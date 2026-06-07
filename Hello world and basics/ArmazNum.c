#include <stdio.h>
#include <stdlib.h>
int numeros[10];

int main()
{

for(int i = 0; i < 10; i++)
{
printf("Digite o %d numero de 10, ele tem que ser inteiros: \n", i + 1);
scanf("%d", &numeros[i]);
}
printf("\nEsses são os numeros digitados:\n");
for(int i = 0; i < 10; i++){
printf("%d, ", numeros[i]);
}
return 0;
}