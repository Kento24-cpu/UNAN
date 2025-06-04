sprintf(estudiante1.carnet, "%02d-%05d-%01d",
            carnet_numerico / 1000000,          // Los primeros 2 dígitos
            (carnet_numerico / 10) % 100000,    // Los siguientes 5 dígitos
            carnet_numerico % 10);              // El último dígito