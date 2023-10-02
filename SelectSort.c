void SelectSort(int A[], int n) {
	for (int i=0; i < n - 1;i++) {  // 一共进行n-1趟
		int min = i;  // 记录最小元素位置
		for (int j = i + 1;j < n;j++)  // 在A[i…n-1]中选择最小的元素
			if (A[j] < A[min]) min = j;  // 更新最小元素位置
		if (min != i) Swap(&A[i], &A[min]);  // 封装的Swap()函数共移动元素3次
	}
}