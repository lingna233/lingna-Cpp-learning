/*
	list��������һ������洢��Ԫ�Ϸ���������˳��Ĵ洢�ṹ��
	����Ԫ�ص��߼�˳����ͨ�������е�ָ�����Ӵ���ʵ�ֵġ�
	������һϵ�н�㣨�����е�ÿһ��Ԫ�س�Ϊ��㣩��ɣ�������������ʱ��̬���ɡ�
	ÿ���������������֣�һ���Ǵ洢����Ԫ�ص���������һ���Ǵ洢��һ������ַ��ָ����
	list �ĺô���ÿ�β������ɾ��һ��Ԫ�أ��������û����ͷ�һ��Ԫ�صĿռ䡣
	��������Ԫ�صĲ�����Ƴ���list ��Զ�ǳ���ʱ�䡣
	list ������һ��˫������
*/
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// ��������
void printListInt(list<int> &l)
{
	list<int>::iterator it = l.begin();
	for (; it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// list ������API
void test()
{
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_front(40);
	l1.push_front(50);
	l1.push_front(60);

	printListInt(l1);	// 60 50 40 10 20 30

	// list �����ĵ�������˫�����������֧��+2��ֱ�Ӽ�һ��������֧��++��++������������أ�
	list<int>::iterator it = l1.begin();
	// it + 2;	����ֱ�Ӽ�һ����
	it++;
	it++;
	l1.insert(it,3, 100);
	printListInt(l1);	// 60 50 100 100 100 40 10 20 30

	// STL �ṩ���㷨��ֻ֧��������ʵ��������� list ��˫������������� sort ��֧�� list
	// sort(l1.begin(), l1.end());
	// list ����ʹ�� list �Լ��ĺ���
	l1.sort();
	printListInt(l1);	// 10 20 30 40 50 60 100 100 100
	// ��ת list �е�Ԫ��
	l1.reverse();
	printListInt(l1);	// 100 100 100 60 50 40 30 20 10
}

int main()
{
	test();
	return 0;
}