// 希尔排序
void ShellSort(int A[], int n) {
	int d, i, j;
	for (d = n / 2;d >= 1; d = d / 2)  // 步长变化
		for (i = d;i < n;i++)
			if (A[i] < A[i - d]) {  // 需将A[i]插入有序增量子表
				int temp = A[i];  // 暂存在temp
				for (j = i - d;j >= 0 && temp < A[j];j-=d)  // 
					A[j + d] = A[j];  // 记录后移，查找插入的位置
				A[j + d] = temp;  // 插入
			}
}