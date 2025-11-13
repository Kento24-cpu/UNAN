const btnNuevo = document.getElementById("btnNuevo");
const btnAgregar = document.getElementById("btnAgregar");
const btnCancelar = document.getElementById("btnCancelar");

    const nombre = document.getElementById("nombre");
    const apellido = document.getElementById("apellido");
    const carrera = document.getElementById("carrera");
    const sexoRadios = document.getElementsByName("sexo");
    const tbody = document.getElementById("tbody");

    function soloLetras(e) {
      const char = e.key;
      if (!/^[a-zA-ZáéíóúÁÉÍÓÚñÑ\s]$/.test(char)) {
        e.preventDefault();
      }
    }
    nombre.addEventListener("keypress", soloLetras);
    apellido.addEventListener("keypress", soloLetras);

    function habilitarFormulario(habilitar) {
      nombre.disabled = !habilitar;
      apellido.disabled = !habilitar;
      carrera.disabled = !habilitar;
      sexoRadios.forEach(r => r.disabled = !habilitar);
      btnAgregar.disabled = !habilitar;
      btnCancelar.disabled = !habilitar;
      btnNuevo.disabled = habilitar;
    }

    function limpiarCampos() {
      nombre.value = "";
      apellido.value = "";
      carrera.value = "";
      sexoRadios.forEach(r => r.checked = false);
    }

    function existeRegistro(nombre, apellido, carrera) {
      const filas = tbody.querySelectorAll("tr");
      for (let fila of filas) {
        const datos = fila.querySelectorAll("td");
        if (
          datos[0].textContent.toLowerCase() === nombre.toLowerCase() &&
          datos[1].textContent.toLowerCase() === apellido.toLowerCase() &&
          datos[2].textContent.toLowerCase() === carrera.toLowerCase()
        ) {
          return true;
        }
      }
      return false;
    }

    btnNuevo.addEventListener("click", () => {
      habilitarFormulario(true);
      nombre.focus();
    });

    btnCancelar.addEventListener("click", () => {
      if (confirm("¿Seguro que desea cancelar? Los datos no guardados se perderán.")) {
        alert("Registro cancelado.");
        limpiarCampos();
        habilitarFormulario(false);
      }
    });

    btnAgregar.addEventListener("click", () => {
      const sexo = Array.from(sexoRadios).find(r => r.checked)?.value;
      if (!nombre.value.trim() || !apellido.value.trim() || !carrera.value || !sexo) {
        alert("Por favor complete todos los campos.");
        return;
      }

      if (existeRegistro(nombre.value, apellido.value, carrera.value)) {
        alert("Ya existe un registro con los mismos nombres en la misma carrera.");
        return;
      }

      if (!confirm("¿Desea guardar los datos del estudiante?")) {
        limpiarCampos();
        return;
      } else {
        alert("Registro guardado correctamente.");
      }

      const fila = document.createElement("tr");
      fila.innerHTML = `
        <td>${nombre.value.trim()}</td>
        <td>${apellido.value.trim()}</td>
        <td>${carrera.value}</td>
        <td>${sexo}</td>
        <td>
          <button class="eliminar">Eliminar</button>
          <button class="editar">Editar</button>
        </td>
      `;
      tbody.appendChild(fila);

      limpiarCampos();
      habilitarFormulario(false);
    });

    tbody.addEventListener("click", (e) => {
      if (e.target.classList.contains("eliminar")) {
        const fila = e.target.closest("tr");
        const nombre = fila.children[0].textContent;
        const apellido = fila.children[1].textContent;
        const carrera = fila.children[2].textContent;

        if (confirm(`¿Está seguro que desea eliminar a ${nombre} ${apellido} (${carrera})?`)) {
          alert("Resgitro eliminado correctamente.");
          fila.remove();
        }
      }
    });