void InsertSort(int A[], int n) {
	int i, j, temp;
	for (i = 1;i < n;i++) {   // ����Ԫ�ز������źõ�������
		if (A[i] < A[i - 1]) {  // ��a[i]�ؼ���С��ǰ��
			temp = A[i];  // ��temp�ݴ�a[i]
			for (j = i - 1;j >= 0 && A[j] > temp;--j) //�������ǰ�����ź����Ԫ��
				A[j + 1] = A[j];  // ���д���temp��Ԫ�ض����Ųλ
			A[j + 1] = temp;  // ���Ƶ�����λ��
		}
	}
}