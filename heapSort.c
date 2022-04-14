#include <stdio.h>
#include <stdlib.h>
long long int count;

void maxHeapify(int A[], int i, int tam) {
	int pronto=0, maior, tmp;

	while ((i*2 <= tam) && (!pronto)) { //enquanto o filho for menor que o tamanho da heap
		count++;
		if (i*2 == tam) { //encontra os filhos do pai
			maior = i*2;
		}
		else if (A[i*2] > A[i*2+1]) { //se  filho da esquerda for maior que o da direita
			maior = i * 2; 
		}
		else { //se  filho da direita for maior que o da esquerda
			count++;
			maior = i*2+1;
		}
		count++;  //o heap criado é ordenado em ordem decrescente

		if (A[i] < A[maior]) { //compara se o maior filho é maior que o pai
			tmp = A[i];
			A[i] = A[maior];
			A[maior] = tmp;
			i = maior;
		}
		else {
      		pronto = 1; //vai ser 1 quando o pai é maior que os filhos
		}
	count++;
  }
  count++;
}

void bMaxHeap(int A[],int n){ //bulid-max-heap
    int i;
    for (i = (n/2); i >= 0; i--) { //constroi um heap usando os elementos dados
		count++;
		maxHeapify(A, i, n-1); //toda vez que o heap é ordenado novamente, o ultimo item é ignorado por ser o maior item
	}
	count++;
}

long long int heapSort(int A[], int n) {
	int i, tmp;
	count=0;

	bMaxHeap(A,n);

	for (i = n-1; i >= 1; i--) {
		count++;
		tmp = A[0];
		A[0] = A[i];
		A[i] = tmp; //a raiz, que acaba sendo o maior item, é enviada para o fim da lista
		maxHeapify(A, 0, i-1);
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
	res = heapSort(A, 100); 
	printf("resultado:"); 
	for (i=0;i<100;i++) printf("%d ",A[i]);
    printf("\n");
	printf("cont: %d\n",res);
    return 0;
}
*/