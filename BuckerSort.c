// Ͱ������
void BucketSort(int A[], int n) {
    // �������ݷ�Χ��0��99֮�䣬��������100��Ͱ������
    int* buckets[100];
    // ��ʼ��Ͱ�����е�ÿ��Ԫ��Ϊ0
    for (int i = 0; i < 100; i++) {
        buckets[i] = 0;
    }
    // ��Ԫ�ط���Ͱ��
    for (int i = 0; i < n; i++) {
        int index = A[i];
        // ����Ͱ��Ԫ�صĸ���
        buckets[index]++;
    }
    // ��Ͱ��ȡ�����ݣ���˳��Ż�ԭ������
    int index = 0;
    for (int i = 0; i < 100; i++) {
        while (buckets[i] > 0) {
            A[index++] = i;
            buckets[i]--; // ����Ͱ��Ԫ�صĸ���
        }
    }
}