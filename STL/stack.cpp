/*
	stack ��һ���Ƚ���������ݽṹ��ջ������ֻ��һ�����ڡ�
	stack ������������Ԫ�أ��Ƴ�Ԫ�أ�ȡ��ջ��Ԫ�أ�
	���ǳ�������⣬û���κ������������Դ�ȡ stack ������Ԫ�ء�
	����֮��stack �������б�����Ϊ��Ҳû�е�������
*/
#include <iostream>
#include <stack>

using namespace std;

// stack ����API
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
		cout << "ջ�Ĵ�С��" << s.size() << endl;
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