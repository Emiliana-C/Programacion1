#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu(){
    int opc=0;
    printf("Seleccione una opcion\n");
    printf("1.Registrar producto\n");
    printf("2.Ver inventario\n");
    printf("3.Encontrar el producto mas caro y mas barato\n");
    printf("4.Buscar producto por nombre\n");
    printf(">> ");
    opc = validarEnteroConRango(1,4);
    return opc;
}

int registrarProducto(char nombres[10][20], float precio[10], int stock[10], int cont){
    printf("Ingrese el nombre del producto %d: ",cont+1);
    leerCadena(nombres[cont],20);
    printf("Ingrese el precio del producto %d: ",cont+1);
    precio[cont] = validarFloatConRango(0,10000);
    printf("Ingrese el stock del producto %d: ",cont+1);
    stock[cont] = validarEnteroConRango(0,1000);
    return cont + 1;
}

void verInventario(char nombres[10][20], float precio[10], int stock[10], int cont){
    float totalProducto = 0;
    float totalInventario = 0;
    float precioPromedio = 0;

    printf("#\t\tNombre\t\tStock\t\tPrecio\t\tTotal\n");

    for (int i = 0; i < cont; i++)
    {
        totalProducto = stock[i] * precio[i];
        totalInventario += totalProducto;
        precioPromedio+=precio[i];
        printf("%d\t\t%s\t\t%d\t\t%.2f\t\t%.2f\n",i+1,nombres[i],stock[i],precio[i],totalProducto);
    }
    printf("Total inventario: %.2f\n",totalInventario);
    precioPromedio/=cont;
    printf("Precio promedio de los productos: %.2f\n",precioPromedio);
}

void leerCadena(char cadena[], int n){
    int len;
    fgets(cadena,n,stdin);
    len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

int validarEnteroConRango(int a, int b){
    int n;
    int aux;
    do
    {
        aux = scanf("%d",&n);
        while((getchar()) != '\n');
        if(aux != 1 || n < a || n > b){
            printf("El valor ingresado es incorrecto\n");
            printf(">> ");
        }
    } while (aux!=1 || n < a || n > b);
    return n;
}

float validarFloatConRango(int a, int b){
    float n;
    int aux;
    do
    {
        aux = scanf("%f",&n);
        while((getchar()) != '\n');
        if(aux != 1 || n < a || n > b){
            printf("El valor ingresado es incorrecto\n");
            printf(">> ");
        }
    } while (aux!=1 || n < a || n > b);
    return n;
}

void productoBajoAlto (char nombres [10][20], float precios[10], int cont){
    if (cont==0) return;
    int c=0, b=0;
    for (int i=1; i<cont; i++){
        if (precios [i]>precios [c]) c=i;
        if (precios[i]<precios[b])  b=i;
    }
    printf("Producto mas caro: %s (Precio: %.2f)\n", nombres[c], precios[c]);
    printf("Producto mas barato: %s (Precio: %.2f)\n", nombres[b], precios[b]);
}

void buscarProductoxNombre (char nombres [10][20], float precios[10], int stock [10], int cont){
    char nombre[20];
    printf("Ingrese el nombre del producto a buscar: ");
    leerCadena(nombre,20);
    for (int i=0; i<cont; i++){
        if (strcmp(nombre, nombres[i])==0){
            printf("Producto encontrado: %s (Precio: %.2f)\n", nombres[i], precios[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}