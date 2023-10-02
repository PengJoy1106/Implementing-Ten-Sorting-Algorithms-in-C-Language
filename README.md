# Implementing Ten Sorting Algorithms in C Language
# 排序算法
## 内部排序
数据都在内存中
==关注如何使算法时、空复杂度更低==
## 外部排序
数据太多，无法全部放入内存中
还要关注如何使读/写磁盘次数更少
# 插入排序
## 算法思想
每次将一个待排序的记录按其关键字大小插入到前面已排好序的子序列中，直到全部记录插入完成。
## 算法实现
![image.png|200](https://blog-1310087999.cos.ap-nanjing.myqcloud.com/20230929172225.png)
```C
//直接插入排序
void InsertSort(int A[],int n){
	int i,j,temp;
	for(i = 1;i < n;i++){   // 将各元素插入已排好的序列中
		if(A[i] < A[i-1]){  // 若A[i]关键字小于前驱
			temp = A[i];  // 用temp暂存A[i]
			for(j = i-1;j >= 0 && A[j] > temp;--j) //检查所有前面已排好序的元素
				A[j+1] = A[j];  // 所有大于temp的元素都向后挪位
			A[j+1] = temp;  // 复制到插入位置
		}
	}
}
```
```C
// 直接插入排序（带哨兵）
void InsertSort(int A[],int n){
	int i,j;
	for(i = 2;i <= n;i++){  // 依次将A[2]~A[n]插入到前面已排序序列
		if(A[i] < A[i-1]){  // 若A[i]关键码小于其前驱，将A[i]插入有序表
		 A[0] = A[i];  // 复制为哨兵 A[0]不存放元素
		 for(j = i-1; A[0] < A[j];--j)  // 从后往前查找待插入位置
		 	A[j+1] = A[j];  // 向后挪位
		 A[j+1] = A[0];  // 复制插入位置
		 }
	}
}
```
**优点**：不用每轮循环都判断 $j>=0$  （不明显）
## 算法性能分析
空间复杂度：$O(1)$
时间复杂度：主要来自对于关键字、移动元素；若有n个元素，则需要n-1趟处理
最好时间复杂度（全部有序）：$O(n)$
最坏时间复杂度（全部逆序）：$O(n^2)$
平均时间复杂度：$O(n^2)$
算法稳定性：稳定
# 希尔排序
## 算法思想
先将待排序表分割成若干形如$L[ i,i+d,i+2d,…,i+kd ]$的特殊子表对各个子表分别进行直接插入排序。缩小增量d，重复上述过程，直到**d=1**为止
## 算法实现
```C
// 希尔排序
void ShellSort(int A[],int n){
	int d,i,j;
	// A[0]只是暂存单元，不是哨兵，当j>0时，插入位置已到
	for(d=n/2;d>=1,d=d/2)  // 步长变化
		for(i=d+1;i<=n;++i)
			if(A[i]<A[i-d]){  // 需将A[i]插入有序增量子表
				A[0]=A[i];  // 暂存在A[0]
				for(j=i-d;j>0&&A[0]<A[j];j=d)  // 
					A[j+d]=A[j];  // 记录后移，查找插入的位置
				A[j+d]=A[0];  // 插入
			}
}
```
## 算法性能分析
**空间复杂度**：$O(1)$
**时间复杂度**：和增量序列$d_1,d_2,d_3,…$的选择有关，最坏时间复杂度为$O(n^2)$，当$n$在某个范围时，可达$O(n^{1.3})$
**稳定性**：不稳定
**适用性**：仅适用于顺序表，不适用于链表
# 冒泡排序
## 算法思想
1. 从后往前（或从前往后）两两比较相邻元素的值，若为逆序（即$A[i-1]>A[i]$），则交换它们，直到序列比较完。称这样的过程为“一趟”冒泡排序。
2. 每一趟排序都可以使一个元素移动到最终位置，已经确定最终位置的元素在之后的处理中无需再对比。
3. **如果某一趟排序过程中未发生交换，则算法可以提前结束**。
## 算法实现
```C
// 交换
void Swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
// 冒泡排序 (从后往前冒泡)
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
```
## 算法性能分析
空间复杂度：$O(1)$
时间复杂度：最好情况：$O(n)$，最坏情况：$O(n^2)$
平均时间复杂度：$O(n^2)$
稳定性：稳定
# 快速排序
## 算法思想
在待排序表$L[1…n]$中任取一个元素$pivot$作为枢轴（或基准，通常取首元素），通过一趟排序将待排序表划为独立的两部分$L[1…K-1]$和$L[K+1…n]$，使得$L[1…K-1]$中所有元素都小于$pivot$，$L[K+1…n]$中的所有元素大于等于$pivot$，则$pivot$放在了其最终位置上$L(K)$上，这一过程称为划分。然后分别递归地对两个子表重复上述过程，直至每部分只有一个元素或空为止，即所有元素放在了其最终位置上。
## 算法实现
```C
// 用第一个元素将待排序序列划分为左右两个部分
int Partition(int A[], int low, int high) {
	int pivot = A[low];  // 第一个元素作为枢轴
	while (low < high) {  // 用low和high搜索枢轴的最终位置
		while (low < high && A[high] >= pivot) --high;   
		A[low] = A[high];  // 比枢轴小的元素移到左端
		while (low < high && A[low] <= pivot) ++low;  
		A[high] = A[low];  // 比枢轴大的元素移动到右端
	}
	A[low] = pivot;  // 枢轴元素存放到最终位置
	return low;  // 返回存放枢轴的最终位置
}
// 快速排序
void QuickSort(int A[], int low, int high) {
	if (low < high) {  // 递归跳出的条件
		int pivotpos = Partition(A, low, high);  // 划分
		QuickSort(A, low, pivotpos - 1);  // 划分左子表
		QuickSort(A, pivotpos + 1, high);  // 划分右子表
	}
}
```
## 算法性能分析
空间复杂度：$O(递归层数)$       最好：$O(log_2{n})$    最坏：$O(n)$
时间复杂度：$O(n*递归层数)$ 最好：$O(nlog_2{n})$ 最坏：$O(n^2)$
平均时间复杂度：$O(nlog_2{n})$
最好情况时：每次选的枢轴元素都能将序列划分成均匀的两部分
最坏情况时：若序列原本就有序或逆序，则时、空复杂度最高（可优化，尽量选择可以把数据中分的枢轴元素）
稳定性：不稳定
# 选择排序
## 算法思想
每一趟在待排序元素中选取关键字最小的元素加入有序子序列
## 算法实现
```C
void SelectSort(int A[], int n) {
	for (int i=0; i < n - 1;i++) {  // 一共进行n-1趟
		int min = i;  // 记录最小元素位置
		for (int j = i + 1;j < n;j++)  // 在A[i…n-1]中选择最小的元素
			if (A[j] < A[min]) min = j;  // 更新最小元素位置
		if (min != i) Swap(&A[i], &A[min]);  // 封装的Swap()函数共移动元素3次
	}
}
```
## 算法性能分析
空间复杂度：$O(1)$
时间复杂度：$O(n^2)$
稳定性：不稳定
适用性：既可以用于顺序表，也可用于链表
# 堆排序
## 算法思想

## 算法实现
```C
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
```
## 算法性能分析
建堆时时间复杂度：$O(n)$
排序时时间复杂度不超过：$O(h)=O(log_2{n})$
堆排序的时间复杂度：$O(n)+O(nlog_2{n})=O(nlog_2{n})$
空间复杂度：$O(1)$
稳定性：不稳定
# 归并排序
## 算法思想
把两个或多个已经有序的序列合并成一个
## 算法实现
```C
 int *B = (int*)malloc((high - low + 1) * sizeof(int));
//int B[8] = {0,0,0,0,0,0,0,0};
// A[low…mid]和A[mid…high]各自有序，将两个部分归并
void Merge(int A[], int low, int mid, int high) {
	int i, j, k;
	for (k = low;k <= high;k++)
		B[k] = A[k];
	for (i = low, j = mid + 1, k = i;i <= mid && j <= high;k++) {
		if (B[i] <= B[j]) 
			A[k] = B[i++];  // 将较小值复制到A中
		else 
			A[k] = B[j++];
	}
	while (i <= mid) A[k++] = B[i++];
	while (j <= high) A[k++] = B[j++];
}
void MergeSort(int A[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;  // 从中间划分
		MergeSort(A, low, mid);  // 对左半部分归并排序
		MergeSort(A, mid + 1, high);  // 对右半部分归并排序
		Merge(A, low, mid, high);  //  归并
	}
}
```
## 算法效率分析
时间复杂度：$O(nlog_2{n})$
空间复杂度：$O(n)$
稳定性：稳定
# 计数排序
## 算法思想
统计原来数组的数据，并将数据转换成下标存储于一个临时的空间中，然后变量临时空间把对应的下表值放回原数组，当遍历临时空间完成后，原来的数组就是排好序了。
## 算法实现
```C
#define N 10
int B[N];
void CountSort(int A[], int n) {
	for (int i = 0;i < n;i++)
		B[A[i]]++;
	for (int i = 0, j = 0;i < N;i++)
		while (B[i]--)
			A[j++] = i;
}
```
# 基数排序
## 算法思想
## 算法实现
```C
int B[10][8];
void RedixSort(int A[], int n) {
	int i ,j, pos;
	for (int k = 10;k < 10000;k *= 10) {
		for (int i = 0;i < n;i++) {
			int j = 0;
			int pos = (A[i] % k) / (k / 10);
			while (B[pos][j])
				j++;
			B[pos][j] = A[i];
		}
		int pos = 0;
		for (int i = 0;i < 10;i++) {
			for (j = 0;j < n&&B[i][j]!=0;j++) {
				if (B[i][j] != 0) {
					A[pos++] = B[i][j];
					B[i][j] = 0;
				}
			}
		}
	}
}
```
