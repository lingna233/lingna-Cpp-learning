/*
	set 的特性是所有元素都会根据元素的键值（索引值）自动被排序，set 的元素即是键值又是实值（只有键值没有实值）。
	set 不允许两个元素有相同的键值。(内部使用平衡二叉树管理)
	multiset 特性及用法和 set 完全相同，唯一的区别在于它允许键值重复。
*/
#include <iostream>
#include <set>

using namespace std;

// 遍历 set 容器
template <typename T>
void printSetInt(const T &s)
{
	// set 容器的迭代器是只读迭代器，防止用户更改 set 容器内容，破坏容器的布局。
	typename T::const_iterator it = s.begin();
	for (; it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// 仿函数：重载函数调用运算符()的类
class MyGreater
{
public:

	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};


// set 容器API
void test01()
{
	set<int> s1;
	s1.insert(30);
	s1.insert(20);
	s1.insert(10);
	s1.insert(30);	// 重复了，无法插入到 s1 中
	s1.insert(40);
	printSetInt(s1);	// 10 20 30 40	默认从小到大

	// set<int，排序规则> s1;		
	// <>中的排序规则必须既是函数也是类型，
	// 所以排序规则为 “仿函数”
	set<int, MyGreater> s2;
	s2.insert(30);
	s2.insert(20);
	s2.insert(10);
	s2.insert(50);
	s2.insert(40);
	printSetInt(s2);	// 50 40 30 20 10	更改排序规则为从大到小
}

// set 存放自定义数据必须修改排序规则
class MyGreaterPerson;	// 提前申明
class Person
{
	friend class MyGreaterPerson;
	friend void printSetPerson(set<Person, MyGreaterPerson> &s);
public:
	Person();
	Person(int num, string name, int score);
	~Person();

private:
	int num;
	string name;
	int score;
};

Person::Person()
{}

Person::Person(int num, string name, int score)
{
	this->num = num;
	this->name = name;
	this->score = score;
}

Person::~Person()
{}

class MyGreaterPerson
{
public:

	bool operator()(Person ob1, Person ob2) const
	{
		return ob1.num > ob2.num;
	}
};

void printSetPerson(set<Person, MyGreaterPerson> &s)
{
	set<Person, MyGreaterPerson>::const_iterator it = s.begin();
	for (; it != s.end(); it++)
	{
		// *it == Person
		cout << (*it).num << " " << (*it).name << " " << (*it).score << " ";
	}
	cout << endl;
}

void test02()
{
	set<Person, MyGreaterPerson> s;
	s.insert(Person(101, "lucy", 88));
	s.insert(Person(103, "tom", 98));
	s.insert(Person(105, "bob", 80));
	s.insert(Person(104, "coco", 90)); 
	s.insert(Person(102, "lili", 95));
	printSetPerson(s);
}

int main()
{
	test01();
	test02();
	return 0;
}