#include <stdio.h>
#include <stdlib.h>

long long int insertionSort(int A[],int n){
    int i,j,chave;
    long long int cins=0;
    
    for (j=1; j<n; j++){
        cins++;
        i=j-1; 
        chave = A[j]; // seleciona o primeiro elemento não odenado
        while (i>=0 && A[i] > chave){ //move os elementos para a direita parar criar espaço para o elemento não ordenado
            A[i+1]=A[i];
            i=i-1;
            cins++;
        }
        cins++;
        A[i+1] = chave; //insere o elemento não ordenado na posição correta
    }
    cins++;
    return cins;
}

/*
teste
int main(){ 
	int A[100];
    int res,i; 
    for (i=0;i<100;i++) A[i] = (rand()%100);
	res = insertionSort(A, 100); 
	printf("resultado:"); 
	for (i=0;i<100;i++) printf("%d ",A[i]);
    printf("\n");
	printf("cont: %d\n",res);
    return 0;
}
*/
