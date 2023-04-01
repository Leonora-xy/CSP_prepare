#include <stdio.h>

int main () {
	int n, m;
	scanf("%d", &n);
	
	
	int min = 0, max = 0, tmp = 0;
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &m);
		if (tmp != m) {
			min += m;
			max += m;
		} else {
			max += tmp;
		}
		tmp = m;
	}
	printf("%d\n%d", max, min);
	return 0;
}
