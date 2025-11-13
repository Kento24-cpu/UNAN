let formData = [];
let posicion = -1;

const nombre = document.getElementById("name");
const apellido = document.getElementById("surname");
const opciones = document.getElementById("options");
const sexo = document.getElementsByName("sexo");
const egresado = document.getElementById("egresado");

const newBtn = document.getElementById("newBtn");
const saveBtn = document.getElementById("saveBtn");
const cancelBtn = document.getElementById("cancelBtn");
const deleteBtn = document.getElementById("deleteBtn");

const primero = document.getElementById("primero");
const anterior = document.getElementById("anterior");
const siguiente = document.getElementById("siguiente");
const ultimo = document.getElementById("ultimo");

function disableInput(block = true) {
  nombre.disabled = block;
  apellido.disabled = block;
  opciones.disabled = block;
  sexo.forEach((radio) => {
    radio.disabled = block;
  });
  egresado.disabled = block;
  saveBtn.disabled = block;
  if (formData.length === 0) {
    deleteBtn.disabled = block;
  }
}

function clearForm() {
  nombre.value = "";
  apellido.value = "";
  opciones.value = "none";
  sexo.forEach((radio) => {
    radio.checked = false;
  });
  egresado.checked = false;
}

function viewData(i) {
  if (i < 0 || i >= formData.length) return;
  const data = formData[i];

  nombre.value = data.nombre;
  apellido.value = data.apellido;
  opciones.value = data.opciones;
  sexo.forEach((radio) => (radio.checked = radio.value === data.sexo));
  egresado.checked = data.egresado;
  posicion = i;
}

function view() {
  let buscar = document.getElementById("search").value;
  let nombre = formData[buscar].nombre
  let apellido = formData[buscar].apellido
  let opciones = formData[buscar].opciones
  let sexo = formData[buscar].sexo
  let egresado = formData[buscar].egresado

  let cadenaVisualizar = `Nombre: ${nombre}
  <br>Apellido: ${apellido}
  <br>Opciones: ${opciones}
  <br>Sexo: ${sexo}
  <br>Egresado: ${egresado}`

  let visualizar = getElementById("visualizar")
  visualizar.innerHTML = cadenaVisualizar
}

newBtn.onclick = () => {
  clearForm();
  disableInput(false);
};

cancelBtn.onclick = () => {
  disableInput(true);
  if (formData.length > 0) {
    viewData(formData.length - 1);
  } else {
    clearForm();
  }
};

saveBtn.onclick = () => {
  const pattern = new RegExp("^[a-zA-Z]+$");
  const data = {
    nombre: nombre.value.trim(),
    apellido: apellido.value.trim(),
    opciones: opciones.value,
    sexo: [...sexo].find((radio) => radio.checked)?.value || "",
    egresado: egresado.checked,
  };

  if (!data.nombre || !data.apellido || !data.opciones || !data.sexo) {
    alert("Complete todos los campos para continuar.");
    return;
  }

  if (!pattern.test(data.nombre) || !pattern.test(data.apellido)) {
    alert("Caracter invalido");
    clearForm();
    return;
  }

  resp = confirm("Desea guardar los datos?");
  if (!resp) {
    clearForm();
  }

  if (resp) {
    alert("Registro guardado correctamente.");
    formData.push(data);
    posicion = formData.length - 1;
  } else {
    alert("Registro cancelado.");
    viewData(formData.length - 1);
  }

  disableInput(true);
};

deleteBtn.onclick = () => {
  resp = confirm("Esta seguro de eliminar los datos?");
  if (resp) {
    alert("Registro eliminado correctamente.");
    if (posicion >= 0 && formData.length > 0) {
      formData.splice(posicion, 1);
      if (formData.length === 0) {
        clearForm();
        posicion = -1;
      } else if (posicion >= formData.length) {
        viewData(formData.length - 1);
      } else {
        viewData(posicion);
      }
    }
  } else {
    alert("Registro cancelado.");
    viewData(formData.length - 1);
  }
};

primero.onclick = () => {
  if (formData.length) viewData(0);
};

ultimo.onclick = () => {
  if (formData.length) viewData(formData.length - 1);
};

anterior.onclick = () => {
  if (posicion > 0) viewData(posicion - 1);
};

siguiente.onclick = () => {
  if (posicion < formData.length - 1) viewData(posicion + 1);
};

buscarBtn.onclick = () => {
  const nameSearched = search.value.trim();

  if (!nameSearched) {
    alert("Ingrese un nombre en el campo.");
    return;
  }

  const index = formData.findIndex((item) =>
    item.nombre.includes(nameSearched)
  );

  if (index !== -1) {
    viewData(index);
    if (formData.length === 0) {
      clearForm();
      posicion = -1;
    } else if (posicion >= formData.length) {
      viewData(formData.length - 1);
    } else {
      viewData(posicion);
    }
  } else {
    alert("No existen coincidencias en el registro.");
  }
};

disableInput(true);
