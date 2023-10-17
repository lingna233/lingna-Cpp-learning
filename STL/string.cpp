#include <iostream>
#include <string>

using namespace std;

// string ����͸�ֵ����
void StructureAssignment()
{
	string str1("hello world");
	cout << str1 << endl;
	string str2(5, 'A');
	cout << str2 << endl;

	string str3 = str2;
	cout << str3 << endl;
	string str4 = "hello world";
	cout << str4 << endl;
	str4 = "W";
	cout << str4 << endl;

	str4.assign("hello world", 5);
	cout << str4 << endl;

	string str5 = "hello world";
	str4.assign(str5, 2, 3);
	cout << str4 << endl;
}

// string ��ȡ�ַ�����
void access()
{
	string str1 = "hello world";
	cout << str1[1] << " " << str1.at(1) << endl;
	str1[1] = 'E';
	str1.at(6) = 'H';
	cout << str1 << endl;

	// [] Խ�粻���׳��쳣��at����Խ����׳��쳣
	try
	{
		// str1[100] = 'A';
		str1.at(100) = 'A';
	} catch (const std::exception &e)
	{
		cout << "�����쳣" << e.what() << endl;
	}
}

// string ƴ�Ӳ���
void splicing()
{
	string str1 = "hello";
	str1 += "world";
	cout << str1 << endl;
	string str2 = "I love the world";
	str1 += str2;
	cout << str1 << endl;

	string str3 = "hello";
	string str4 = "world";
	cout << str3 + str4 << endl;

	string str5 = "hello";
	string str6 = "world";
	str5.append(str6, 2, 3);
	cout << str5 << endl;
	string str7 = "hello";
	str7.append("world", 3);
	cout << str7 << endl;
}

// string �����滻����
void FindReplace()
{
	string str1 = "http://www.666.777.666.com";
	cout << str1 << endl;
	while (true)
	{
		int ret = str1.find("666");		// find()�Ǵ�ǰ�����ң�rfind()�ǴӺ���ǰ��
		if (ret == -1)
		{
			break;
		}
		str1.replace(ret, 3, "111");
	}
	cout << str1 << endl;
}

// string �Ƚϲ���
void compare()
{
	// string�е�compare������>ʱ����1��<ʱ����-1��=ʱ����0
	string str1 = "hehe";
	string str2 = "haha";
	if (str1.compare(str2) == 0)
	{
		cout << "���" << endl;
	} else if (str1.compare(str2) > 0)
	{
		cout << "����" << endl;
	} else if (str1.compare(str2) < 0)
	{
		cout << "С��" << endl;
	}
	// ������> < == �ȹ�ϵ�����
	if (str1 == str2)
	{
		cout << "���" << endl;
	} else if (str1 > str2)
	{
		cout << "����" << endl;
	} else if (str1 < str2)
	{
		cout << "С��" << endl;
	}
}

// string ��ȡ�ִ�����
void extract()
{
	string str1 = "hehehe:hahaha:xixixi:lalala";
	int pos = 0;	// ������ʼλ��Ϊ0
	while (true)
	{
		int ret = str1.find(":", pos);
		if (ret < 0)
		{
			string tmp = str1.substr(pos, str1.size() - pos);
			cout << tmp << endl;
			break;
		}
		string tmp = str1.substr(pos, ret - pos);
		cout << tmp << endl;
		pos = ret + 1;
	}
}

// string �����ɾ������
void InsertsDeletions()
{
	string str1 = "hello";
	str1.insert(2, "***");
	cout << str1 << endl;
	str1.erase(2, 3);
	cout << str1 << endl;
	str1.erase(0, str1.size());
	cout << str1 << endl;
	cout << str1.size() << " " << str1.capacity() << endl;
}

// string �� c-style �ַ���ת��
void conversion()
{
	// char * ת�� string��Ĭ��֧�֣�
	string str1;
	str1 = (string)"hello";
	cout << str1 << endl;

	// string ����ֱ��ת���� char *����Ҫ��Ա����c_str
	string str2 = "hello";
	char *p = (char *)str2.c_str();
	cout << p << endl;
}

int main()
{
	// StructureAssignment();
	// access();
	// splicing();
	// FindReplace();
	// compare();
	// extract();
	// InsertsDeletions();
	conversion();
	return 0;
}