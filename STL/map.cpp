/*
	map 的所有元素都会根据元素的键值自动排序。
	map 所有元素都是 pair，同时拥有实值和键值，
	pair 的第一元素被视为键值，第二元素被视为实值，map 不允许两个元素拥有相同的键值。
	multimap 和 map 的唯一区别是 multimap 的键值可重复。
	map 和 multimap 都是以红黑树为底层实现机制。
*/
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

// map 容器：每个元素都是 键值-实值 成对存储，自动根据键值排序，键值不能重复，不能修改。
// map 插入操作
class Student
{
	friend void Insert();
	friend void printMapAll(map<int, Student> &m);
public:
	Student();
	Student(int num, string name, int score);
	~Student();

private:
	int num;
	string name;
	int score;
};

Student::Student()
{}

Student::Student(int num, string name, int score)
{
	this->num = num;
	this->name = name;
	this->score = score;
}

Student::~Student()
{}

// 遍历 map 容器
void printMapAll(map<int, Student> &m)
{
	map<int, Student>::const_iterator it = m.begin();
	for (; it != m.end(); it++)
	{
		// *it = pair<int, Student>
		cout << (*it).first << " " << (*it).second.name << " " << (*it).second.score << endl;
	}
}

void Insert()
{
	map<int, Student> m;
	// map 赋值方式一
	m.insert(pair<int, Student>(103, Student(103, "lucy", 88)));
	// map 赋值方式二（推荐）
	m.insert(make_pair(101, Student(101, "bob", 86)));
	// map 赋值方式三
	m.insert(map<int, Student>::value_type(102, Student(102, "tom", 90)));
	// map 赋值方式四
	m[104] = Student(104, "dema", 99);

	// 遍历 m
	printMapAll(m);

	cout << m[101].num << " " << m[101].name << m[101].score << endl;
	// 必须确保 [] 中的键值存在，不然会自动加入该键值，但实值是不确定的。
	// cout << m[107].num << " " << m[107].name << m[107].score << endl;
	cout << "----------------" << endl;
	printMapAll(m);
}


#define SALE_DEPATMENT 1;	// 销售部门
#define DEVELOP_DEPATMENT 2;	// 研发部门
#define FINACIAL_DEPATMENT 3;	// 财务部门

class Employee
{
	friend void employeeJionDepartment(vector<Employee> &v, multimap<int, Employee> &m);
	friend void showDepartmentEmployee(multimap<int, Employee> &m);
public:
	Employee();
	Employee(string name, int age, int money, string tel);
	~Employee();

private:
	string name;
	int age;
	int money;
	string tel;
};

Employee::Employee()
{}

Employee::Employee(string name, int age, int money, string tel)
{
	this->name = name;
	this->age = age;
	this->money = money;
	this->tel = tel;
}

Employee::~Employee()
{}

// 创建员工
void createVectorEmployee(vector<Employee> &v)
{
	// 设置随机数种子
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; i++)
	{
		string seedName = "ABCDE";
		string tmpName = "员工";
		tmpName += seedName[i];
		int age = 20 + i;
		int money = 15000 + rand() % 10 * 1000;
		string tel = to_string(rand());

		v.push_back(Employee(tmpName, age, money, tel));
	}
}

// 加入部门
void employeeJionDepartment(vector<Employee> &v, multimap<int, Employee> &m)
{
	vector<Employee>::iterator it = v.begin();
	for (; it != v.end(); it++)
	{
		// *it = Employee
		cout << "请输入[" << (*it).name << "]加入的部门 1（销售）、2（研发）、3（财务）：";
		int op = 1;
		cin >> op;
		m.insert(make_pair(op, *it));
	}
}

// 显示部门员工
void showDepartmentEmployee(multimap<int, Employee> &m)
{
	cout << "请输入你要显示的部门 1（销售）、2（研发）、3（财务）：";
	int op = 1;
	cin >> op;
	switch (op)
	{
		case 1:
			cout << "-----------销售部门员工如下-------------" << endl;
			break;
		case 2:
			cout << "-----------研发部门员工如下-------------" << endl;
			break;
		case 3:
			cout << "-----------财务部门员工如下-------------" << endl;
			break;
		default:
			break;
	}

	// 寻找 op 的位置
	multimap<int, Employee>::const_iterator ret = m.begin();
	ret = m.find(op);
	if (ret == m.end())
	{
		return;
	}
	// 统计 op 的个数
	int count = m.count(op);
	
	// 从 op 的位置，按照个数逐个遍历
	for (int i = 0; i < count; i++)
	{
		// *ret = pair<int, Employee>
		cout << "\t" << (*ret).second.name << "\t" << (*ret).second.age << "\t" << (*ret).second.money << "\t" << (*ret).second.tel << endl;
	}
}

// multimap 案例
void multimapTest()
{
	// 创建5名员工，存放在 vector 容器中
	vector<Employee> v;
	createVectorEmployee(v);

	// 5名员工加入部门
	multimap<int, Employee> m;
	employeeJionDepartment(v, m);

	// 显示部门员工
	showDepartmentEmployee(m);
}

int main()
{
	// Insert();
	multimapTest();
	return 0;
}