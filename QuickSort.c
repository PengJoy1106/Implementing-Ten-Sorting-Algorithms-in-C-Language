// �õ�һ��Ԫ�ؽ����������л���Ϊ������������
int Partition(int A[], int low, int high) {
	int pivot = A[low];  // ��һ��Ԫ����Ϊ����
	while (low < high) {  // ��low��high�������������λ��
		while (low < high && A[high] >= pivot) --high;   
		A[low] = A[high];  // ������С��Ԫ���Ƶ����
		while (low < high && A[low] <= pivot) ++low;  
		A[high] = A[low];  // ��������Ԫ���ƶ����Ҷ�
	}
	A[low] = pivot;  // ����Ԫ�ش�ŵ�����λ��
	return low;  // ���ش�����������λ��
}
// ��������
void QuickSort(int A[], int low, int high) {
	if (low < high) {  // �ݹ�����������
		int pivotpos = Partition(A, low, high);  // ����
		QuickSort(A, low, pivotpos - 1);  // �������ӱ�
		QuickSort(A, pivotpos + 1, high);  // �������ӱ�
	}
}