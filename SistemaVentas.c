#include <stdio.h>

int main() {
    char id[10];   //variables y validaciones
    char nombre[30];

    int stock = 0; 
    float precio = 0;
    float ganancias = 0;

    int op, valido, cant;
    float desc;

    int registrado = 0;

    do {  //menu con switch
        printf("\n=============================\n");
        printf("\tMENU PRINCIPAL\n");
        printf("=============================\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer stock\n");
        printf("4. Consultar producto\n");
        printf("5. Ver ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");

        valido = scanf("%d", &op);

        if (valido != 1) {
            printf("Error: opcion no valida (no ingrese letras).\n");
            while (getchar() != '\n'); // limpiar buffer
            op = 0; // hace op invalida
        } else {
            getchar(); 
        }

        switch (op) {  //registro

            case 1:
                printf("\n--- REGISTRO ---\n");

                printf("Ingrese ID: ");
                fgets(id, 10, stdin);

                printf("Ingrese nombre: ");
                fgets(nombre, 30, stdin);

                do {
                    printf("Ingrese stock inicial: ");
                    valido = scanf("%d", &stock);
                    if (valido != 1 || stock < 0) {
                        printf("Error: valor invalido\n");
                        while (getchar() != '\n');
                    }
                } while (valido != 1 || stock < 0);

                do {
                    printf("Ingrese precio: ");
                    valido = scanf("%f", &precio);
                    if (valido != 1 || precio <= 0) {
                        printf("Error: valor invalido\n");
                        while (getchar() != '\n');
                    }
                } while (valido != 1 || precio <= 0);

                registrado = 1;
                printf("Producto registrado correctamente\n");
                break;

            case 2:  //venta
                if (registrado == 0) {
                    printf("Primero registre un producto\n");
                } else {
                    do {
                        printf("Cantidad a vender: ");
                        valido = scanf("%d", &cant);
                        if (valido != 1 || cant <= 0) {
                            printf("Error: cantidad invalida\n");
                            while (getchar() != '\n');
                        }
                    } while (valido != 1 || cant <= 0);

                    if (cant > stock) {
                        printf("No hay stock suficiente\n");
                    } else {
                        do {
                            printf("Descuento (0-100): ");
                            valido = scanf("%f", &desc);
                            if (valido != 1 || desc < 0 || desc > 100) {
                                printf("Error: descuento invalido\n");
                                while (getchar() != '\n');
                            }
                        } while (valido != 1 || desc < 0 || desc > 100);

                        float precioFinal = precio - (precio * desc / 100);
                        ganancias += cant * precioFinal;
                        stock -= cant;

                        printf("Venta realizada exitosamente\n");
                    }
                }
                break;

            case 3:  //restock
                if (registrado == 0) {
                    printf("Primero registre un producto\n");
                } else {
                    do {
                        printf("Cantidad a agregar: ");
                        valido = scanf("%d", &cant);
                        if (valido != 1 || cant<= 0) {
                            printf("Error: cantidad invalida\n");
                            while (getchar() != '\n');
                        }
                    } while (valido != 1 || cant <= 0);

                    stock += cant;
                    printf("Stock actualizado\n");
                }
                break;

            case 4:       //consultar datos
                if (registrado == 0) {
                    printf("No hay producto registrado\n");
                } else {
                    printf("\n======= PRODUCTO =======\n");
                    printf("ID:\t%s", id);
                    printf("Nombre:\t%s", nombre);
                    printf("Stock:\t%d\n", stock);
                    printf("Precio:\t%.2f\n", precio);
                }
                break;

            case 5:   //mostrar ganancias
                printf("\nGanancias acumuladas: %.2f\n", ganancias);
                break;

            case 6:   //fin programa
                printf("\nSaliendo...\n");
                break;

            default:          //op no validos
                printf("Opcion no valida. Intentar nuevamente\n");
                break;
        }

    } while (op != 6);

    printf("Fin del Programa\n");

    return 0;
}