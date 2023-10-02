int temp[30][30];
void RedixSort(int A[], int n) {
	int i = 0, j = 0, pos = 0;
	for (int k = 10;k < 10000;k *= 10) {
		for (int i = 0;i < n;i++) {
			int j = 0;
			int pos = (A[i] % k) / (k / 10);
			while (temp[pos][j])
				j++;
			temp[pos][j] = A[i];
		}
		int pos = 0;
		for (int i = 0;i < 10;i++) {
			for (j = 0;j < n&& temp[i][j]!=0;j++) {
				if (temp[i][j] != 0) {
					A[pos++] = temp[i][j];
					temp[i][j] = 0;
				}
			}
		}
	}
}