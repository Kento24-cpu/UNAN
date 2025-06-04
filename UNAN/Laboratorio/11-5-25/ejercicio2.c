// Leer 50 calificaciones de un grupo de alumnos calcule y escriba el porcentaje de reprobados.
// Tomando en cuenta que la calificación mínima aprobatoria es de 70

#include <stdio.h>
#include <stdio.h>

int main()
{

    const int NUMERO_CALIFICACIONES = 5;
    const int CALIFICACION_MINIMA_APROBATORIA = 70;
    const int CALIFICACION_MAXIMA_POSIBLE = 100;
    const int CALIFICACION_MINIMA_POSIBLE = 0;

    float calificacion_actual;
    int contador_alumnos = 0;
    int alumnos_reprobados = 0;
    float porcentaje_reprobados;

    printf("Por favor, ingrese las %d calificaciones del grupo de alumnos.\n", NUMERO_CALIFICACIONES);
    printf("La calificacion minima aprobatoria es %d.\n", CALIFICACION_MINIMA_APROBATORIA);
    printf("Las calificaciones deben estar entre %d y %d.\n\n", CALIFICACION_MINIMA_POSIBLE, CALIFICACION_MAXIMA_POSIBLE);

    if (NUMERO_CALIFICACIONES <= 0)
    {
        printf("No hay calificaciones que procesar.\n");
        return 0;
    }

    do
    {
        printf("Ingrese la calificacion del alumno %d: ", contador_alumnos + 1);

        int scanf_result;
        do
        {
            scanf_result = scanf("%f", &calificacion_actual);

            while (getchar() != '\n')
                ;

            if (scanf_result != 1)
            {
                printf("Entrada invalida. Por favor, ingrese un numero: ");
            }
            else if (calificacion_actual < CALIFICACION_MINIMA_POSIBLE || calificacion_actual > CALIFICACION_MAXIMA_POSIBLE)
            {
                printf("Calificacion fuera de rango. Ingrese un valor entre %d y %d: ", CALIFICACION_MINIMA_POSIBLE, CALIFICACION_MAXIMA_POSIBLE);
            }
        } while (scanf_result != 1 || calificacion_actual < CALIFICACION_MINIMA_POSIBLE || calificacion_actual > CALIFICACION_MAXIMA_POSIBLE);

        if (calificacion_actual < CALIFICACION_MINIMA_APROBATORIA)
        {
            alumnos_reprobados++;
        }

        contador_alumnos++;

    } while (contador_alumnos < NUMERO_CALIFICACIONES);

    if (NUMERO_CALIFICACIONES > 0)
    {
        porcentaje_reprobados = ((float)alumnos_reprobados / NUMERO_CALIFICACIONES) * 100.0f;
    }
    else
    {

        porcentaje_reprobados = 0.0f;
    }

    printf("\n--- Resultados del Grupo ---\n");
    printf("Total de alumnos evaluados: %d\n", NUMERO_CALIFICACIONES);
    printf("Cantidad de alumnos reprobados: %d\n", alumnos_reprobados);
    printf("Porcentaje de alumnos reprobados: %.2f%%\n", porcentaje_reprobados);

    return 0;
}