// 桶排序函数
void BucketSort(int A[], int n) {
    // 假设数据范围在0到99之间，创建包含100个桶的数组
    int* buckets[100];
    // 初始化桶数组中的每个元素为0
    for (int i = 0; i < 100; i++) {
        buckets[i] = 0;
    }
    // 将元素放入桶中
    for (int i = 0; i < n; i++) {
        int index = A[i];
        // 计算桶中元素的个数
        buckets[index]++;
    }
    // 从桶中取出数据，按顺序放回原数组中
    int index = 0;
    for (int i = 0; i < 100; i++) {
        while (buckets[i] > 0) {
            A[index++] = i;
            buckets[i]--; // 减少桶中元素的个数
        }
    }
}