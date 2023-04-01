#include <stdio.h>
#include <iostream>
//#include <cmath>
//#define abx(x) ((x > 0) ? (x) : (-x))
using namespace std;
long long sum = 0;

int abx(int x) {
	return x > 0 ? x : -x;
}

void calculate(int r, int begin, int end, int fx) {
	// [begin, end] 
	int gx = begin / r;
	if (gx == end / r) {
		sum +=  (end - begin + 1)*abx(gx - fx);
	} else {
		// ¿çÔ½ 
		int front = (r*(gx+1) - 1);
		sum += (front - begin + 1)*abx(gx - fx); 
		int j;
		for (j = front + 1; j + r <= end && j <= end; j += r) {
			sum += r*abx(j/r - fx);
		}
		if (j <= end) {
			sum += (end - j + 1) * abx(j/r - fx);
		}
	}
}

int main () {
	int n, N;
	cin >> n >> N;
	
	int begin = 0;
	int r = N / (n+1);
	int i, gx, tmp;
	for (i = 0; i < n; i++) {
		cin >> tmp;
		int end = tmp - 1;
		calculate(r, begin, end, i);
		begin = tmp;
	}
	calculate(r, begin, N-1, i);
	cout << sum;
	return 0;
} 
