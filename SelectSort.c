void SelectSort(int A[], int n) {
	for (int i=0; i < n - 1;i++) {  // һ������n-1��
		int min = i;  // ��¼��СԪ��λ��
		for (int j = i + 1;j < n;j++)  // ��A[i��n-1]��ѡ����С��Ԫ��
			if (A[j] < A[min]) min = j;  // ������СԪ��λ��
		if (min != i) Swap(&A[i], &A[min]);  // ��װ��Swap()�������ƶ�Ԫ��3��
	}
}