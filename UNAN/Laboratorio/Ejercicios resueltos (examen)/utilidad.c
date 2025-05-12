#include <stdio.h>

int antig;
float sm,util;
int main(int argc, char *argv[]) {
	printf("Ingrese Salario Mensual");
	scanf("%f",&sm);
	printf("ingrese su antiguedad");
	scanf("%d",&antig);
	if(antig<=1)
		util=sm*0.05;
	else if((antig>1) && (antig<=2))
		util=sm*0.07;
	else if ((antig>2) && (antig<=5))
		util=sm*0.07;
	else if((antig>5) && (antig<=10))
		util=sm*0.15;
	else 
		util=sm*0.20;
	printf("Utilidad=%.2f\n",util);
	return 0;
}

