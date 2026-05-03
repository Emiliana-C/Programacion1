#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {

    char nombres[10][20];
    int stock[10];
    float precio[10];

    int opc1 = 0, opc2 = 0, cont = 0;

    do
    {
        opc1 = menu();
        switch (opc1)
        {
        case 1:
            cont = registrarProducto(nombres,precio,stock,cont);
            break;
        case 2:
            verInventario(nombres,precio,stock,cont);
            break;
        case 3:
            productoBajoAlto (nombres, precio, cont);
            break;
        case 4: 
            buscarProductoxNombre (nombres,precio,stock,cont);
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
        printf("Desea seleccionar otra opcion 1.Si/2.No: ");
        opc2 = validarEnteroConRango(1,2);
    } while (opc2 == 1);
    return 0;
}