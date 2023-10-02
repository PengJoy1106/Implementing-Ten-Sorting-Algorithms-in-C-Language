#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 30


void initA(int A[], int len) {
	for (int i = 0;i < len;i++) {
		A[i] = rand() % 200;
	}
}

void ShowA(int A[], int len) {
	for (int i = 0;i < len;i++) {
		printf("%d ", A[i]);
	}
	printf("\n----------------------------------------\n");
}

int main()
{
	srand((unsigned int)time(NULL));
	int A[MAXSIZE];
	initA(A, MAXSIZE);
	ShowA(A, MAXSIZE);
	InsertSort(A,MAXSIZE);
	//InsertSort_1(A,MAXSIZE);
	//ShellSort(A,MAXSIZE);
	//BubbleSort(A, MAXSIZE);
	//QuickSort(A, 0, MAXSIZE-1);
	//SelectSort(A, MAXSIZE);
	//HeapSort(A, MAXSIZE);
	//MergeSort(A, 0, MAXSIZE-1);
	//CountSort(A,MAXSIZE);
	RedixSort(A, MAXSIZE);
	ShowA(A, MAXSIZE);
	system("pause");
	return 0;

}