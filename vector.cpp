#include<iostream>
#include<list>
using namespace std;
bool comp(int first, int second) {
	bool a;
	a = first < second;
	return a;
}
int main()
{
    list<int> li={9,10,11, -1, 0, 14};
  list<int> li1={5,6,7,15};
  li.sort();
  for(list<int>::iterator itr=li.begin();itr!=li.end();++itr){
      std::cout << *itr <<" "<< std::endl;
  } 
  
  return 0;
}
