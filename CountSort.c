#define N 200
int temp[N];
void CountSort(int A[], int n) {
	for (int i = 0;i < n;i++)
		temp[A[i]]++;
	for (int i = 0, j = 0;i < N;i++)
		while (temp[i]--)
			A[j++] = i;
}