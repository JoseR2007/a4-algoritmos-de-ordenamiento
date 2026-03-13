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

int menu(char *, char *, int, int, int, int, int);

int main()
{

   return 0;
}

int menu(char *titulo, char *opciones, int cant_opciones, int posx, int posy, int color, int fondo)
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
         else if (ind == 0)
            ind = cant_opciones - 1;
      }
      else if (tecla == ABAJO)
      {
         if (ind < cant_opciones - 1)
            ind++;
         else if (ind == cant_opciones - 1)
            ind = 0;
      }
   } while (tecla != ENTER && tecla != ESC);

   return ind;
}