#include <stdio.h>
#include <string.h>

float precioTotalInventario (float precios[], int cantidadProductos);
void precioBajoAlto (float precios[], int n);
float precioPromedio (float precios[], int n);
void buscarProductos (char nombres [][21], float precios[], int n);

int main (int argc, char *argv[]) {
   
    float precioTotal, precioProm;
    int pCaro, pBarato, productos, i, op;
    char nombreProducto[10][21];
    float precioProducto [10];

    printf ("---------------------INVENTARIO---------------------\n");
    do {
    printf ("Cuantos productos desea ingresar?\n");
    printf (">> ");
    scanf ("%d", &productos);
    if (productos>10 || productos<0) {
        printf ("Ingrese nuevamente. Se permite MINIMO 1 y MAXIMO 10 productos");
    }
    }while (productos>10 || productos<0);
    printf ("Registro Exitoso\n");

    printf ("----------------PRODUCTO----------------\n");
    printf ("Ingrese el/los nombre/s del producto\n");
    for (i=0; i < productos; i++)
    {
     printf ("Producto #%d: \n", i+1);
     printf (">> ");
     scanf ("%s", nombreProducto[i]);
    }

    printf ("---------------PRECIOS--------------\n");
    printf ("Ingrese el/los precio/s de los productos\n");
    for (i= 0; i < productos; i++)
    {
        do{
        printf ("Producto #%d: \n",i+1);
        printf (">> ");
        scanf ("%f", &precioProducto[i]);

        if (precioProducto[i]<=0)
        {
            printf ("Dato no valido. Ingrese de nuevo.\n");
        }
        
        }while (precioProducto[i]<=0);
    }
    
    do
    {
        printf ("----------------------MENU----------------------\n");
        printf ("------------------------------------------------\n");
        printf ("Escoja una opcion\n");
        printf ("1. Precio total del inventario\n");
        printf ("2. Producto mas caro y mas barato\n");
        printf ("3. Precio promedio de todos los productos\n");
        printf ("4. Buscar producto y mostrar precio\n");
        printf ("5. Salir\n");
        printf (">> ");
        scanf ("%d", &op);
        if (op>5 || op<=0)
        {
            printf ("Opcion no valida. Ingrese de nuevo\n");
        }
    } while (op>5 || op<=0);
    
    switch (op)
    {
    case 1:
        precioTotal=precioTotalInventario(precioProducto, productos);
        printf ("El precio total del inventario es: %.2f \n", precioTotal);
        break;
    
    case 2:
        precioBajoAlto(precioProducto, productos);
        break;

    case 3:
        precioProm=precioPromedio(precioProducto,productos);
        printf("El precio promedio de los productos es: %.2f", precioProm);
        break;

    case 4:
       buscarProductos(nombreProducto, precioProducto, productos);
       break;

    case 5:
        printf ("Saliendo...\n");
        break;

    default:
        printf ("Opcion no valida\n");
        break; 
    }
    
    return 0;
}


float precioTotalInventario (float precios[], int n){
float sumaT=0;
int i=0;
for  (i = 0; i < n; i++)
{
    sumaT=sumaT+precios[i];
}
return sumaT;
}

void precioBajoAlto (float precios[], int n){
    float mayor=precios[0];
    float menor=precios[0];
    int i=0;
    for (i = 1; i < n; i++)
    {
        if (precios[i]>mayor)
        {
            mayor=precios[i];
        }
        if (precios[i]<menor)
        {
            menor=precios[i];
        }
        
    }
    printf ("\nEl producto mas bajo cuesta: $%.2f", menor);
    printf ("\nEl producto mas caro cuesta: $%.2f\n", mayor);
    
}

float precioPromedio (float precios[], int n){
if (n<=0) return 0;
float promedio=precioTotalInventario(precios,n);
return (float) promedio/n;
}

void buscarProductos (char nombres [][21], float precios[], int n){
    char buscarNombre [21];
    int encontrado=0, i=0;
    printf ("Ingrese el nombre del producto a buscar: \n");
    scanf ("%s", buscarNombre);

    for (i = 0; i < n; i++)
    {
        if (strcmp(nombres[i], buscarNombre)==0)
        {
            printf ("Producto encontrado: %s - Precio del producto: %.2f\n", nombres [i], precios [i]);
            encontrado=1;
            break;
        }
    }
    if (encontrado==0){
        printf ("No existe el producto '%s' en el inventario\n", buscarNombre);
    }
    
}