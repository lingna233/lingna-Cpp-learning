/*
	v.rend() 指向vector容器第0个元素的前一个位置
	v.begin() 获取vector容器的起始迭代器（迭代器与容器一一对应）
	v.end() 获取vector容器的结束迭代器（指向vector容器最后一个元素的下一个位置）

	未雨绸缪机制：当vector容器放满时，会扩展原先两倍的空间；
				但并不会在原空间之后续接新空间，而是另找一块更大的内存空间，将原数据拷贝至新空间，并将原空间释放。
*/
#include <iostream>
#include <vector>

using namespace std;

// 打印vector
void printVectorInt(vector<int> &v)
{
	vector<int>::iterator it = v.begin();
	for (; it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

// vector 构造和赋值操作
void StructureAssignment()
{
	// 采用模板实现类实现，默认构造函数
	vector<int>	v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	// 遍历该容器
	// 定义一个迭代器 iterator 保存起始迭代器
	vector<int>::iterator it = v1.begin();
	for (; it != v1.end(); it++)
	{
		// *it == int 但不是指针
		cout << *it << "  ";
	}
	cout << endl;
	// 5个100
	vector<int> v2(5, 100);
	printVectorInt(v2);
	// 区间构造
	vector<int> v3(v2.begin(), v2.end());
	printVectorInt(v3);

	// 赋值
	vector<int> v4;
	// v4 = v1;
	
	// 区间赋值
	// v4.assign(v1.begin(), v1.end());

	// 赋值n个元素（10个10）
	v4.assign(10, 10);
	printVectorInt(v4);

	// 交换
	v4.swap(v2);
	printVectorInt(v4);
	printVectorInt(v2);
}

// veactor 插入数据时的未雨绸缪机制
void expansion()
{
	vector<int> v1;
	cout << "容量：" << v1.capacity() << " 大小：" << v1.size() << endl;

	vector<int>::iterator it;

	int count = 0;

	for (int i = 0; i < 1000; i++)
	{
		v1.push_back(i);

		// 有错误，程序会崩溃
		if (it != v1.begin())
		{
			count++;
			cout << "第" << count << "次开辟空间，容量：" << v1.capacity() << endl;
			it = v1.begin();
		}

	}

}



int main()
{
	StructureAssignment();
	// expansion();

	return 0;
}