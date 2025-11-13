document.querySelector(".programa1").addEventListener("click", () => {
        // Programa 1
        let bandera = true;
        while (bandera)
        {
                let numP1 = prompt("Escriba un numero:")
                if (!isNaN(numP1) && numP1 != null && numP1 != "" && numP1 >= 0)
                {
                        if (numP1 < 100)
                                alert(`El numero es menor a 100`)
                        else if (numP1 == 100)
                                alert(`El numero es igual a 100`)
                        else
                                alert(`El numero es mayor a 100`)
                        bandera = false
                } else {
                        alert("No es un numero")
                }
        }
})

document.querySelector(".programa2").addEventListener("click", () => {
        // Programa 2
        let calificaciones, suma = 0, i, promedio;
        let bandera;
        for (i = 0; i < 3; i++)
        {
                bandera = true;

                while (bandera)
                {
                        calificaciones = parseInt(prompt(`Nota ${i + 1}:`));
                        if (!isNaN(calificaciones) && calificaciones != null && calificaciones != "" && calificaciones >= 0)
                        {
                                bandera = false;
                        } else {
                                alert("No es un numero")
                        }
                }

                suma += calificaciones;
        }

        promedio = suma / 3;

        if (promedio < 60)
                alert(`El estudiante reprobo la clase con: ${promedio}`);
        else
                alert(`El estudiante aprobo la clase con: ${promedio}`);
})

document.querySelector(".programa3").addEventListener("click", () => {
        // Programa 3
        let precio = 0, total, suma = 0, bandera = true, cantidadCamisas, descuento;
        while (bandera)
        {
                cantidadCamisas = parseInt(prompt("Cantidad de camisas a llevar:"));
                if (!isNaN(cantidadCamisas) && cantidadCamisas != null && cantidadCamisas != "" && cantidadCamisas >= 0)
                {
                        bandera = false;
                } else {
                        alert("Error, intentelo de nuevo.")
                }
        }

        bandera = true;

        while (bandera)
        {
                precio = parseInt(prompt(`Precio de las camisas:`));
                if (!isNaN(precio) && precio != null && precio != "" && precio >= 0)
                {
                        bandera = false;
                } else {
                        alert("Debe ser un numero mayor a 0");
                }
        }

        suma = cantidadCamisas * precio;

        if (cantidadCamisas < 12)
        {
                descuento = suma * 0.1;
                total = Math.round(suma - descuento, 2)
                alert(`Total de la compra: ${suma}
                \nDescuento aplicado: ${descuento}
                \nTotal de la compra con descuento: ${total}
                `)
        } else {
                descuento = suma * 0.2;
                total = Math.round(suma - descuento, 2)
                alert(`Total de la compra: ${suma}
                \nDescuento aplicado: ${descuento}
                \nTotal de la compra con descuento: ${total}
                `)
        }
})

document.querySelector(".programa4").addEventListener("click", () => {
        // Programa 4
        let salario = 0, totalHorasExtras, totalHorasTrabajadas, bandera = true, horasTrabajadas, horasExtras;

        while (bandera)
        {
                horasTrabajadas = parseInt(prompt("Horas trabajadas:"));
                if (!isNaN(horasTrabajadas) && horasTrabajadas != null && horasTrabajadas != "" && horasTrabajadas >= 0)
                {
                        bandera = false;
                } else {
                        alert("No es un numero")
                }
        }

        while (bandera)
        {
                horasExtras = parseInt(prompt("Horas extras trabajadas:"));
                if (!isNaN(horasExtras) && horasExtras != null && horasExtras != "")
                {
                        bandera = false;
                } else {
                        bandera = true;
                }
        }

        totalHorasTrabajadas = horasTrabajadas * 20;

        if (horasExtras > 0)
        {
                totalHorasExtras = horasExtras * 25;
                salario = totalHorasTrabajadas + totalHorasExtras;
                alert(`El salario del obrero es de: ${salario}`)
        } else {
                alert(`El salario del obrero es de: ${totalHorasTrabajadas}`);
        }
})

document.querySelector(".programa5").addEventListener("click", () => {
        let numeros, suma = 0;
        let bandera;
        for (let i = 0; i < 5; i++)
        {
                bandera = true;

                while(bandera)
                {
                        numeros = parseInt(prompt(`Numero ${i + 1}:`));
                        if(!isNaN(numeros) && numeros != null && numeros != "" && numeros >= 0)
                        {
                                if(numeros[i] <= 0) i--;
                                bandera = false;
                        } else {
                                alert("No es un numero")
                        }
                }
                suma += numeros;
        }
        alert(`La suma de los numeros es: ${suma}`);
})

document.querySelector(".programa6").addEventListener("click", () => {
        let suma = 0;
        for (let i = 1; i < 101; i++)
        {
                if (i % 2 == 0)
                {
                        suma += i;
                }
        }
        alert(`Suma de los numeros: ${suma}`)
})

document.querySelector(".programa7").addEventListener("click", () => {
        let bandera = true;
        while(bandera)
        {
                let numero = prompt("Numero para la tabla:");
                document.write(`Tabla del ${numero}: <br>`)
                if(!isNaN(numero) && numero != null && numero != "" && numero >= 0)
                        for (let i = 0; i < 12; i++)
                        {
                                document.write(`${numero} X ${i + 1} = ${parseInt(numero) * parseInt((i + 1))} <br>`)
                                bandera = false;
                        }
                else {
                        alert("No es un numero")
                }
        }
})

document.querySelector(".programa8").addEventListener("click", () => {
        let bandera = true;
        while(bandera)
        {
                let numero = parseInt(prompt("Numero:"))
                if(!isNaN(numero) && numero != null && numero != "" && numero >= 0)
                {
                        console.log(numero)
                        while (numero != 1)
                        {
                                if (numero % 2 == 0)
                                {
                                        numero = numero / 2;
                                } else {
                                        numero = (numero * 3) + 1
                                }
                                console.log(numero)
                        }
                        bandera = false;
                } else {
                        alert("No es un numero")
                }
        }
})

document.querySelector(".programa9").addEventListener("click", () => {
        let factorial = 1, i;
        for (i = 1; i <= 5; i++)
        {
                factorial = factorial * i
                document.write(`Factorial de ${i}: ${factorial}<br>`)
        }

})

document.querySelector(".programa10").addEventListener("click", () => {
        let fibonacci = [], suma = 0;
        fibonacci[0] = 0;
        fibonacci[1] = 1;

        suma = fibonacci[0] + fibonacci[1];
        for (let i = 2; i < 50; i++)
        {
                fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
                suma += fibonacci[i]
        }
        document.write(`La suma de los numeros de Fobinacci es: ${fibonacci} <br>`)
})
