#include <stdlib.h>
#include <stdio.h>
#include <conio.c>
#include <string.h>
#include <ctype.h>

// Constantes:
#define CANT_OPCIONES_MENU_MAIN 3
#define CANT_OPCIONES_MENU_ORDE 5
#define CANT_OPCIONES_MENU_BUSQUEDA 3
#define PADDING_MENU 2
#define POS_INI_Y 1
#define POS_INI_X 1
#define ORDENAMIENTO_OPCION 0
#define BUSQUEDA_OPCION 1
#define PATH_SAVE "palabras.bin"

// Teclas de control:
#define ESC 27
#define ENTER 13
#define FLECHA 224
#define BACKSPACE 8

// Teclas de movimiento:
#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75

// Colores:
#define BLACK 0
#define BLUE 1
#define YELLOW 14
#define WHITE 15
#define LIGHTGRAY 7

int menu(const char *, char *[], int, int, int);
void show_menu(const char *, char *[], int, int, int, int);
void cargar_cadenas (char **[], int *);
int comparar_str(char *, char *);

// Algoritmos de ordenamiento:
void quick_sort(char *[], int, int);
void shell_sort(char *[], int);
int partition(char *[], int, int);

// Algortimo de busqueda:
int binary_search(char *[], int, char *);

// Funciones de color:
void set_color(int, int);
void color_default(void);

int main()
{
   char *opciones_menu_principal[CANT_OPCIONES_MENU_MAIN] = {"Ordenamiento", "Busqueda", "Salir"};
   char *opciones_menu_ordenamiento[CANT_OPCIONES_MENU_ORDE] = {"Burbuja", "Shell", "Seleccion", "QuickSort", "Atras"};
   char *opciones_menu_busqueda[CANT_OPCIONES_MENU_BUSQUEDA] = {"Secuencial", "Binaria", "Atras"};

   int opcion;
   do {
      _setcursortype(0);
      opcion = menu("Menu", opciones_menu_principal, CANT_OPCIONES_MENU_MAIN, POS_INI_X, POS_INI_Y);

      if (opcion == 0)
      {
         opcion = menu("Ordenamiento", opciones_menu_ordenamiento, CANT_OPCIONES_MENU_ORDE, strlen("Ordenamiento") + PADDING_MENU + 1, ORDENAMIENTO_OPCION + 1);

         if (opcion == CANT_OPCIONES_MENU_ORDE - 1)
         {
            system("cls");
            opcion = -1;
            continue;
         }
      } else if (opcion == 1)
      {
         opcion = menu("Busqueda", opciones_menu_busqueda, CANT_OPCIONES_MENU_BUSQUEDA, strlen("Ordenamiento") + PADDING_MENU + 1, BUSQUEDA_OPCION + 1);

         if (opcion == CANT_OPCIONES_MENU_BUSQUEDA - 1)
         {
            system("cls");
            opcion = -1;
            continue;
         }
      }

   } while (opcion != CANT_OPCIONES_MENU_MAIN - 1);

   return 0;
}

/*
Funcion: menu
Argumentos: char *titulo: Indica el titulo que aparecera en la parte superior del menu.
            char *opciones: Indica las opciones del menu.
            int cant_opciones: Indica la cantidad de opciones presentes en el menu.
            int posx: Indica la posicion del menu en el eje X.
            int posy: Indica la posicion del menu en el eje Y.
Objetivo: Se encarga de la funcionalidad de movimiento en el menu
Retorno: (int) La posicion del usuario en el menu.
*/
int menu(const char *titulo, char *opciones[], int cant_opciones, int posx, int posy)
{
   int ind = 0;
   int tecla;

   do
   {
      show_menu(titulo, opciones, cant_opciones, ind, posx, posy);
      do
      {
         tecla = getch();
      } while (tecla != ENTER && tecla != ESC && tecla != ARRIBA && tecla != ABAJO);

      if (tecla == ARRIBA)
      {
         if (ind > 0)
            ind--;
         else if (ind == 0) // Si el usuario esta al principio del menu, se mueve hasta el final
            ind = cant_opciones - 1;
      }
      else if (tecla == ABAJO)
      {
         if (ind < cant_opciones - 1)
            ind++;
         else if (ind == cant_opciones - 1) // Si el usuario esta al final del menu, se mueve al principio
            ind = 0;
      }
   } while (tecla != ENTER && tecla != ESC);

   return ind;
}

