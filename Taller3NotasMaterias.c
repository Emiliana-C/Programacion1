#include <stdio.h>

int main () {

float notas [5][3], suma, nalta, nbaja;    //variables y matriz declarada
int op, aprobados;                          //variable para el menú y acumulador de aprobacion

aprobados=0;

//Ingreso de notas y validacion de las mismas

printf ("SISTEMA DE NOTAS\n");
printf ("-------------------------------------\n");
printf ("Ingrese las notas de 5 estudiantes (3 por cada uno):\n");
for (int i=0; i<5; i++){
    for (int j=0; j<3; j++){
        do {
        printf ("Estudiante #%d, Nota #%d: ", i+1, j+1);
        scanf ("%f", &notas[i][j]);
        } while (notas[i][j] < 0 || notas[i][j] > 10);
    }
}

printf ("Ha ingresado las notas exitosamente.\n");

//Menú y bucle do while principal para todo el programa

do {
        printf ("Escoja una opcion:\n");
        printf ("1. Promedio de cada estudiante\n");
        printf ("2. Promedio por materia\n");
        printf ("3. Nota mas alta y mas baja por estudiante\n");
        printf ("4. Nota mas alta y mas baja por materia\n");
        printf ("5. Numero de estudiantes aprobados y reprobados\n");
        printf ("6. Salir\n");
        printf (">> ");
        scanf ("%d", &op);

        switch (op) {
            case 1:                                   //Promedio de cada estudiante
                for (int i=0; i<5; i++){
                    suma=0;
                    for (int j=0; j<3; j++){
                        suma += notas[i][j];
                    }
                    printf ("El promedio del estudiante #%d es: %.2f\n", i+1, suma/3);
                }
                break;

            case 2:                                   //Promedio por materia
                for (int j=0; j<3; j++){
                    suma=0;
                    for (int i=0; i<5; i++){
                        suma += notas[i][j];
                    }
                    printf ("El promedio de la materia #%d es: %.2f\n", j+1, suma/5);
                }
                break;

            case 3:                                     //Nota mas alta y mas baja por estudiante
                for (int i=0; i<5; i++){
                    nalta=notas[i][0];
                    nbaja=notas[i][0];
                    for (int j=0; j<3; j++){
                        if (notas[i][j] > nalta){
                            nalta = notas[i][j];
                        }
                        if (notas[i][j] < nbaja){
                            nbaja = notas[i][j];
                        }
                    }
                    printf ("El estudiante #%d tiene la nota mas alta: %.2f \n", i+1, nalta);
                    printf ("El estudiante #%d tiene la nota mas baja: %.2f \n", i+1, nbaja);
                }
                break;

            case 4:                                    //Nota mas alta y mas baja por materia
                for (int j=0; j<3; j++){
                    nbaja=notas[0][j];
                    nalta=notas[0][j];
                    for (int i=0; i<5; i++){
                        if (notas[i][j] < nbaja){
                            nbaja = notas[i][j];
                        }
                        if (notas[i][j] > nalta){
                            nalta = notas[i][j];
                        }
                    }
                    printf ("La materia #%d tiene la nota mas baja: %.2f\n", j+1, nbaja);
                    printf ("La materia #%d tiene la nota mas alta: %.2f\n", j+1, nalta);
                }
                break;

            case 5:                                       //Numero de estudiantes aprobados y reprobados por materia
            for (int j=0; j<3; j++){
                suma=0;
                for (int i=0; i<5; i++){
                    suma += notas[i][j];
                }
                if (suma/3 >= 6){
                    aprobados++;    
                }
            }
            printf ("El numero de estudiantes aprobados es: %d\n", aprobados);
            printf ("El numero de estudiantes reprobados es: %d\n", 5 - aprobados);
            break;
            
            case 6:                                         //Salida del programa
                printf ("Saliendo...\n");
                break;

            default:                                         //Una opcion ajena a las del menú
                printf ("Opcion invalida. Intente de nuevo.\n");   
                break;
        }
} while(op != 6);                                            //Cierre del bucle do while principal

    return 0;
}