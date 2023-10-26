/*
	v.rend() 指向vector容器第0个元素的前一个位置
	v.begin() 获取vector容器的起始迭代器（迭代器与容器一一对应）
	v.end() 获取vector容器的结束迭代器（指向vector容器最后一个元素的下一个位置）

	未雨绸缪机制：当vector容器放满时，会扩展原先两倍的空间；
				但并不会在原空间之后续接新空间，而是另找一块更大的内存空间，将原数据拷贝至新空间，并将原空间释放。
*/
#include <iostream>
#include <vector>
#include <algorithm>	// STL 算法
#include <string>

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
void Expansion()
{
	vector<int> v1;
	cout << "容量：" << v1.capacity() << " 大小：" << v1.size() << endl;
	/*v1.push_back(1);*/

	vector<int>::iterator it = v1.begin();

	int count = 0;

	for (int i = 0; i < 1000; i++)
	{
		v1.push_back(i);

		// 有错误，程序会崩溃，迭代器不兼容
		if (it != v1.begin())
		{
			count++;
			cout << "第" << count << "次开辟空间，容量：" << v1.capacity() << endl;
			it = v1.begin();
		}
	}
}

// vector 大小操作
void Size()
{
	vector<int> v1;
	if (v1.empty())
	{
		cout << "空" << endl;
	} else
	{
		cout << "非空" << endl;
	}

	vector<int> v2(10, 30);
	cout << "v2容量：" << v2.capacity() << "，v2大小：" << v2.size() << endl;
	printVectorInt(v2);
	// 重置大小
	// v2.resize(15);	// 过大，默认补0
	// v2.resize(15, 2);	// 自定义过大时补2
	v2.resize(5);	// 过小删除多余部分
	printVectorInt(v2);
}

// vector 数据存取操作
void Access()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);	// 10 20 30 40 50

	cout << "头元素：" << v1.front() << "，尾元素：" << v1.back() << endl;
	// at越界会抛出异常，[]越界不会抛出异常
	cout << v1[1] << " " << v1.at(1) << endl;
	v1.at(1) = 200;
	v1[3] = 400;
	printVectorInt(v1);	// 10 200 30 400 50
}

// vector 插入和删除操作
void InsertDelete()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	// 尾部删除
	v1.pop_back();
	printVectorInt(v1);	// 10 20 30 40
	// 插入
	v1.insert(v1.begin() + 2, 3, 500);
	printVectorInt(v1);	// 10 20 500 500 500 30 40

	// 区间删除
	v1.erase(v1.begin() + 2, v1.begin() + 5);
	printVectorInt(v1);	// 10 20 30 40

	// 清空容器
	v1.clear();
	cout << "v1容量：" << v1.capacity() << "，v1大小：" << v1.size() << endl;
}

// vector swap收缩空间
void Swap()
{
	vector<int> v1;
	v1.reserve(1000);
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	cout << "v1容量：" << v1.capacity() << "，v1大小：" << v1.size() << endl;	// 1000 4
	// resize 只能修改大小 不能修改容量
	// 
	// 创建一个匿名对象，将v1拷贝给匿名对象，再将v1和匿名对象进行交换
	// 当v1和匿名对象进行拷贝时，不会拷贝v1的容量，只会拷贝v1的大小
	// 所以将v1与拷贝后的匿名对象交换后，v1的容量就会收缩
	vector<int>(v1).swap(v1);
	cout << "v1容量：" << v1.capacity() << "，v1大小：" << v1.size() << endl;	// 4 4
}

// vector 案例
void Case()
{
	vector<int> v1(5, 10);
	vector<int> v2(5, 100);
	vector<int> v3(5, 1000);

	// 需求：定义一个 vector 容器存放 v1,v2,v3
	vector<vector<int>> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	// 遍历
	vector<vector<int>>::iterator it = v.begin();	// 定义迭代器
	for (; it != v.end(); it++)
	{
		// *it == vector<int> 
		vector<int>::iterator mit = (*it).begin();
		for (; mit != (*it).end(); mit++)
		{
			cout << *mit << " ";
		}
		cout << endl;
	}
}

// 使用 STL 算法对 vector 容器排序
void Sort()
{
	vector<int> v1;
	v1.push_back(40);
	v1.push_back(20);
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(60);
	v1.push_back(50);
	printVectorInt(v1);

	// 排序算法
	sort(v1.begin(), v1.end());
	printVectorInt(v1);
}

// vector 存放自定义数据
// 自定义类
class Person
{
	// 自定义遍历
	friend void printVectorPerson(vector<Person> &v);
	// 自定义比较规则
	friend bool comparePerson(Person &p1, Person &p2);
public:
	Person()
	{};
	Person(int num, string name, float score)
	{
		this->num = num;
		this->name = name;
		this->score = score;
	}	
	~Person()
	{};

private:
	int num;
	string name;
	float score;
};

// 自定义遍历
void printVectorPerson(vector<Person> &v)
{
	vector<Person>::iterator it = v.begin();
	for (; it != v.end(); it++)
	{
		// *it == Preson
		cout << (*it).num << "  " << (*it).name << "  " << (*it).score << endl;
	}
}

// 自定义比较规则
bool comparePerson(Person &p1, Person &p2)
{
	return p1.num < p2.num;
}

void Custom()
{
	vector<Person> v1;
	v1.push_back(Person(105, "lucy", 67.7f));
	v1.push_back(Person(103, "bob", 77.7f));
	v1.push_back(Person(101, "tom", 87.7f));
	v1.push_back(Person(104, "德玛", 97.7f));
	v1.push_back(Person(102, "小法", 57.7f));
	printVectorPerson(v1);

	// 对自定义类型的 vector 排序，需要指定排序规则
	sort(v1.begin(), v1.end(),comparePerson);
	printVectorPerson(v1);

}

int main()
{
	// StructureAssignment();
	Expansion();
	// Size();
	// Access();
	// InsertDelete();
	// Swap();
	// Case();
	// Sort();
	// Custom();
	return 0;
}