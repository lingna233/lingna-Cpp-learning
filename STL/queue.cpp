/*
	queue 是一种先进先出的数据结构（队列），
	它有两个出口，queue 容器允许从一端新增元素，从另一端移除元素。
	queue 的所有元素的进出都必须符合“先进先出”的条件，只有 queue	的顶端元素才有机会被外界取用。
	queue 不提供遍历功能，也不提供迭代器。
*/
#include <iostream>
#include <queue>

using namespace std;

// queue 容器API
void test()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	
	if (!q.empty())
	{
		cout << "队列的大小：" << q.size() << endl;
		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}
}

int main()
{
	test();
	return 0;
}