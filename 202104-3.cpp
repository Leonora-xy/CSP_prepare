//#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

const int MAX = 10000 + 1;

typedef struct addr {
	int state;//状态 1 2 3 4
	string loc;
	int time; 
} ADDR;

ADDR pos[MAX];
void updataPos(int now, int N) {
	for (int i = 1; i <= N; i++) {
		if (pos[i].state == 2 && pos[i].time <= now) {
			pos[i].state = 1;
			pos[i].loc = "";
			pos[i].time = 0;
		}
		if (pos[i].state == 3 && pos[i].time <= now) {
			pos[i].state = 4;
			pos[i].time = 0;
		}
	}
}
int main() {
	int N, Tdef, Tmax, Tmin;
	string name;
	
	cin >> N >> Tdef >> Tmax >> Tmin >> name;
	
	for (int i = 1; i <= N; i++)	pos[i].state = 1;

	int n;
	cin >> n; 
//	scanf("%d", &n);
	
	string send, receive, type;
	int ip2, endTime, now;
	
	for (int i = 0; i < n; i++) {
		cin >> now >> send >> receive >> type >> ip2 >> endTime;
		// 更新时间
		updataPos(now, N); 
		if (!(receive == name || receive == "*") && type != "REQ") {
			continue;
		}
		if ((receive == "*" && type != "DIS") || (receive == name && type == "DIS")) {
			continue;
		}
		if (type == "DIS") {
			int select = 0, notAlloc = 0;
			int delay = 0;
			for (int i = 1; i <= N; i++) {
				if (pos[i].loc == send && pos[i].state != 1) {
					select = i;
					break;
				}
			}
			if (select == 0) {
				for (int i = 1; i <= N; i++) {
					if (pos[i].state == 1 && select == 0) {
						select = i;
						break; 
					}	
				}
			}
			if (select == 0) {
				for (int i = 1; i <= N; i++) {
					if (pos[i].state == 4 && select == 0) {
						select = i;
					} 
				}
			}
//				if (pos[i].state == 1 && notAlloc == 0) {
//						notAlloc = i;
//					}
//				if (pos[i].state == 4 && delay == 0) {
//					delay = i;
//				} 
			//找分配的ip 
//			if (select == 0) {
//				if (notAlloc == 0) {
//					if (delay == 0) {
//						select = 0;
//						continue;
//					} else {
//						select = delay;
//					}
//				} else {
//					select = notAlloc;
//				}
//			}
			if (select == 0) {
				continue;
			}
			pos[select].state = 2;
			pos[select].loc = send;
//			cout << pos[select].loc << endl;
			if (endTime == 0) {
				pos[select].time = now + Tdef;
			} else {
				if (endTime - now < Tmin) {
					pos[select].time = now + Tmin;
				} else if (endTime - now > Tmax) {
					pos[select].time = now + Tmax;
				} else {
					pos[select].time = endTime;
				}
			}
			cout << name << " " << send << " OFR " << select << " " << pos[select].time << endl; 
//			printf("%s %s OFR %d %d\n", name.c_str(), send.c_str(), select, pos[select].time);
		} else if (type == "REQ") {
			if (receive != name) {
				for (int i = 1; i <= N; i++) {
					if (pos[i].loc == send && pos[i].state == 2) {
						pos[i].state = 1;
						pos[i].loc = "";
						pos[i].time = 0;
					}
				}
				continue;
			}
//			cout << pos[ip2].loc << endl;
//			cout << send << endl;
			if (!(ip2 <= N && ip2 >= 1 && pos[ip2].loc == send)) {
				cout << name << " " << send << " NAK " << ip2 << " 0" << endl; 	
			} else {
				pos[ip2].state = 3;
				if (endTime == 0) {
					pos[ip2].time = now + Tdef;
				} else {
					if (endTime - now < Tmin) {
						pos[ip2].time = now + Tmin;
					} else if (endTime - now > Tmax) {
						pos[ip2].time = now + Tmax;
					} else {
						pos[ip2].time = endTime;
					}
				}
				cout <<  name << " " << send << " ACK " << ip2 << " " << pos[ip2].time << endl; 
			}
		}
	}
	
}
