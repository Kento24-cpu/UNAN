// Elaborar un programa que registre datos en las estructuras propuestas y para finalizar de
// registrar digitará la palabra FIN. Luego mostrara los datos registrados, el programa utilizara lo
// siguiente:

// Dos estructuras:
// typedef struct
// { int dia;
// int mes;
// int anno;
// }fecha;

// typedef struct
// { char nombre[80];
// char calle[80];
// char ciudad[80];
// int cuen_no;
// char cuen_tipo;
// float anteriorsaldo;
// float nuevosaldo;
// float pago;
// fecha ultimopago;
// }registro;

// Dos funciones
// registro leerpantalla(registro cliente);
// void escribirarchivo(registro cliente);

// Fragmento
// FILE *fpt;
// main()
// {
// int indicador=CIERTO;
// registro cliente;
// registro leerpantalla(registro cliente);
// void escribirarchivo(registro cliente);
// fpt=fopen("registro.dat","w");
// printf("SISTEMA DE CUENTA DE CLIENTES - INICIALIZACION\n\n");
// CONTINUAR………………….

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de las estructuras
typedef struct
{
        int dia;
        int mes;
        int anno;
} fecha;

typedef struct
{
        char nombre[80];
        char calle[80];
        char ciudad[80];
        int cuen_no;
        char cuen_tipo;
        float anteriorsaldo;
        float nuevosaldo;
        float pago;
        fecha ultimopago;
} registro;

// Declaración de las funciones
registro leerpantalla();
void escribirarchivo(registro cliente, FILE *fpt);
void mostrarRegistros(FILE *fpt);

int main()
{
        FILE *fpt;
        registro cliente;

        // Abrir el archivo en modo de escritura binaria
        fpt = fopen("registro.dat", "wb");
        if (fpt == NULL)
        {
                perror("Error al abrir el archivo para escritura");
                return 1;
        }

        printf("SISTEMA DE CUENTA DE CLIENTES - INICIALIZACION\n\n");

        // Bucle para leer datos de clientes hasta que se ingrese "FIN"
        do
        {
                cliente = leerpantalla();
                if (strcmp(cliente.nombre, "FIN") != 0)
                {
                        escribirarchivo(cliente, fpt);
                }
        } while (strcmp(cliente.nombre, "FIN") != 0);

        // Cerrar el archivo después de escribir todos los registros
        fclose(fpt);

        printf("\nRegistros guardados en 'registro.dat'.\n\n");

        // Abrir el archivo en modo de lectura binaria para mostrar los datos
        fpt = fopen("registro.dat", "rb");
        if (fpt == NULL)
        {
                perror("Error al abrir el archivo para lectura");
                return 1;
        }

        // Mostrar los registros en la pantalla
        mostrarRegistros(fpt);

        // Cerrar el archivo
        fclose(fpt);

        return 0;
}

registro leerpantalla()
{
        registro cliente;
        printf("Ingresa el nombre del cliente (o 'FIN' para terminar): ");
        scanf(" %79s", cliente.nombre);

        if (strcmp(cliente.nombre, "FIN") == 0)
        {
                return cliente;
        }

        printf("Calle: ");
        scanf(" %79s", cliente.calle);

        printf("Ciudad: ");
        scanf(" %79s", cliente.ciudad);

        printf("Numero de cuenta: ");
        scanf("%d", &cliente.cuen_no);

        printf("Tipo de cuenta (A/B/C): ");
        scanf(" %c", &cliente.cuen_tipo);

        printf("Saldo anterior: ");
        scanf("%f", &cliente.anteriorsaldo);

        printf("Nuevo saldo: ");
        scanf("%f", &cliente.nuevosaldo);

        printf("Pago: ");
        scanf("%f", &cliente.pago);

        printf("Fecha de ultimo pago (dd mm aaaa): ");
        scanf("%d %d %d", &cliente.ultimopago.dia, &cliente.ultimopago.mes, &cliente.ultimopago.anno);

        return cliente;
}

void escribirarchivo(registro cliente, FILE *fpt)
{
        fwrite(&cliente, sizeof(registro), 1, fpt);
}

void mostrarRegistros(FILE *fpt)
{
        registro cliente;
        printf("LISTADO DE CLIENTES REGISTRADOS\n");
        printf("----------------------------------\n");

        while (fread(&cliente, sizeof(registro), 1, fpt) == 1)
        {
                printf("\nNombre: %s\n", cliente.nombre);
                printf("Calle: %s\n", cliente.calle);
                printf("Ciudad: %s\n", cliente.ciudad);
                printf("Cuenta No.: %d\n", cliente.cuen_no);
                printf("Tipo de cuenta: %c\n", cliente.cuen_tipo);
                printf("Saldo anterior: %.2f\n", cliente.anteriorsaldo);
                printf("Nuevo saldo: %.2f\n", cliente.nuevosaldo);
                printf("Pago: %.2f\n", cliente.pago);
                printf("Ultimo pago: %d/%d/%d\n", cliente.ultimopago.dia, cliente.ultimopago.mes, cliente.ultimopago.anno);
        }
}