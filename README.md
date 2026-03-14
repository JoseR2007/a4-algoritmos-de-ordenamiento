# A4: Algoritmos de ordenamiento y busqueda
1. Algoritmos de búsquedas y ordenamiento.
  - Ordenamiento:
    - Burbuja.
    - Inserción.
    - Selección.
    - Shell.
    - QuickSort.
  - Búsqueda:
    - Secuencial.
    - Binaria.
2. Puntero a funciones – Aplicaciones.

## ¿Cómo utilizar menu()?
La función menu(), es una de las funciones principales del programa, la misma se encarga de manejar el menu interactivo que aparece en pantalla al
ejecutar el programa.

**Prototipo:**
`int menu (const char *title, char *opciones[], int cant_opciones, int posx, int posy)`

La función devuelve un entero que indica la posición del usuario dentro del menú.
Recibe 5 parametros detallado a continuación:
- `const char *title`:
  Este parametro indica el titúlo que parecera en la parte superior del menú (no es seleccionable), este parametro puede ser enviado a la funcion
  como una cadena directamente entre comillas, ejemplo: `menu("este es el titulo", ...)`.

- `char *opciones[]`:
  Este parametro indica las opciones que apareceran en el menú (estas sí son seleccionables), se espera que las envies como un arreglo de cadenas que
  defines previamente, observe dentro del programa como se hace una llamada a esta función y se pasa `char *opciones[] = {"Ordenamiento", ...}` como parametro
  de opciones.

- `int cant_opciones`:
  Este parametro indica la cantidad de opciones que fueron enviadas a la función, *esta cantidad debe ser enviada contando desde el 1* NO desde el cero.
  En otras palabras, indica la cantidad de cadenas de caracteres dentro del arreglo `opciones[]` que se mencionó previamente.

- `int posx` y `int posy`:
  Estos parametros van de la mano. Componen la posición del menú en la consola indicado dentro del eje X (horizontal) y eje Y (vertical).
  Estos paramtros son utilizados con gotoxy(), envielos tomando en cuenta esto.