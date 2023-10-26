/*
	deque ������һ��һ�εĶ����������ռ乹�ɡ�
	һ���б�Ҫ�� deque ǰ�˻���β�������¿ռ䣬������һ�����������Ŀռ䣬������ deque ��ͷ�˻���β�ˡ�
	deque ���Ĺ�������ά����Щ�ֶ��������ڴ�ռ�������Եļ��󣬲��ṩ�����ȡ�Ľӿڣ�
	��������������ÿռ䡢���ơ��ͷŵ��ֻأ����۾��Ǹ��ӵĵ������ܹ���
	���� deque ��Ҫ�п�����Ϊ���ء�
*/
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <numeric>
#include <time.h>

using namespace std;

// ���� deque ����
void printDequeInt(deque<int> &d)
{
	deque<int>::iterator it = d.begin();
	for (; it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// deque ˫�˲����ɾ������
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
	cout << "��С��" << d1.size() << endl;

	d1.pop_front();
	printDequeInt(d1);	// 5 4 1 2 3
	d1.pop_back();
	printDequeInt(d1);	// 5 4 1 2

	d1.insert(d1.begin() + 1, 3, 100);
	printDequeInt(d1);	// 5 100 100 100 4 1 2
}

// deque ����
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
		string name = "ѡ��";
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
	// ÿ���������
	vector<Player>::iterator it = v.begin();
	for (; it != v.end(); it++)
	{
		// ����һ��deque�������10����ί�Ĵ��
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			d.push_back(rand() % 41 + 60);
		}
		// �� deque ����
		sort(d.begin(), d.end());

		// ȥ����߷ֺ���ͷ�
		d.pop_back();
		d.pop_front();

		// ��ƽ����
		(*it).score = accumulate(d.begin(), d.end(), 0) / d.size();
	}
}

void Case()
{
	vector<Player> v;

	// srand �������������
	srand(time(NULL));

	// ��������ѡ��
	createPlayer(v);

	// ����
	playGame(v);

	// ��ʾѡ�ֳɼ�
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
