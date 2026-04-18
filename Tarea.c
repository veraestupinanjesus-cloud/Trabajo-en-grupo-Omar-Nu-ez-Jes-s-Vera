#include <stdio.h>
#define ESTUDIANTES 5
#define ASIGNATURAS 3

int main(){
    // Matrices y Vectores - Omar Nunez
    float calificaciones[ESTUDIANTES][ASIGNATURAS];
    float promedios_est[ESTUDIANTES] = {0};
    float promedios_asig[ASIGNATURAS] = {0};
    int aprobados_asig[ASIGNATURAS] = {0};
    int reprobados_asig[ASIGNATURAS] = {0};

    printf("SISTEMA DE GESTION ACADEMICA\n\n");
 //Validacion - Jesus Vera
for (int i = 0; i < ESTUDIANTES; i++) {
    for (int j = 0; j < ASIGNATURAS; j++) {
        do {
            printf("Ingrese la calificacion del estudiante %d en la asignatura %d: ", i + 1, j + 1);
            scanf("%f", &calificaciones[i][j]);
            if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10) {
                printf("Calificacion invalida. Por favor ingrese un valor entre 0 y 10.\n");
            }
        } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
    }
    printf("\n");

}
//Calculo de promedios por estudiante - Omar Nunez
  for (int i = 0; i < ESTUDIANTES; i++) {
        float suma = 0;
        for (int j = 0; j < ASIGNATURAS; j++) {
            suma += calificaciones[i][j]; // FIX: Era +=, no +-
        }
        promedios_est[i] = suma / ASIGNATURAS; // FIX: Era promedios_est, no esl
    }
    return 0;
}
