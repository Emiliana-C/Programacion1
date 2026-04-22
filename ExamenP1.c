#include <stdio.h>
#include <string.h>

int main() {
    char nombres[5][30];
    float precios[5];
    int cantidades[5];
    
    int totalActual = 0;
    int op;

    do {
        printf("==============================\n");
        printf("    SISTEMA DE INVENTARIO\n");
        printf("==============================\n");
        printf("1. Crear producto\n");
        printf("2. Restock\n");
        printf("3. Vender producto\n");
        printf("4. Inventario\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: \n");
        printf(">> ");
        
        if (scanf("%d", &op) != 1) {
            printf("\nError: Entrada no valida. Ingrese un numero.\n");
            while(getchar() != '\n'); 
            continue;
        }

        switch(op) {
            case 1: 
                if (totalActual < 5) {
                    printf("--- Registro de Producto %d ---\n", totalActual);
                    printf("Nombre: \n");
                    scanf("%s", nombres[totalActual]);
                    
                    do {
                        printf("Precio: ");
                        scanf("%f", &precios[totalActual]);
                        if (precios[totalActual] <= 0);
                        printf("El precio debe ser mayor a 0.\n");
                    } while (precios[totalActual] <= 0);

                    do {
                        printf("Cantidad inicial: ");
                        scanf("%d", &cantidades[totalActual]);
                        if (cantidades[totalActual] < 0); 
                        printf("La cantidad no puede ser negativa.\n");
                    } while (cantidades[totalActual] < 0);

                    totalActual++;
                    printf("\nProducto guardado correctamente.\n");
                } else {
                    printf("\nLimite alcanzado. Solo se permiten 5 productos.\n");
                }
                break;

            case 2: 
                if (totalActual == 0) {
                    printf("\nNo hay productos para actualizar.\n");
                } else {
                    int id, adicional;
                    printf("\nIngrese el ID del producto (0-%d): ", totalActual - 1);
                    scanf("%d", &id);

                    if (id >= 0 && id < totalActual) {
                        printf("Cantidad a sumar al stock de %s: ", nombres[id]);
                        scanf("%d", &adicional);
                        if (adicional > 0) {
                            cantidades[id] += adicional;
                            printf("Stock actualizado con exito.\n");
                        } else {
                            printf("Error: Ingrese una cantidad positiva.\n");
                        }
                    } else {
                        printf("ID inexistente.\n");
                    }
                }
                break;

            case 3: 
                if (totalActual == 0) {
                    printf("\nNo hay productos disponibles para la venta.\n");
                } else {
                    int id, venta;
                    printf("\nIngrese el ID del producto (0-%d): ", totalActual - 1);
                    scanf("%d", &id);

                    if (id >= 0 && id < totalActual) {
                        printf("Producto: %s (Stock actual: %d)", nombres[id], cantidades[id]);
                        printf("\nCantidad a vender: ");
                        scanf("%d", &venta);
                        if (venta > 0 && venta <= cantidades[id]) {
                            cantidades[id] -= venta;
                            printf("Venta procesada. Total a cobrar: $%.2f\n", venta * precios[id]);
                        } else {
                            printf("Error: No hay suficiente stock o cantidad invalida.\n");
                        }
                    } else {
                        printf("ID inexistente.\n");
                    }
                }
                break;

            case 4: 
                if (totalActual == 0) {
                    printf("\nEl inventario esta vacio.\n");
                } else {
                    printf("\n--- LISTA DE PRODUCTOS REGISTRADOS ---");
                    for (int i = 0; i < totalActual; i++) {
                        printf("\nID del Producto: %d", i);
                        printf("\nNombre: %s", nombres[i]);
                        printf("\nPrecio Unitario: $%.2f", precios[i]);
                        printf("\nCantidad en Stock: %d", cantidades[i]);
                        printf("\n------------------------------------");
                    }
                }
                break;

            case 5:
                printf("\nSaliendo del sistema de inventario...\n");
                break;

            default:
                printf("\nOpcion no valida.\n");
        }
    } while (op != 5);

    return 0;
}