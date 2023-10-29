/*
	set ������������Ԫ�ض������Ԫ�صļ�ֵ������ֵ���Զ�������set ��Ԫ�ؼ��Ǽ�ֵ����ʵֵ��ֻ�м�ֵû��ʵֵ����
	set ����������Ԫ������ͬ�ļ�ֵ��(�ڲ�ʹ��ƽ�����������)
	multiset ���Լ��÷��� set ��ȫ��ͬ��Ψһ�����������������ֵ�ظ���
*/
#include <iostream>
#include <set>

using namespace std;

// ���� set ����
template <typename T>
void printSetInt(const T &s)
{
	// set �����ĵ�������ֻ������������ֹ�û����� set �������ݣ��ƻ������Ĳ��֡�
	typename T::const_iterator it = s.begin();
	for (; it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// �º��������غ������������()����
class MyGreater
{
public:

	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};


// set ����API
void test01()
{
	set<int> s1;
	s1.insert(30);
	s1.insert(20);
	s1.insert(10);
	s1.insert(30);	// �ظ��ˣ��޷����뵽 s1 ��
	s1.insert(40);
	printSetInt(s1);	// 10 20 30 40	Ĭ�ϴ�С����

	// set<int���������> s1;		
	// <>�е�������������Ǻ���Ҳ�����ͣ�
	// �����������Ϊ ���º�����
	set<int, MyGreater> s2;
	s2.insert(30);
	s2.insert(20);
	s2.insert(10);
	s2.insert(50);
	s2.insert(40);
	printSetInt(s2);	// 50 40 30 20 10	�����������Ϊ�Ӵ�С
}

// set ����Զ������ݱ����޸��������
class MyGreaterPerson;	// ��ǰ����
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