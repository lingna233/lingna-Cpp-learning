#include <iostream>
using namespace std;
int main(void) {
	int target = 456;
	int guess;
	int a = 1, b = 1000;
	cout << "����Ϸ��ΧΪ1��1000����Ϸ���ڿ�ʼ��" << endl << "����������" << endl;
	for (int i = 0; i < 10; i++) {
		cin >> guess;
		if (guess == a || guess == b) {
			cout << "��������߽�����" << endl;
			break;
		}
		if (guess < target) {
			a = guess;
			cout << "�²�������ڷ�ΧΪ" << a << "��" << b << endl;
			cout << "��������������" << endl;
		}
		if (guess > target) {
			b = guess;
			cout << "�²�������ڷ�ΧΪ" << a << "��" << b << endl;
			cout << "��������������" << endl;
		}
		if (guess == target) {
			cout << "�²���ȷ��" << endl;
			break;
		}
	} 
	return 0;
}