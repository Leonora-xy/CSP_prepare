#include <stdio.h>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<int> values;// 创建stack容器
	stack<string> strStack;
	// 初始化
	stack<int> initInt ({1, 2, 3});
	// 返回一个栈顶元素的引用，类型为 T&。
	// 如果栈为空，程序会报错
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
	initInt.pop();// 返回值为void 
	printf("%d\n", a);//123
	// emplace:在当前栈顶元素上方插入新元素
	initInt.emplace(99);
	printf("%d\n", initInt.top());
}
