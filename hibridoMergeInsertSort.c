#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long int cmer;

/*
void printArr(int A[], n){
    
}*/

void mergeI(int A[], int p, int q, int r, int max){ //mergesort
     int n1 = q-p, n2 = r-q;
     int L[n1+1], R[n2+1]; //cria duas listas temporarias
     int i,j,k=p;

     for (i=0;i<n1;i++){ //percorre a primeira metade da lista
         cmer++;
         L[i]=A[p+i]; //preenche uma das listas temporarias com os valores em relação a metade p
     }
     cmer++;
     L[i] = max+1;

    for (j=0; j<n2; j++) { //percorre a segunda metade da lista
        cmer++;
        R[j]=A[q+j]; //preenche a outra lista temporaria com os valores da outra metade 
    }
    cmer++;
    R[j]= max+1;

    i = 0;
    j = 0;

    for (;k<r;k++){ //merge - substitui o vetor principal com os dois ordenados
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

void insMerSort(int A[],int p, int n){ //insertsort
    int i,j,chave;
    
    for (j=p+1; j<n; j++){
        cmer++;
        i=j-1;
        chave = A[j]; //seleciona o primeiro elemento não odenado
        while (i>=p && A[i] > chave){ //move os elementos para a direita parar criar espaço para o elemento não ordenado
            A[i+1]=A[i];
            i=i-1;
            cmer++;
        }
        cmer++;
        A[i+1] = chave; //insere o elemento não ordenado na posição correta
    }
    cmer++;
}

void mergeInss(int A[], int p, int r, int max){
     int q = floor((p+r)/2),i;

     if (r-p<100){
         insMerSort(A,p,r); //chama insertsort (modificado para lidar com os vetores do tamanho p-r)
     }
     else { //enquanto l é maior que r
         mergeInss(A,p,q,max); //recursivamente se chama, até que o tamanho de p-r seja menor que 100
         mergeInss(A,q,r,max);
         mergeI(A,p,q,r,max); //merge as partes do array
     }
     cmer++;
 }

 long long int mergeIns(int A[], int p, int r, int max){ //retorna o numero correto de comparações
     cmer=0;
     mergeInss(A,p,r,max);
     return cmer;

 }
/*

int main() {
	int A[100];
	int i;
    for (i=0;i<100;i++){
        A[i]=(rand()%100);
    }
	mergeIns(A,0,100,100);
	for (i = 0; i < 100; i++) {
		printf("%d ", A[i]);
	}
	return 0;
}*/
