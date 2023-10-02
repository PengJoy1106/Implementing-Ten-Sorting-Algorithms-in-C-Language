// ����KΪ������������Ϊ�����
void HeadAdjust(int A[], int k, int len) {
	int temp = A[k];  // �ݴ������ĸ��ڵ�
	for (int i = 2 * k + 1; i < len; i = 2 * i + 1) {  // ��key�ϴ���ӽڵ�����ɸѡ
		if (i + 1 < len && A[i] < A[i + 1]) 
			i++;  // ȡkey�ϴ���ӽڵ���±�
		if (temp >= A[i])  
			break;  // ɸѡ����
		else {
			A[k] = A[i];  //��A[i]��ֵ������˫�׽ڵ���
			k = i;  // �޸�kֵ���Ա��������ɸѡ
		}
	}
	A[k] = temp;  // ��ɸѡ�ڵ��ֵ��������λ��
}
// ���������
void BuildMaxHeap(int A[], int len) {
	for (int i = len / 2 - 1; i >= 0; i--)  // �Ӻ���ǰ�������з��ն˽��
		HeadAdjust(A, i, len);
}
// ������������߼�
void HeapSort(int A[], int len) {
	BuildMaxHeap(A, len);  // ��ʼ����
	for (int i = len - 1; i > 0; i--) {  // n-1�˵Ľ����ͽ��ѹ���
		Swap(&A[i], &A[0]);  // �Ѷ�Ԫ�غͶѵ�Ԫ�ؽ���
		HeadAdjust(A, 0, i);  // ��ʣ��Ĵ�����Ԫ������ɶ�
	}
}