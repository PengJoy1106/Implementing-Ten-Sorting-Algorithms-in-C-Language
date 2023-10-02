// 将以K为根的子树调整为大根堆
void HeadAdjust(int A[], int k, int len) {
	int temp = A[k];  // 暂存子树的根节点
	for (int i = 2 * k + 1; i < len; i = 2 * i + 1) {  // 沿key较大的子节点向下筛选
		if (i + 1 < len && A[i] < A[i + 1]) 
			i++;  // 取key较大的子节点的下表
		if (temp >= A[i])  
			break;  // 筛选结束
		else {
			A[k] = A[i];  //将A[i]的值调整到双亲节点上
			k = i;  // 修改k值，以便继续向下筛选
		}
	}
	A[k] = temp;  // 被筛选节点的值放入最终位置
}
// 建立大根堆
void BuildMaxHeap(int A[], int len) {
	for (int i = len / 2 - 1; i >= 0; i--)  // 从后往前调整所有非终端结点
		HeadAdjust(A, i, len);
}
// 堆排序的完整逻辑
void HeapSort(int A[], int len) {
	BuildMaxHeap(A, len);  // 初始建堆
	for (int i = len - 1; i > 0; i--) {  // n-1趟的交换和建堆过程
		Swap(&A[i], &A[0]);  // 堆顶元素和堆底元素交换
		HeadAdjust(A, 0, i);  // 把剩余的待排序元素整理成堆
	}
}