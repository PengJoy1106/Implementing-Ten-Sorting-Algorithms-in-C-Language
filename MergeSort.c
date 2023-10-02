#define N  8
int B[N];
//int B[8] = {0,0,0,0,0,0,0,0};
// A[low��mid]��A[mid��high]�������򣬽��������ֹ鲢
void Merge(int A[], int low, int mid, int high) {
	int i, j, k;
	for (k = low;k <= high;k++)
		B[k] = A[k];
	for (i = low, j = mid + 1, k = i;i <= mid && j <= high;k++) {
		if (B[i] <= B[j]) 
			A[k] = B[i++];  // ����Сֵ���Ƶ�A��
		else 
			A[k] = B[j++];
	}
	while (i <= mid) A[k++] = B[i++];
	while (j <= high) A[k++] = B[j++];
}
void MergeSort(int A[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;  // ���м仮��
		MergeSort(A, low, mid);  // ����벿�ֹ鲢����
		MergeSort(A, mid + 1, high);  // ���Ұ벿�ֹ鲢����
		Merge(A, low, mid, high);  //  �鲢
	}
}