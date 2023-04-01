#include <stdio.h>
#include <stdlib.h>
int iindex = -1;

void mergeSort(int arr[], int start, int end, int n) {
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	mergeSort(arr, start, mid, n);
	mergeSort(arr, mid+1, end, n);
	merge(arr, start, mid, end, n);
}

void merge(int arr[], int start, int mid, int end, int n) {
	int * result = (int *)malloc(sizeof(int) * n);
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (arr[i] < arr[j]) {
			result[k++] = arr[j++];
		} else {
			result[k++] = arr[i++];
		}
	}
	if (i == mid + 1) {
		while (j <= end) {
			result[k++] = arr[j++];
		}
	} 
	if (j == end + 1) {
		while (i <= mid) {
			result[k++] = arr[i++];
		}
	}
	for (j = 0, i = start; j < k; i++, j++) {
		arr[i] = result[j];
	}
} 

int mergeFind(int arr[], int start, int end, int p) {
	if (start == end) {
		if (arr[start] >= p) {
			return 1;
		} else {
			return 0;
		}
	}
	int mid = (start + end) / 2;
	int a = mergeFind(arr, start, mid, p);
	int b = mergeFind(arr, mid+1, end, p);
	if (arr[mid] >= p && arr[mid+1] >= p) {
		return a + b -1;
	} else {
		return a + b;
	}
}

int findMax(int arr[], int index) {
	if (index == -1) {
		iindex = index + 1;
	} else {
		int tmp = arr[iindex];
		int i;
		for (i = iindex; arr[i] >= tmp; i++);
		iindex = i;
	}
	return arr[iindex];
}

int main() {
	int n;
	scanf("%d", &n);
	int* A = (int *)malloc(sizeof(int) * n);
	int* B = (int *)malloc(sizeof(int) * n);
	int i = 0, p, m, flag = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &m);
		A[i] = m;
		B[i] = m;
		if (m != 0) {
			flag = 1;
		}
	}
	mergeSort(B, 0, n-1, n);
	
//	
//	for (i = 0; i < n; i++) {
//		printf("%d ", B[i]);
//	}
//	printf("\n");
//	找
	int now = 0, last = 0;
	if (flag == 0) {
		printf("0");
		return 0;
	}
	p = B[0];
	int*  C= (int *)malloc(sizeof(int) * n);
	i = 0;
	while (p != B[n-1]) {
		p = findMax(B, iindex);
//		printf("%d\n", p);
		now = mergeFind(A, 0, n-1, p);
		C[i] = now;// 必须列举所有的C的情况，C不一定是递减 
		i++;
	}
	mergeSort(C, 0, i-1, i);
	printf("%d", C[0]);
	return 0;
}
