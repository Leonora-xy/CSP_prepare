#include <stdio.h>
#include <iostream>
#include <string>
#include <ctype.h>
#include <queue>
#include <cmath>
const int MAXN = (1000);
const int MOD = 929;

long long xishu[10][10];

using namespace std;

queue<int> seq; 
vector<int> ans;

long long leftequal[MAXN];
long long qx[MAXN];

void calculate(string str) {
	int last = -1;
	// 计算码字
	for (int i = 0; i < str.length(); i++) {
		if (isupper(str[i])) {
			// 大写 0
			switch (last) {
				case 1:
					// 小写转大写
					seq.push(28);
					seq.push(28);
					seq.push(str[i]-'A'); 
					break;
				case 2:
					// 数字转大写 
					seq.push(28);
					seq.push(str[i]-'A');
					break;
				default:
					seq.push(str[i]-'A');
					break; 
			}
			last = 0;
		} else if (islower(str[i])) {
			// 小写 1
			switch (last) {
				case 0:
				case -1:
					// 大写转小写 
					seq.push(27);
					seq.push(str[i]-'a');
					break;
				case 2:
					// 数字转小写 
					seq.push(27);
					seq.push(str[i]-'a'); 
					break;
				default:
					seq.push(str[i]-'a');
					break; 
			}
			last = 1;
		} else {
			// 数字 
			switch (last) {
				case 0:
				case -1:
					// 大写转数字 
					seq.push(28);
					seq.push(str[i] - '0');
					break;
				case 1:
					// 小写转数字 
					seq.push(28);
					seq.push(str[i]-'0'); 
					break;
				default:
					seq.push(str[i]-'0');
					break; 
			}
			last = 2; 
		}
	}
	if (seq.size() % 2 != 0) {
		seq.push(29);
	} 
	// 组合码字
	while (seq.size() != 0) {
		int a = seq.front();
		seq.pop();
		int b = seq.front();
		seq.pop();
		ans.push_back(30*a+b);
	} 
}

void calxishu() {
	xishu[1][0] = -3;
	xishu[1][1] = 1;
	for (int i = 2; i <= 8; i++) {
		// 计算(x-3^i)*xishu[i-1]
		// 计算x 
		for (int j = 0; j < i; j++) {
			xishu[i][j+1] += xishu[i-1][j];//*x 
			// *-3^i
			xishu[i][j] += xishu[i-1][j]*(-pow(3, i));
		} 
	}
} 

void calLeft(int k, int n) {
	leftequal[n-1+k] = n;
	for (int i = 0; i < ans.size(); i++) {
		leftequal[n-1-i+k-1] = ans[i];
	}
}

void calqx(int k, int n) {
	// xishu[k]
	// leftequal
	int begin = n-1+k;
	for (int i = begin-k; i>= 0; i--, begin--) {
		int tmp = leftequal[begin];
		// 更新left参数 
		for (int j = k; j >= 0; j--) {
			leftequal[j+i] -= xishu[k][j]*tmp;
		}
	} 
	//now leftequal
	 
}


int main () {
	int w, s;
	cin >> w >> s;
	string str;
	cin >> str;
	
	calculate(str);// 计算码字 
	int k = (s == -1 ? 0 : pow(2, s+1));
	int n = (((ans.size() + k)/ w) + 1) * w - k;
	cout << n << endl;
	n--;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
		n--;
	}
	for (int i = 0; i < n ; i++) {
		ans.push_back(900);
		cout << 900 << endl;
	}
	
	// 计算校验码 
	n = (((ans.size() + k)/ w) + 1) * w - k;
	if (s != -1 && s <= 2) {
		// 计算系数
		calxishu();
		calLeft(k, n);
		calqx(k, n);
		for (int i = k-1; i>= 0; i--) {
			int tmp = -leftequal[i] % MOD;
			if (tmp < 0) {
				tmp += MOD;
			}
			cout << tmp << endl;
		}
	} 
	
	return 0;
}
