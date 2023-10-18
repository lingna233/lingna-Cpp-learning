/*
	v.rend() ָ��vector������0��Ԫ�ص�ǰһ��λ��
	v.begin() ��ȡvector��������ʼ��������������������һһ��Ӧ��
	v.end() ��ȡvector�����Ľ�����������ָ��vector�������һ��Ԫ�ص���һ��λ�ã�

	δ����ѻ��ƣ���vector��������ʱ������չԭ�������Ŀռ䣻
				����������ԭ�ռ�֮�������¿ռ䣬��������һ�������ڴ�ռ䣬��ԭ���ݿ������¿ռ䣬����ԭ�ռ��ͷš�
*/
#include <iostream>
#include <vector>

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
void expansion()
{
	vector<int> v1;
	cout << "������" << v1.capacity() << " ��С��" << v1.size() << endl;

	vector<int>::iterator it;

	int count = 0;

	for (int i = 0; i < 1000; i++)
	{
		v1.push_back(i);

		// �д��󣬳�������
		if (it != v1.begin())
		{
			count++;
			cout << "��" << count << "�ο��ٿռ䣬������" << v1.capacity() << endl;
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