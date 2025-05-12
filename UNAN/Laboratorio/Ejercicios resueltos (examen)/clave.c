#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nombre[100];
int cve;
float prec_orig, prec_desc;

int main(int argc, char *argv[])
{
	printf("ingrese el nombre de un articulo\n");
	gets(nombre);
	// scanf("%c",&nombre);
	printf("\n ingrese la clave solo se puede tomar dos valores 01 y 02:\n");
	fflush(stdin);
	scanf("%d", &cve);
	printf("\n Introduzca el precio original del articulo:\n");
	fflush(stdin);
	scanf("%f", &prec_orig);
	if (cve == 01)
		prec_desc = (prec_orig - (prec_orig * 0.10));
	else if (cve == 02)
		prec_desc = (prec_orig - (prec_orig * 0.20));
	else
	{
		printf("Clave Invalida\n");
		exit(0);
	}
	printf("\n\n Nombre articulo:%s\n Clave: %d\n", nombre, cve);
	printf("precio original:%.2f\n precio con descuento:%.2f\n", prec_orig, prec_desc);
	return 0;
}
