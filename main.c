#include <stdio.h>
#include <stdlib.h>

// 声明 BucketSort 函数，位于 bucketsort.c 文件中
extern void BubbleSort(int A[], int n);
extern void CountSort(int A[], int n);
extern void HeapSort(int A[], int n);
extern void InsertSort(int A[], int n);
extern void InsertSort_1(int A[], int n);
extern void MergeSort(int A[], int low, int high);
extern void QuickSort(int A[], int low, int high);
extern void RedixSort(int A[], int n);
extern void SelectSort(int A[], int n);
extern void ShellSort(int A[], int n);
extern void BucketSort(int A[], int n);

#define MAXSIZE 10


void initA(int A[], int len) {
	for (int i = 0;i < len;i++) {
		A[i] = rand() % 20;
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
	//InsertSort(A,MAXSIZE);
	//InsertSort_1(A,MAXSIZE);
	//ShellSort(A,MAXSIZE);
	//BubbleSort(A, MAXSIZE);
	//QuickSort(A, 0, MAXSIZE-1);
	//SelectSort(A, MAXSIZE);
	//HeapSort(A, MAXSIZE);
	//MergeSort(A, 0, MAXSIZE-1);
	//CountSort(A,MAXSIZE);
	//RedixSort(A, MAXSIZE);
	BucketSort(A, MAXSIZE);
	ShowA(A, MAXSIZE);
	system("pause");
	return 0;

}