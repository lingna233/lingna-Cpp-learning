#include <iostream>
#include <string>

using namespace std;

// string 构造和赋值操作
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

// string 存取字符操作
void access()
{
	string str1 = "hello world";
	cout << str1[1] << " " << str1.at(1) << endl;
	str1[1] = 'E';
	str1.at(6) = 'H';
	cout << str1 << endl;

	// [] 越界不会抛出异常，at方法越界会抛出异常
	try
	{
		// str1[100] = 'A';
		str1.at(100) = 'A';
	} catch (const std::exception &e)
	{
		cout << "捕获到异常" << e.what() << endl;
	}
}

// string 拼接操作
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

// string 查找替换操作
void FindReplace()
{
	string str1 = "http://www.666.777.666.com";
	cout << str1 << endl;
	while (true)
	{
		int ret = str1.find("666");		// find()是从前往后找，rfind()是从后往前找
		if (ret == -1)
		{
			break;
		}
		str1.replace(ret, 3, "111");
	}
	cout << str1 << endl;
}

// string 比较操作
void compare()
{
	// string中的compare函数在>时返回1，<时返回-1，=时返回0
	string str1 = "hehe";
	string str2 = "haha";
	if (str1.compare(str2) == 0)
	{
		cout << "相等" << endl;
	} else if (str1.compare(str2) > 0)
	{
		cout << "大于" << endl;
	} else if (str1.compare(str2) < 0)
	{
		cout << "小于" << endl;
	}
	// 重载了> < == 等关系运算符
	if (str1 == str2)
	{
		cout << "相等" << endl;
	} else if (str1 > str2)
	{
		cout << "大于" << endl;
	} else if (str1 < str2)
	{
		cout << "小于" << endl;
	}
}

// string 提取字串操作
void extract()
{
	string str1 = "hehehe:hahaha:xixixi:lalala";
	int pos = 0;	// 定义起始位置为0
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

// string 插入和删除操作
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

// string 和 c-style 字符串转换
void conversion()
{
	// char * 转成 string（默认支持）
	string str1;
	str1 = (string)"hello";
	cout << str1 << endl;

	// string 不能直接转换成 char *，需要成员函数c_str
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