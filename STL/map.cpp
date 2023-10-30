/*
	map ������Ԫ�ض������Ԫ�صļ�ֵ�Զ�����
	map ����Ԫ�ض��� pair��ͬʱӵ��ʵֵ�ͼ�ֵ��
	pair �ĵ�һԪ�ر���Ϊ��ֵ���ڶ�Ԫ�ر���Ϊʵֵ��map ����������Ԫ��ӵ����ͬ�ļ�ֵ��
	multimap �� map ��Ψһ������ multimap �ļ�ֵ���ظ���
	map �� multimap �����Ժ����Ϊ�ײ�ʵ�ֻ��ơ�
*/
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

// map ������ÿ��Ԫ�ض��� ��ֵ-ʵֵ �ɶԴ洢���Զ����ݼ�ֵ���򣬼�ֵ�����ظ��������޸ġ�
// map �������
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

// ���� map ����
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
	// map ��ֵ��ʽһ
	m.insert(pair<int, Student>(103, Student(103, "lucy", 88)));
	// map ��ֵ��ʽ�����Ƽ���
	m.insert(make_pair(101, Student(101, "bob", 86)));
	// map ��ֵ��ʽ��
	m.insert(map<int, Student>::value_type(102, Student(102, "tom", 90)));
	// map ��ֵ��ʽ��
	m[104] = Student(104, "dema", 99);

	// ���� m
	printMapAll(m);

	cout << m[101].num << " " << m[101].name << m[101].score << endl;
	// ����ȷ�� [] �еļ�ֵ���ڣ���Ȼ���Զ�����ü�ֵ����ʵֵ�ǲ�ȷ���ġ�
	// cout << m[107].num << " " << m[107].name << m[107].score << endl;
	cout << "----------------" << endl;
	printMapAll(m);
}


#define SALE_DEPATMENT 1;	// ���۲���
#define DEVELOP_DEPATMENT 2;	// �з�����
#define FINACIAL_DEPATMENT 3;	// ������

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

// ����Ա��
void createVectorEmployee(vector<Employee> &v)
{
	// �������������
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; i++)
	{
		string seedName = "ABCDE";
		string tmpName = "Ա��";
		tmpName += seedName[i];
		int age = 20 + i;
		int money = 15000 + rand() % 10 * 1000;
		string tel = to_string(rand());

		v.push_back(Employee(tmpName, age, money, tel));
	}
}

// ���벿��
void employeeJionDepartment(vector<Employee> &v, multimap<int, Employee> &m)
{
	vector<Employee>::iterator it = v.begin();
	for (; it != v.end(); it++)
	{
		// *it = Employee
		cout << "������[" << (*it).name << "]����Ĳ��� 1�����ۣ���2���з�����3�����񣩣�";
		int op = 1;
		cin >> op;
		m.insert(make_pair(op, *it));
	}
}

// ��ʾ����Ա��
void showDepartmentEmployee(multimap<int, Employee> &m)
{
	cout << "��������Ҫ��ʾ�Ĳ��� 1�����ۣ���2���з�����3�����񣩣�";
	int op = 1;
	cin >> op;
	switch (op)
	{
		case 1:
			cout << "-----------���۲���Ա������-------------" << endl;
			break;
		case 2:
			cout << "-----------�з�����Ա������-------------" << endl;
			break;
		case 3:
			cout << "-----------������Ա������-------------" << endl;
			break;
		default:
			break;
	}

	// Ѱ�� op ��λ��
	multimap<int, Employee>::const_iterator ret = m.begin();
	ret = m.find(op);
	if (ret == m.end())
	{
		return;
	}
	// ͳ�� op �ĸ���
	int count = m.count(op);
	
	// �� op ��λ�ã����ո����������
	for (int i = 0; i < count; i++)
	{
		// *ret = pair<int, Employee>
		cout << "\t" << (*ret).second.name << "\t" << (*ret).second.age << "\t" << (*ret).second.money << "\t" << (*ret).second.tel << endl;
	}
}

// multimap ����
void multimapTest()
{
	// ����5��Ա��������� vector ������
	vector<Employee> v;
	createVectorEmployee(v);

	// 5��Ա�����벿��
	multimap<int, Employee> m;
	employeeJionDepartment(v, m);

	// ��ʾ����Ա��
	showDepartmentEmployee(m);
}

int main()
{
	// Insert();
	multimapTest();
	return 0;
}