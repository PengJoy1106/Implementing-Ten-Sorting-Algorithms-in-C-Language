// ϣ������
void ShellSort(int A[], int n) {
	int d, i, j;
	for (d = n / 2;d >= 1; d = d / 2)  // �����仯
		for (i = d;i < n;i++)
			if (A[i] < A[i - d]) {  // �轫A[i]�������������ӱ�
				int temp = A[i];  // �ݴ���temp
				for (j = i - d;j >= 0 && temp < A[j];j-=d)  // 
					A[j + d] = A[j];  // ��¼���ƣ����Ҳ����λ��
				A[j + d] = temp;  // ����
			}
}