#include<stdio.h> 
#include<stdlib.h>
long long int cq;

#include <stdio.h>

long long int quickSortt(int a[], int p, int r) { //alternativo - evita segmentation fault
    int i=p, j=r, x, aux; //x - pivot
    x = a[(p + r) / 2]; //determina o pivot de maneira que ele fica na metade do vetor

    //partition 
    while(i <= j) {
        cq++;
        while(a[i] < x && i < r) { //determina o primeiro elemento da esquerda que é maior que o pivot
            cq++;
            i++;
        }
        cq++;
        while(a[j] > x && j > p) { //determina o primeiro elemento da direita que é menor que o pivot
            cq++;
            j--;
        }
        cq++;
        if(i <= j) { //ordena se i <= j (troca maior item a direita pelo menor item a esquerda) // o igual é porque se j=0 for maior eles serão ordenados
            aux = a[i]; 
            a[i] = a[j];
            a[j] = aux;
            i++;
            j--;
        }
        cq++;
    }
    cq++;
    //fim
     
    if(j > p) {
        quickSortt(a, p, j); //quick sort na parte da esquerda (que tem os itens menores que o pivot)
    }
    cq++;
    if(i < r) {
        quickSortt(a, i, r); //quick sort na parte da direita (que tem os itens maiores que o pivot)
    }
    cq++;  
}

long long int quickSort(int a[], int p, int r){ //retorna o numero correto de comparações
    cq=0;
    quickSortt(a,p,r);
    return cq;
}


/*
int partition (int A[], int p, int r){
    int tmp,j; 
	int x = A[r]; // pivot
	int i = (p - 1); // posição do menor elemento

	for (j = p; j <= r- 1; j++){ 
		cq++;
		if (A[j] < x){  //se o elemento atual é menor que o pivot
			i++; // incremento do ind 
			tmp = A[i];
            A[i] = A[j];
            A[j] = tmp; //troca
		}
		cq++;
	}
	cq++;
	tmp = A[i + 1];
    A[i+1] = A[r];
    A[r] = tmp; 
	return (i + 1);  //retorna o pivot
} 

void quickSortReal(int A[], int p, int r){ 
	if (p < r){ 
		int q = partition(A, p, r); 
		quickSortReal(A, p, q - 1); 
		quickSortReal(A, q + 1, r); 
	} 
    cq++;
} 

long long int quickSort(int A[], int p, int r){
	cq=0;
	quickSortReal(A, p, r);
	return cq;
}
*/


//teste
/*
 int main(){ 
	int A[100];
    int res,i; 
    for (i=0;i<100;i++) A[i] = (rand()%100);
	res = quickSort(A, 0, 100-1); 
	printf("resultado:"); 
	for (i=0;i<100;i++) printf("%d ",A[i]);
    printf("\n");
	printf("cont: %d\n",res);
    return 0;
} */
