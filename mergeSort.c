#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long int cmer;

 void merge(int A[], int p, int q, int r, int max){
     int n1 = q-p+1, n2 = r-q;
     int L[n1+1], R[n2+1]; //cria duas listas temporarias
     int i,j,k=p; 

     for (i=0;i<n1;i++){ //percorre a primeira metade da lista
         cmer++;
         L[i]=A[p+i];  //preenche uma das listas temporarias com os valores em relação a metade p
     }
     cmer++;
     L[i] = max+1;  

    for (j=0; j<n2; j++) { //percorre a segunda metade da lista
        cmer++;
        R[j]=A[q+j+1]; //preenche a outra lista temporaria com os valores da outra metade
    }
    cmer++;
    R[j]= max+1;

    i = 0;
    j = 0;

    for (;k<=r;k++){ //merge - substitui o vetor principal com os dois ordenados
        cmer++;
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        cmer++;
    }
    cmer++;
 }

void mmergeSort(int A[], int p, int r,int max){
    //p - inicio, r - fim
     int q = floor((p+r)/2), t=A[0], i; //deteremina a "metade" do vetor
    //q - meio

     if (p<r){  //enquanto l é maior que r
         mmergeSort(A,p,q,max); //recursivamente se chama, até que o tamanho de p-r seja 1
         mmergeSort(A,q+1,r,max);
         merge(A,p,q,r,max); //merge duas "metades" do array
     }
     cmer++;
 }

 long long int mergeSort(int A[], int p, int r,int max){ //retorna o numero correto de comparações
     cmer=0;
     mmergeSort(A,p,r,max);
     return cmer;
 }

/*
//teste
 int main(){ 
	int A[1000];
    int res,i; 
    for (i=0;i<1000;i++) A[i] = (rand()%100);
	res = mergeSort(A, 0, 1000-1, 100); 
	printf("resultado:"); 
	//for (i=0;i<100;i++) printf("%d ",A[i]);
    printf("\n");
	printf("cont: %d\n",res);
    return 0;
}
*/
