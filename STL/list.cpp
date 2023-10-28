/*
	list（链表）是一种物理存储单元上非连续、非顺序的存储结构，
	数据元素的逻辑顺序是通过链表中的指针链接次序实现的。
	链表由一系列结点（链表中的每一个元素称为结点）组成，结点可以在运行时动态生成。
	每个结点包含两个部分：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域。
	list 的好处是每次插入或者删除一个元素，就是配置或者释放一个元素的空间。
	对于任意元素的插入或移除，list 永远是常数时间。
	list 容器是一个双向链表。
*/
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// 遍历链表
void printListInt(list<int> &l)
{
	list<int>::iterator it = l.begin();
	for (; it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// list 容器的API
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

	// list 容器的迭代器是双向迭代器，不支持+2（直接加一个数），支持++（++运算符可以重载）
	list<int>::iterator it = l1.begin();
	// it + 2;	不能直接加一个数
	it++;
	it++;
	l1.insert(it,3, 100);
	printListInt(l1);	// 60 50 100 100 100 40 10 20 30

	// STL 提供的算法，只支持随机访问迭代器，而 list 是双向迭代器，所以 sort 不支持 list
	// sort(l1.begin(), l1.end());
	// list 排序使用 list 自己的函数
	l1.sort();
	printListInt(l1);	// 10 20 30 40 50 60 100 100 100
	// 反转 list 中的元素
	l1.reverse();
	printListInt(l1);	// 100 100 100 60 50 40 30 20 10
}

int main()
{
	test();
	return 0;
}