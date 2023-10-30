/*
	对组（pair）将一对值组合成一个值，这一对值可以具有不同的数据类型，
	两个值可以分别用 pair 的两个公有属性 first 和 second 去访问。
*/
#include <iostream>

using namespace std;

// pair （对组）的API
void test()
{
	// 定义方式一
	pair<int, string> p1(10086, "移动");
	pair<int, string> p2(10010, "联通");
	pair<int, string> p3(10000, "电信");
	// 定义方式二（推荐）
	pair<int, string> p4 = make_pair(9527, "星爷");
	cout << p4.first << " " << p4.second << endl;
}

int main()
{
	test();
	return 0;
}