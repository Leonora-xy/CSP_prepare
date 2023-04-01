#include <stdio.h>
#include <bits/stdc++.h>

int main() {
	int n, l, r, t;
	scanf("%d %d %d %d", &n, &l, &r, &t);
	
	int m = n+1;
	int **predSum = new int *[m];// 前缀和 
	int **array = new int *[m];// 保存数组值 
	for (int i = 0; i < m; i++) {
		predSum[i] = new int [m];// 留一个0 
		array[i] = new int [m];
	}
	
	memset(predSum, 0, sizeof(predSum));

//    for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= n;j++) {
//			printf("%d ", predSum[i][j]);
//		}
//		printf("\n");
//	} 
	for (int i = 1; i <= n; i++) {
		predSum[i][0] = 0;
		for (int j = 1; j <= n; j++) {
			scanf("%d", &array[i][j]);
			predSum[i][j] = predSum[i][j-1] + array[i][j];			
		}
	}
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n;j++) {
//			printf("%d ", predSum[i][j]);
//		}
//		printf("\n");
//	} 
	
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int top  = (i - r) < 1 ? 1: (i - r);
			int down = (i + r) > n ? n: (i + r);
			int l2    = (j - r) < 1 ? 1: (j - r);
			int r2    = (j + r) > n ? n: (j + r);
			 
			int sum = 0;
			for (int k = top; k <= down; k++) {
				sum += predSum[k][r2] - predSum[k][l2-1];// l-1不是l 
			} 
			
			if (sum <= t*(down-top+1)*(r2-l2+1)) {
				cnt++;
//				printf("%d %d\n", i, j);
			}
		}
	}
	
	printf("%d", cnt);
} 