/*
Funcion: show_menu
Argumentos: char *titulo: Indica el titulo del menu.
            char *opciones: Indica las opciones presentes en el menu.
            int cant_opciones: Indica la cantidad de opciones del menu.
            int posx: Indica la posicion del menu en la consola en el eje X.
            int posy: Indica la posicion del menu en la consola en el eje Y.
Objetivo: Mostrar un menu interactivo en consola.
Retorno: (void)
*/
void show_menu(const char *titulo, char *opciones[], int cant_opciones, int ind, int posx, int posy)
{
   int w_max = strlen(titulo) + PADDING_MENU;
   for (int j = 0; j < cant_opciones; j++)
      if (strlen(opciones[j]) > w_max)
         w_max = strlen(opciones[j]) + PADDING_MENU;

   gotoxy(posx, posy);
   set_color(WHITE, BLUE);
   printf("%*s", w_max * -1, titulo);
   for (int i = 0; i < cant_opciones; i++)
   {
      if (i == ind)
         set_color(YELLOW, BLACK);
      else
         set_color(YELLOW, BLUE);
      gotoxy(posx, posy + i + 1);
      printf("%*s", w_max * -1, opciones[i]);
   }
   color_default();
}

/*
Funcion: comparar_str
Argumentos: char *str: Indica uno de los string a evaluar
            char *str1: Indica uno de los string a evaluar
Objetivo: Devolver el orden en el que van los string tomando en cuenta su case
Retorno: (int)
*/
int comparar_str(char *str, char *str1)
{
   int len = strlen(str);
   int len1 = strlen(str1);

   char *str_lower  = malloc((len  + 1) * sizeof(char));
   char *str1_lower = malloc((len1 + 1) * sizeof(char));

   for (int i = 0; i <= len; i++)
      str_lower[i] = tolower((unsigned char) str[i]);

   for (int i = 0; i <= len1; i++)
      str1_lower[i] = tolower((unsigned char) str1[i]);

   int result = strcmp(str_lower, str1_lower);
   free(str_lower);
   free(str1_lower);
   return result;
}
/*
Funcion: shell_sort
Argumentos: char *arr[]: Indica el arreglo de cadenas a ordenar
            int size: Indica el tamaño del arreglo a ordenar
Objetivo: Organizar el arreglo de cadenas de caracteres usando el metodo de ordenamiento Shell
Retorno: (void)
*/
void shell_sort(char *arr[], int size)
{
   for (int gap = size / 2; gap > 0; gap /= 2)
   {
      for (int i = gap; i < size; i++)
      {
         char *temp = arr[i];
         int j;
         for (j = i; j >= gap && comparar_str(arr[j - gap], temp) > 0; j -= gap)
         {
            arr[j] = arr[j - gap];
         }
         arr[j] = temp;
      }
   }
}

/*
Funcion: quick_sort
Argumentos: char *arr[]: Indica el arreglo de strins a organizar
            int low: Indica el indice al menor elemento
            int high: Indica el indice al mayor elemento
Objetivo: Se encarga de organizar un arreglo de strings utilizando el algoritmo quick_sort
Retorno: (void)
*/
void quick_sort(char *arr[], int low, int high)
{
   if (low < high)
   {
      int pivot = partition(arr, low, high);

      quick_sort(arr, low, pivot - 1);
      quick_sort(arr, pivot + 1, high);
   }
}

/*
Funcion: partition
Argumentos: char *arr[]: Indica el arreglo de strings a organizar
            int low: Indica el indice del menor elemento
            int high: Indica el indice del mayor elemento
Objetivo: Se encarga de organizar los elementos y mover el pivot a una nueva ubicacion
Retorno: (int) Indice del nuevo pivot
*/
int partition (char *arr[], int low, int high)
{
   char *pivot = arr[high];
   int i = low - 1;

   for (int ind = low; ind < high; ind++)
   {
      if (comparar_str(arr[ind], pivot) < 0)
      {
         i++;
         char* temp = arr[i];
         arr[i] = arr[ind];
         arr[ind] = temp;
      }
   }
   char* temp = arr[i + 1];
   arr[i + 1] = arr[high];
   arr[high] = temp;
   return i + 1;
}

/*
Funcion: binary_search
Argumentos: char *arr[]: Indica el arreglo de cadenas que se verificara
            int n: Indica la cantidad de elementos en arr.
            char *target: Indica el elemento a buscar
Objetivo: Buscar target dentro del arreglo utilizando binary search
*/
int binary_search(char *arr[], int n, char *target)
{
   int lo = 0;
   int hi = n - 1;

   while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;

      if (!comparar_str(arr[mid], target))
         return mid;
      else if (comparar_str(arr[mid], target) > 0)
         lo = mid + 1;
      else
         hi = mid - 1;
   }

   return -1;
}

/*
Funcion: color_default
Argumentos: (void)
Objetivo: Reestablecer los colores de consola a sus valores por defecto
Retorno: (void)
*/
void color_default(void)
{
   textcolor(LIGHTGRAY);
   textbackground(BLACK);
}

/*
Funcion: set_color
Argumentos: int color: Indica el color de texto a mostrar.
            int fondo: Indica el color de fondo a mostrar.
Objetivo: Se encarga de ofrecer una forma de cambiar color de manera rapida y con una sola llamada.
Retorno: (void)
*/
void set_color(int color, int fondo)
{
   textcolor(color);
   textbackground(fondo);
}
