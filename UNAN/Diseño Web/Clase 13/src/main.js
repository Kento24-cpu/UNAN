const arrayDatos = [];

function saveInfo()
{
        let nombre = document.getElementById("name").value;
        let apellido = document.getElementById("surname").value;
        let correo = document.getElementById("email").value;
        let sexo = document.querySelector('input[name="sexo"]:checked').value;
        let condiciones = document.getElementById("conditions").checked;
        let opciones = document.getElementById("selection");
        let opcionSeleccionada = opciones.options[opciones.selectedIndex].text;

        console.log(`Nombre: ${nombre}
                \nApellido: ${apellido}
                \nCorreo: ${correo}
                \nSexo: ${sexo}
                \nCondiciones: ${condiciones}
                \nOpcion Seleccionada: ${opcionSeleccionada}
                `)

        resp = confirm("Desea guardar los datos?");

        if(resp)
        {
                let nuevoElemento = [];
                nuevoElemento.push(nombre);
                nuevoElemento.push(apellido);
                nuevoElemento.push(correo);
                nuevoElemento.push(sexo);
                nuevoElemento.push(condiciones);
                nuevoElemento.push(opcionSeleccionada);

                arrayDatos.push(nuevoElemento);
                document.getElementById("formulario").reset();
        }

        return false;
}