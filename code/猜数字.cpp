#include <iostream>
using namespace std;
int main(void) {
	int target = 456;
	int guess;
	int a = 1, b = 1000;
	cout << "本游戏范围为1到1000，游戏现在开始！" << endl << "请输入数字" << endl;
	for (int i = 0; i < 10; i++) {
		cin >> guess;
		if (guess == a || guess == b) {
			cout << "不能输入边界数字" << endl;
			break;
		}
		if (guess < target) {
			a = guess;
			cout << "猜测错误，现在范围为" << a << "到" << b << endl;
			cout << "请重新输入数字" << endl;
		}
		if (guess > target) {
			b = guess;
			cout << "猜测错误，现在范围为" << a << "到" << b << endl;
			cout << "请重新输入数字" << endl;
		}
		if (guess == target) {
			cout << "猜测正确！" << endl;
			break;
		}
	} 
	return 0;
}