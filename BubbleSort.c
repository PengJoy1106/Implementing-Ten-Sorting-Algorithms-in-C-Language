// 冒泡排序（从后往前冒泡）
void BubbleSort(int A[], int n) {
	for (int i = 0;i < n - 1;i++) {
		int flag = 0; // 表示本趟冒泡是否发生交换的标志
		for(int j = n-1; j > i; j--)  // 一趟冒泡过程
			if (A[j - 1] > A[j]) {  //  若为逆序
				Swap(&A[j - 1],&A[j]);  //  交换
				flag = 1;
			}
		if (flag == 0)
			return;  // 本趟遍历后没有发生交换，说明表已经有序
	}
}

// 冒泡排序（从前往后冒泡）
void BubbleSort_1(int A[], int n) {
	for (int i = 0;i < n - 1;i++) {
		int flag = 0; // 表示本趟冒泡是否发生交换的标志
		for (int j = 0; j < n-1; j++)  // 一趟冒泡过程
			if (A[j + 1] < A[j]) {  //  若为逆序
				Swap(&A[j + 1], &A[j]);  //  交换
				flag = 1;
			}
		if (flag == 0)
			return;  // 本趟遍历后没有发生交换，说明表已经有序
	}
}