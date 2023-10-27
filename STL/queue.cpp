/*
	queue ��һ���Ƚ��ȳ������ݽṹ�����У���
	�����������ڣ�queue ���������һ������Ԫ�أ�����һ���Ƴ�Ԫ�ء�
	queue ������Ԫ�صĽ�����������ϡ��Ƚ��ȳ�����������ֻ�� queue	�Ķ���Ԫ�ز��л��ᱻ���ȡ�á�
	queue ���ṩ�������ܣ�Ҳ���ṩ��������
*/
#include <iostream>
#include <queue>

using namespace std;

// queue ����API
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
		cout << "���еĴ�С��" << q.size() << endl;
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