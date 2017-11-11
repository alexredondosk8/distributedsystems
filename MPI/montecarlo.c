#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"



int main(int argc,char *argv[]){
	
	int numIter = 1e7;
	int size, rank;
	double x, y;
	int i;
	int cont = 0;
	double tem1;
	double pi;
	int reducedcont;
	int reducednumIter;

	MPI_Init(&argc,&argv);  // Comienza MPI
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	// Defina aqui el segmento que debe procesar una tarea
	if(rank != 0){
		srand48(time(NULL));
    	for(i=0; i<= numIter; i++){
    		x = (double)drand48();
    		y = (double)drand48();
    		tem1 = ((x*x)+(y*y));
    		if (tem1 <= 1.0) ++cont;
    	}
	}
	
	// Utilice la funcion 'MPI_Reduce' para guardar en la variable 
	// 'sumTotal' la suma parcial de todos las tareas
	MPI_Reduce(&cont, &reducedcont, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Reduce(&numIter, &reducednumIter, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	reducednumIter -= numIter; //para compensar por no loop en nodo master
    
    if (rank == 0){
    	//p = 4(m/n)
    	pi = ((double)reducedcont/(double)reducednumIter)*4.0;
		printf ("\nPi: %f\n",pi);
	}

	MPI_Finalize(); //Cierra la instacia MPI
	
	return 0;
}
