/*
	stack 是一种先进后出的数据结构（栈），它只有一个出口。
	stack 容器允许新增元素，移除元素，取得栈顶元素，
	但是除了最顶端外，没有任何其他方法可以存取 stack 的其他元素。
	换言之，stack 不允许有遍历行为，也没有迭代器。
*/
#include <iostream>
#include <stack>

using namespace std;

// stack 容器API
void test()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	
	if (!s.empty())
	{
		cout << "栈的大小：" << s.size() << endl;
		while (!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}
}

int main()
{
	test();
	return 0;
}