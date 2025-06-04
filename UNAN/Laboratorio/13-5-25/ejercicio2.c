#include <stdio.h>
#include <math.h>

// Declaración de funciones (prototipos)
double calcularArea(double radio);
double calcularPerimetro(double radio);

int main()
{
    double radio;

    // Solicitar el radio al usuario
    printf("Ingrese el radio del circulo: ");
    scanf("%lf", &radio);

    // Calcular el área y el perímetro
    double area = calcularArea(radio);
    double perimetro = calcularPerimetro(radio);

    // Mostrar los resultados
    printf("El area del circulo es: %.2lf\n", area);
    printf("El perimetro del circulo es: %.2lf\n", perimetro);

    return 0;
}

// Definición de la función calcularArea
double calcularArea(double radio)
{
    return M_PI * radio * radio;
}

// Definición de la función calcularPerimetro
double calcularPerimetro(double radio)
{
    return 2 * M_PI * radio;
}