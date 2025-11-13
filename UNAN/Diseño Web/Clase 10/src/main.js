document.querySelector(".black").addEventListener("click", () => {
        document.body.style.backgroundColor = "black";
        document.body.style.color = "white";
})

document.querySelector(".white").addEventListener("click", () => {
        document.body.style.backgroundColor = "white"
        document.body.style.color = "black";
})

document.querySelector(".hidden").addEventListener("click", () => {

})

let string1 = "Esta es una cadena de texto pero mas larga"
let string = "Esta es una cadena de texto";

console.log(`La cadena es: ${string1.toUpperCase()}\nTiene una longitud de ${string1.length} caracteres`)
alert(`La cadena es: ${string.toUpperCase()}\nTiene una longitud de ${string.length} caracteres`)