/*
	���飨pair����һ��ֵ��ϳ�һ��ֵ����һ��ֵ���Ծ��в�ͬ���������ͣ�
	����ֵ���Էֱ��� pair �������������� first �� second ȥ���ʡ�
*/
#include <iostream>

using namespace std;

// pair �����飩��API
void test()
{
	// ���巽ʽһ
	pair<int, string> p1(10086, "�ƶ�");
	pair<int, string> p2(10010, "��ͨ");
	pair<int, string> p3(10000, "����");
	// ���巽ʽ�����Ƽ���
	pair<int, string> p4 = make_pair(9527, "��ү");
	cout << p4.first << " " << p4.second << endl;
}

int main()
{
	test();
	return 0;
}