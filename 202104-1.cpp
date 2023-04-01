#include <stdio.h>

int a[300];
int main() {
	int n, m, l;
	scanf("%d %d %d", &n, &m, &l);
	
	int i, j, k;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &k);
			a[k]++;
		}
	}
	
	for (i = 0; i < l; i++) {
		printf("%d ", a[i]); 
	}
} 
