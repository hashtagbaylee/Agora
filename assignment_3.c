// Baylee Jones
// CSC 5760
// Program 3

#include <stdio.h>
#include <string.h>
#include <mpi.h>
#include <stdlib.h>

const int MAX_STRING = 100;

int main(int argc, char *argv[])
{	
	char greeting[MAX_STRING];
	int number[MAX_STRING];
	int size;
	int rank;
	
	strcpy(message, argv[1]);
	number[0] = atoi(argv[2]);
	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	if (rank != 0)
	{
		MPI_Recv(greeting, MAX_STRING, MPI_CHAR, rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MPI_Recv(number, MAX_STRING, MPI_INT, rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		
		char temp[MAX_STRING];
		sprintf(temp, "%d", rank);
		strcat(greeting, temp);
		number[0]++;
		printf("Message: %s \n Rank: %d \n Number: %d", greeting, rank, number[0]);
		
		if(rank == size - 1)
		{
			MPI_Send(greeting, MAX_STRING, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
			MPI_Send(number, MAX_STRING, MPI_INT, 0, 1, MPI_COMM_WORLD);
		}
		else
		{
			MPI_Send(greeting, MAX_STRING, MPI_CHAR, rank+1, 0, MPI_COMM_WORLD);
			MPI_Send(number, MAX_STRING, MPI_INT, rank+1, 0, MPI_COMM_WORLD);
		}
	}
	
	else 
	{
		MPI_Send(greeting, MAX_STRING, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
		MPI_Send(number, MAX_STRING, MPI_INT, 1, 0, MPI_COMM_WORLD);
		
		MPI_Recv(greeting, MAX_STRING, MPI_CHAR, size-1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MPI_Recv(number, MAX_STRING, MPI_INT, size-1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		
		char temp[MAX_STRING];
		sprintf(temp, "%d", rank);
		strcat(greeting, temp);
		number[0]++;
		printf("Message: %s \n Rank: %d \n Number: %d", greeting, rank, number[0]);
	}
	
	MPI_Finalize();
	return 0;
}