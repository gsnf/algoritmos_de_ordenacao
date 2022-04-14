#include <stdio.h>
#include <stdlib.h>

long long int bubbleSort(int A[], int n){
    int i, j, temp;
    long long int count=0; 
    for (i=0;i<n;i++){ //de 0 a comprimento(A)-1
        count++;
        for (j = n-1;j>i;j--){ // de comprimento(A)-1 a 0
            count++;
            if (A[j] < A[j-1]){ //compara os elementos adjacentes
                temp = A[j];
                A[j] = A[j-1]; //troca A[j] com A[j-1]
                A[j-1] = temp;
            }
            count++;
        }
        count++;
    }
    count++;
    
    return count;
}

/*
//teste
int main(){ 
	int A[100];
    int res,i; 
    for (i=0;i<100;i++) A[i] = (rand()%100);
	res = bubbleSort(A, 100); 
	printf("resultado:"); 
	for (i=0;i<100;i++) printf("%d ",A[i]);
    printf("\n");
	printf("cont: %d\n",res);
    return 0;
}
*/

