#include <stdio.h>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<int> values;// ����stack����
	stack<string> strStack;
	// ��ʼ��
	stack<int> initInt ({1, 2, 3});
	// ����һ��ջ��Ԫ�ص����ã�����Ϊ T&��
	// ���ջΪ�գ�����ᱨ��
	printf("%d\n", initInt.top());// 3
	// empty(),size()
	if (initInt.empty()) {
		printf("this is empty\n");
	} else {
		printf("the size is %d\n", initInt.size());//
	}
	// push()\pop()
	initInt.push(123);
	int a = initInt.top();
	initInt.pop();// ����ֵΪvoid 
	printf("%d\n", a);//123
	// emplace:�ڵ�ǰջ��Ԫ���Ϸ�������Ԫ��
	initInt.emplace(99);
	printf("%d\n", initInt.top());
}
