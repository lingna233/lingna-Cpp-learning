/*
	deque 容器是一段一段的定量的连续空间构成。
	一旦有必要在 deque 前端或者尾端增加新空间，便配置一段连续定量的空间，串联在 deque 的头端或者尾端。
	deque 最大的工作就是维护这些分段连续的内存空间的整体性的假象，并提供随机存取的接口，
	这避免了重新配置空间、复制、释放的轮回，代价就是复杂的迭代器架构。
	所以 deque 需要中控器作为主控。
*/
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <numeric>
#include <time.h>

using namespace std;

// 遍历 deque 容器
void printDequeInt(deque<int> &d)
{
	deque<int>::iterator it = d.begin();
	for (; it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// deque 双端插入和删除操作
void InsertDelete()
{
	deque<int> d1;
	d1.push_back(1);
	d1.push_back(2);
	d1.push_back(3);
	d1.push_front(4);
	d1.push_front(5);
	d1.push_front(6);
	printDequeInt(d1);	// 6 5 4 1 2 3
	cout << "大小：" << d1.size() << endl;

	d1.pop_front();
	printDequeInt(d1);	// 5 4 1 2 3
	d1.pop_back();
	printDequeInt(d1);	// 5 4 1 2

	d1.insert(d1.begin() + 1, 3, 100);
	printDequeInt(d1);	// 5 100 100 100 4 1 2
}

// deque 案例
class Player
{
	friend void showPlayer(vector<Player> &v);
	friend void playGame(vector<Player> &v);
public:
	Player()
	{};
	Player(string name, int score)
	{
		this->name = name;
		this->score = score;
	}
	~Player()
	{};
	
private:
	string name;
	int score;
};



void createPlayer(vector<Player> &v)
{
	string tmpName = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += tmpName[i];
		v.push_back(Player(name, 0));
	}
}

void showPlayer(vector<Player> &v)
{
	vector<Player>::iterator it = v.begin();
	for (; it != v.end(); it++)
	{
		// *it = Player
		cout << (*it).name << " " << (*it).score << endl;
	}
}

void playGame(vector<Player> &v)
{
	// 每人逐个比赛
	vector<Player>::iterator it = v.begin();
	for (; it != v.end(); it++)
	{
		// 定义一个deque容器存放10个评委的打分
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			d.push_back(rand() % 41 + 60);
		}
		// 对 deque 排序
		sort(d.begin(), d.end());

		// 去掉最高分和最低分
		d.pop_back();
		d.pop_front();

		// 求平均分
		(*it).score = accumulate(d.begin(), d.end(), 0) / d.size();
	}
}

void Case()
{
	vector<Player> v;

	// srand 设置随机数种子
	srand(time(NULL));

	// 创建五名选手
	createPlayer(v);

	// 比赛
	playGame(v);

	// 显示选手成绩
	showPlayer(v);

}

int main()
{
	// InsertDelete();
	Case();
	return 0;
}

void createPlay(vector<Player> &v)
{}
