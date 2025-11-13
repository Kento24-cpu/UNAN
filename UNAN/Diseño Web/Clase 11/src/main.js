// Programa 1
let nombre = prompt("Nombres:");
let apellidos = prompt("Apellidos:");

alert(`Tu nombre completo es: ${nombre} ${apellidos}`);

// Programa 2
let num = prompt("Numero 1:");
let num1 = prompt("Numero 2:");
let suma = parseInt(num) + parseInt(num1);
let resta = num - num1;
let multi = num * num1;
let div = num / num1;

alert(`Suma: ${suma}\nResta: ${resta}\nMultiplicacion: ${multi}\nDivision: ${div}\n`);

// Programa 3
let numero = prompt("Numero:");
let aleatorio = Math.floor(Math.random(), 0);
let resultado = numero * aleatorio;

alert(`El resultado de la multiplicacion es: ${resultado}`);

// Programa 4
let numero1 = prompt("Numero 1:");
let numero2 = prompt("Numero 2:");
let elevado = Math.pow(numero1, numero2);

alert(`El resultado es: ${elevado}`)

// Programa 5
let cadena = prompt("Escriba su texto:");
let cadena1 = prompt("Escriba su otro texto:");

alert(`${cadena.toUpperCase()}, ${cadena1.toLowerCase()}`);
