#include <iostream>
using namespace std;

const int MAXN = 1000 + 1;
const int MAXS = 1000 + 1;
const int MAXP = 1000 + 1;
const int MAXT = 100000 + 1;

struct nerve {
	double v;
	double u;
	double a;
	double b;
	double c;
	double d;
	int cnt; 
} nerve[MAXN]; 

struct tuchu {
	int s;
	int t;
	double w;
	int D;
} tuchu[MAXS];

int pulse[MAXP];
double Iw[MAXT][MAXN];


/* RAND_MAX assumed to be 32767 */
int myrand(void) {
	static unsigned long next = 1;
    next = next * 1103515245 + 12345;
    return((unsigned)(next/65536) % 32768);
}

void init(int N, int S, int P, int T, double dt) {
	// 输入神经元 
	for (int i = 0; i < N; ) {
		int Rn;
		double v, u, a, b, c, d;
		cin >> Rn >> v >> u >> a >> b >> c >> d;
		
		// 初始化神经元
		for (int j = i; j < i + Rn; j++) {
			nerve[j].a = a; nerve[j].b = b; nerve[j].c = c;
			nerve[j].d = d; nerve[j].u = u; nerve[j].v = v;
			nerve[j].cnt = 0;
		}
		//改变i
		i += Rn;
	}
	// 输入脉冲源 
	for (int i = 0; i < P; i++) {
		int r;
		cin >> r;
		// 初始化脉冲源的r 
		pulse[i] = r;
	}
	// 输入突触 
	for (int i = 0; i < S; i++) {
		int s, t, D;
		double w;
		cin >> s >> t >> w >> D;
		// 初始化突触 	
		tuchu[i].s = s; tuchu[i].t = t;
		tuchu[i].w = w; tuchu[i].D = D; 
	} 
}

int main() {
	
	int N, S, P, T;
	double dt;
	cin >> N >> S >> P >> T;
	cin >> dt;

	// 初始化 
	init(N, S, P, T, dt);
	
	// 开始模拟
	for (int sum = 1; sum <= T; sum++) {
		// 脉冲源发送脉冲
		for (int j = 0; j < P; j++) {
			if (pulse[j] > myrand()) {
				// 发送脉冲
				for (int k = 0; k < P; k++) {
					if (tuchu[k].s == j + N) {
						Iw[tuchu[k].D+sum][tuchu[k].t] += tuchu[k].w;
					}
				}
			}
		} 
		// 突触计算收到的脉冲
		for (int j = 0; j < N; j++) {
			double vlast = nerve[j].v;
			double ulast = nerve[j].u;
			double a = nerve[j].a;
			double b = nerve[j].b;
			nerve[j].v = vlast 
					+ dt*(0.04*vlast*vlast + 5*vlast + 140 - ulast) 
					+ Iw[sum][j];
			nerve[j].u = ulast + dt*a*(b*vlast - ulast); 
			if (nerve[j].v >= 30) {
				nerve[j].cnt++;
				nerve[j].v = nerve[j].c;
				nerve[j].u += nerve[j].d;
				
				// 发送脉冲 
				for (int k = 0; k < P; k++) {
					if (tuchu[k].s == j) {	
						Iw[tuchu[k].D+sum][tuchu[k].t] += tuchu[k].w;
					}
				}
			}
			printf ("v is %.3f, u is %.3f\n", nerve[j].v, nerve[j].u); 
		}
	}
	
	int cntmin = 2147483640, cntmax = 0;
	double vmax = -2147483640, vmin = 2147483640; 
	for (int i = 0; i < N; i++) {
		if (nerve[i].v < vmin) {
			vmin = nerve[i].v;
		}
		if (nerve[i].v > vmax) {
			vmax = nerve[i].v;
		}
		if (nerve[i].cnt < cntmin) {
			cntmin = nerve[i].cnt;
		}
		if (nerve[i].cnt > cntmax) {
			cntmax = nerve[i].cnt;
		}
	}
	printf("%.3f %.3f\n", vmin, vmax);
	printf("%d %d", cntmin, cntmax);
}
