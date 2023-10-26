/*
	v.rend() ָ��vector������0��Ԫ�ص�ǰһ��λ��
	v.begin() ��ȡvector��������ʼ��������������������һһ��Ӧ��
	v.end() ��ȡvector�����Ľ�����������ָ��vector�������һ��Ԫ�ص���һ��λ�ã�

	δ����ѻ��ƣ���vector��������ʱ������չԭ�������Ŀռ䣻
				����������ԭ�ռ�֮�������¿ռ䣬��������һ�������ڴ�ռ䣬��ԭ���ݿ������¿ռ䣬����ԭ�ռ��ͷš�
*/
#include <iostream>
#include <vector>
#include <algorithm>	// STL �㷨
#include <string>

using namespace std;

// ��ӡvector
void printVectorInt(vector<int> &v)
{
	vector<int>::iterator it = v.begin();
	for (; it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

// vector ����͸�ֵ����
void StructureAssignment()
{
	// ����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
	vector<int>	v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	// ����������
	// ����һ�������� iterator ������ʼ������
	vector<int>::iterator it = v1.begin();
	for (; it != v1.end(); it++)
	{
		// *it == int ������ָ��
		cout << *it << "  ";
	}
	cout << endl;
	// 5��100
	vector<int> v2(5, 100);
	printVectorInt(v2);
	// ���乹��
	vector<int> v3(v2.begin(), v2.end());
	printVectorInt(v3);

	// ��ֵ
	vector<int> v4;
	// v4 = v1;

	// ���丳ֵ
	// v4.assign(v1.begin(), v1.end());

	// ��ֵn��Ԫ�أ�10��10��
	v4.assign(10, 10);
	printVectorInt(v4);

	// ����
	v4.swap(v2);
	printVectorInt(v4);
	printVectorInt(v2);
}

// veactor ��������ʱ��δ����ѻ���
void Expansion()
{
	vector<int> v1;
	cout << "������" << v1.capacity() << " ��С��" << v1.size() << endl;
	/*v1.push_back(1);*/

	vector<int>::iterator it = v1.begin();

	int count = 0;

	for (int i = 0; i < 1000; i++)
	{
		v1.push_back(i);

		// �д��󣬳���������������������
		if (it != v1.begin())
		{
			count++;
			cout << "��" << count << "�ο��ٿռ䣬������" << v1.capacity() << endl;
			it = v1.begin();
		}
	}
}

// vector ��С����
void Size()
{
	vector<int> v1;
	if (v1.empty())
	{
		cout << "��" << endl;
	} else
	{
		cout << "�ǿ�" << endl;
	}

	vector<int> v2(10, 30);
	cout << "v2������" << v2.capacity() << "��v2��С��" << v2.size() << endl;
	printVectorInt(v2);
	// ���ô�С
	// v2.resize(15);	// ����Ĭ�ϲ�0
	// v2.resize(15, 2);	// �Զ������ʱ��2
	v2.resize(5);	// ��Сɾ�����ಿ��
	printVectorInt(v2);
}

// vector ���ݴ�ȡ����
void Access()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);	// 10 20 30 40 50

	cout << "ͷԪ�أ�" << v1.front() << "��βԪ�أ�" << v1.back() << endl;
	// atԽ����׳��쳣��[]Խ�粻���׳��쳣
	cout << v1[1] << " " << v1.at(1) << endl;
	v1.at(1) = 200;
	v1[3] = 400;
	printVectorInt(v1);	// 10 200 30 400 50
}

// vector �����ɾ������
void InsertDelete()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	// β��ɾ��
	v1.pop_back();
	printVectorInt(v1);	// 10 20 30 40
	// ����
	v1.insert(v1.begin() + 2, 3, 500);
	printVectorInt(v1);	// 10 20 500 500 500 30 40

	// ����ɾ��
	v1.erase(v1.begin() + 2, v1.begin() + 5);
	printVectorInt(v1);	// 10 20 30 40

	// �������
	v1.clear();
	cout << "v1������" << v1.capacity() << "��v1��С��" << v1.size() << endl;
}

// vector swap�����ռ�
void Swap()
{
	vector<int> v1;
	v1.reserve(1000);
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	cout << "v1������" << v1.capacity() << "��v1��С��" << v1.size() << endl;	// 1000 4
	// resize ֻ���޸Ĵ�С �����޸�����
	// 
	// ����һ���������󣬽�v1���������������ٽ�v1������������н���
	// ��v1������������п���ʱ�����´��v1��������ֻ�´��v1�Ĵ�С
	// ���Խ�v1�뿽������������󽻻���v1�������ͻ�����
	vector<int>(v1).swap(v1);
	cout << "v1������" << v1.capacity() << "��v1��С��" << v1.size() << endl;	// 4 4
}

// vector ����
void Case()
{
	vector<int> v1(5, 10);
	vector<int> v2(5, 100);
	vector<int> v3(5, 1000);

	// ���󣺶���һ�� vector ������� v1,v2,v3
	vector<vector<int>> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	// ����
	vector<vector<int>>::iterator it = v.begin();	// ���������
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

// ʹ�� STL �㷨�� vector ��������
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

	// �����㷨
	sort(v1.begin(), v1.end());
	printVectorInt(v1);
}

// vector ����Զ�������
// �Զ�����
class Person
{
	// �Զ������
	friend void printVectorPerson(vector<Person> &v);
	// �Զ���ȽϹ���
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

// �Զ������
void printVectorPerson(vector<Person> &v)
{
	vector<Person>::iterator it = v.begin();
	for (; it != v.end(); it++)
	{
		// *it == Preson
		cout << (*it).num << "  " << (*it).name << "  " << (*it).score << endl;
	}
}

// �Զ���ȽϹ���
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
	v1.push_back(Person(104, "����", 97.7f));
	v1.push_back(Person(102, "С��", 57.7f));
	printVectorPerson(v1);

	// ���Զ������͵� vector ������Ҫָ���������
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