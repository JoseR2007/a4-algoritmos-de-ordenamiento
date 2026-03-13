#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

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

int menu(char *, char *, int, int, int);
void show_menu(char *, char *, int, int, int, int);

// Funciones de color:
void set_color(int, int);
void color_default(void);

int main()
{

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
int menu(char *titulo, char *opciones, int cant_opciones, int posx, int posy)
{
   int ind = 0;
   int tecla;

   do
   {
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
void show_menu(char *titulo, char *opciones, int cant_opciones, int ind, int posx, int posy)
{
   int w_max = strlen(titulo) + 2;
   for (int j = 0; j < cant_opciones; j++)
      if (strlen(opciones[j]) > w_max)
         w_max = strlen(opciones[j]) + 2;

   gotoxy(posx, posy);
   set_color(WHITE, BLUE);
   printf("%s", titulo);
   for (int i = 0; i < cant_opciones; i++)
   {
      if (i == ind)
         set_color(YELLOW, BLACK);
      else
         set_color(YELLOW, BLUE);
      printf("%*s", w_max, opciones[i]);
   }
}

/*
Funcion: color_default
Argumentos: (void)
Objetivo: Reestablecer los colores de consola a sus valores por defecto
Retorno: (void)
*/
void color_defualt(void)
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