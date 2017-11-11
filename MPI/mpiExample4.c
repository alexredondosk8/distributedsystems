#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib>
#include "mpi.h"

using namespace std;

int main(int argc,char *argv[]){
	long i, maxVal;
	long start, end;
	int size, rank;
	double x, y, rand_nums;
	long sumTotal, sum, circle, cirTotal; // utilizamos Long para que no se desborde la operación

	rand_nums = create_rand_nums(nums_elements_per_proc);

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	// Defina aqui el segmento que debe procesar una tarea
	if(rank == 1){
		// El inicio del segmento en la variable 'start', el fin del segmento
		// la variable 'end'
		start = 0; 
		end = 1e3;
		circle = 0;
    	for(i=start; i<= end; i++){
    		x = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
    		y = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
    		if (x*x+y*y <= 1.0) circle ++;
    	}
	}
	else if (rank == 2){
		// El inicio del segmento en la variable 'start', el fin del segmento
		// la variable 'end'
		start = 0;
		end = 1e4;
		sum = 0;
    	for(i=start; i<= end; i++){
    		sum = sum +i;
    	}
	}
	else if (rank == 3){
		// El inicio del segmento en la variable 'start', el fin del segmento
		// la variable 'end'
		start = 0;
		end = 1e5;
		sum = 0;
    	for(i=start; i<= end; i++){
    		sum = sum +i;
    	}
	}
	else if (rank == 4){
		// El inicio del segmento en la variable 'start', el fin del segmento
		// la variable 'end'
		start = 0;
		end = 1e6;
		sum = 0;
    	for(i=start; i<= end; i++){
    		sum = sum +i;
    	}
	}
	else if (rank == 5){
		// El inicio del segmento en la variable 'start', el fin del segmento
		// la variable 'end'
		start = 0;
		end = 1e7;
		sum = 0;
    	for(i=start; i<= end; i++){
    		sum = sum +i;
    	}
	}
	else if (rank == 6){
		// El inicio del segmento en la variable 'start', el fin del segmento
		// la variable 'end'
		start = 0;
		end = 1e8;
		sum = 0;
    	for(i=start; i<= end; i++){
    		sum = sum +i;
    	}
	}
	else if (rank == 7){
		// El inicio del segmento en la variable 'start', el fin del segmento
		// la variable 'end'
		start = 0;
		end = 1e9;
		sum = 0;
    	for(i=start; i<= end; i++){
    		sum = sum +i;
    	}
	}
	// Utilice la funcion 'MPI_Reduce' para guardar en la variable 
	// 'sumTotal' la suma parcial de todos las tareas
	MPI_Reduce(&circle, &cirTotal, 1, MPI_LONG, MPI_SUM, 0,
           MPI_COMM_WORLD);
    
    if (rank == 0){
	printf ("\nTotal: %ld\n",cirTotal);
	}

	MPI_Finalize();
	
	return 0;
}
