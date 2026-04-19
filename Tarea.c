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
            suma += calificaciones[i][j]; 
        }
        promedios_est[i] = suma / ASIGNATURAS; 
    }
    // Calculo de promedios por asignatura - Jesus Vera
    for (int j = 0; j < ASIGNATURAS; j++)   {
        float suma = 0;
        for (int i = 0; i < ESTUDIANTES; i++) {
            suma += calificaciones[i][j];
        }
        promedios_asig[j] = suma / ESTUDIANTES;
    }   

    // Variables - Calificacion mas alta y baja por Estudiante y por Asignatura
    float alta_est[ESTUDIANTES], baja_est[ESTUDIANTES];
    float alta_asig[ASIGNATURAS], baja_asig[ASIGNATURAS];

    // Calificacion mas alta y baja por estudiante - Omar Nunez
    for (int i = 0; i < ESTUDIANTES; i++) {
        alta_est[i] = calificaciones[i][0];
        baja_est[i] = calificaciones[i][0];
        for (int j = 0; j < ASIGNATURAS; j++) {
            if (calificaciones[i][j] > alta_est[i]) alta_est[i] = calificaciones[i][j];
            if (calificaciones[i][j] < baja_est[i]) baja_est[i] = calificaciones[i][j];
        }
    }
   // Calificacion mas alta y baja por asignatura y aprobados/reprobados - Jesus Vera
    for (int j = 0; j < ASIGNATURAS; j++) {
        alta_asig[j] = calificaciones[0][j];
        baja_asig[j] = calificaciones[0][j];
        for (int i = 0; i < ESTUDIANTES; i++) {
            if (calificaciones[i][j] > alta_asig[j]) alta_asig[j] = calificaciones[i][j];
            if (calificaciones[i][j] < baja_asig[j]) baja_asig[j] = calificaciones[i][j];

            if (calificaciones[i][j] >= 6) {
                aprobados_asig[j]++;
            } else {
                reprobados_asig[j]++;
            }
        }
    }

    // Reporte de resultados finales - Jesus Vera
    printf("\n--- RESULTADOS POR ESTUDIANTE ---\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("Estudiante %d -> Promedio: %.2f | Calificacion mas alta: %.2f | Calificacion mas baja: %.2f\n", i + 1, promedios_est[i], alta_est[i], baja_est[i]);
    }

    printf("\n--- RESULTADOS POR ASIGNATURA ---\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        printf("Asignatura %d -> Promedio: %.2f | Calificacion mas alta: %.2f | Calificacion mas baja: %.2f | Aprobados: %d | Reprobados: %d\n", j + 1, promedios_asig[j], alta_asig[j], baja_asig[j], aprobados_asig[j], reprobados_asig[j]);
    }
    return 0;
}