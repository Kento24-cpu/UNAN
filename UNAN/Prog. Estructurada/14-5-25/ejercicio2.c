#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int main()
{
    int horas, minutos, segundos;

    system("clear");

    for (horas = 0; horas < 24; horas++)
    {
        for (minutos = 0; minutos < 60; minutos++)
        {
            for (segundos = 0; segundos < 60; segundos++)
            {
                printf("%02d:%02d:%02d\n", horas, minutos, segundos);

                // Sleep(1000);

                // system("clear");
            }
        }
    }

    return 0;
}