// ð�����򣨴Ӻ���ǰð�ݣ�
void BubbleSort(int A[], int n) {
	for (int i = 0;i < n - 1;i++) {
		int flag = 0; // ��ʾ����ð���Ƿ��������ı�־
		for(int j = n-1; j > i; j--)  // һ��ð�ݹ���
			if (A[j - 1] > A[j]) {  //  ��Ϊ����
				Swap(&A[j - 1],&A[j]);  //  ����
				flag = 1;
			}
		if (flag == 0)
			return;  // ���˱�����û�з���������˵�����Ѿ�����
	}
}

// ð�����򣨴�ǰ����ð�ݣ�
void BubbleSort_1(int A[], int n) {
	for (int i = 0;i < n - 1;i++) {
		int flag = 0; // ��ʾ����ð���Ƿ��������ı�־
		for (int j = 0; j < n-1; j++)  // һ��ð�ݹ���
			if (A[j + 1] < A[j]) {  //  ��Ϊ����
				Swap(&A[j + 1], &A[j]);  //  ����
				flag = 1;
			}
		if (flag == 0)
			return;  // ���˱�����û�з���������˵�����Ѿ�����
	}
}