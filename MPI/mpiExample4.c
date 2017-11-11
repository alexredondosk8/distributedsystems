#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
    long i, maxVal;
    long start, end;
    int size, rank;
    long sumTotal, sum; // utilizamos Long para que no se desborde la operación

    maxVal = 100000;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Defina aqui el segmento que debe procesar una tarea
    if(rank == 1){
        // El inicio del segmento en la variable 'start', el fin del segmento
        // la variable 'end'
        start = 1;
        end = 20000;
         sum = 0;
        for(i=start; i<= end; i++){
            sum = sum +i;
        }
    }
    else if (rank == 2){
        // El inicio del segmento en la variable 'start', el fin del segmento
        // la variable 'end'
        start = 20001;
        end = 40000;
        sum = 0;
        for(i=start; i<= end; i++){
            sum = sum +i;
        }
    }
    else if (rank == 3){
        // El inicio del segmento en la variable 'start', el fin del segmento
        // la variable 'end'
        start = 40001;
        end = 60000;
        sum = 0;
        for(i=start; i<= end; i++){
            sum = sum +i;
        }
    }
    else if (rank == 4){
        // El inicio del segmento en la variable 'start', el fin del segmento
        // la variable 'end'
        start = 60001;
        end = 80000;
        sum = 0;
        for(i=start; i<= end; i++){
            sum = sum +i;
        }
    }
    else if (rank == 5){
        // El inicio del segmento en la variable 'start', el fin del segmento
        // la variable 'end'
        start = 80001;
        end = 100000;
        sum = 0;
        for(i=start; i<= end; i++){
            sum = sum +i;
        }
    }
    // Utilice la funcion 'MPI_Reduce' para guardar en la variable
    // 'sumTotal' la suma parcial de todos las tareas
    MPI_Reduce(&sum, &sumTotal, 1, MPI_LONG, MPI_SUM, 0,
           MPI_COMM_WORLD);
    
    if (rank == 0){
    printf ("\nTotal: %ld\n",sumTotal);
    }

    MPI_Finalize();
    
    return 0;
}

