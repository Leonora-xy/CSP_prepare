#include <stdio.h>
#include <stdlib.h> 

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

int main() {
	int n;
	scanf("%d", &n);
	int *A = (int *)malloc(sizeof(int) * n);
	
	int i, m;
	for (i = 0; i < n; i++) {
		scanf("%d", &m);
		A[i] = m;
	}
	mergeSort(A, 0, n-1, n);
	
	for (i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	return 0;
}
