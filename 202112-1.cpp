#include <stdio.h>
#include <iostream>
using namespace std;

int main () {
	int n, N;
	cin >> n >> N;
	
	int last = 0;
	int tmp;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		sum += i * (tmp - last);
		last = tmp;
	}
	sum += (N - last) * n;
	cout << sum;
	return 0;
} 
