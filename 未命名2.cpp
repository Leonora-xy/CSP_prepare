#include <bits/stdc++.h>

using namespace std;

const int N = 600 + 1;
int a[N][N], prefixsum[N][N];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(prefixsum, 0, sizeof prefixsum);
    for (int i = 0; i < N; i++) {
		for (int j = 0; j < N;j++) {
			printf("%d ", prefixsum[i][j]);
		}
		printf("\n");
	} 

    int n, l, r, t;
    cin >> n >> l >> r >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            prefixsum[i][j] = prefixsum[i][j - 1] + a[i][j];
        }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            int l2 = j - r < 1 ? 1 : j - r;
            int r2 = j + r > n ? n : j + r;
            int u = i - r < 1 ? 1 : i - r;
            int d = i + r > n ? n : i + r;
            int t2 = 0;
            for (int k = u; k <= d; k++)
                t2 += prefixsum[k][r2] - prefixsum[k][l2 - 1];
            if (t2 <= (d - u + 1) * (r2 - l2 + 1) * t) {
            	cnt++;
				cout << i <<" " <<j <<endl;	
			}
        }

    cout << cnt << endl;

    return 0;
}
