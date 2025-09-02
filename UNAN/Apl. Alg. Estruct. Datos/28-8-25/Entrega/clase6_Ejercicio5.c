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