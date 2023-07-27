#include <iostream>
using namespace std;

class Player;
class Pet {
private:
	int m_id = 2;
public:
	void GetSome(Player& _player);
};

class Player
{
private:
	int m_id = 1;
	int m_str;
	int m_dex;
	//friend class Pet;
	friend void Pet::GetSome(Player& _player);		// �Լ����� ������
public:
	Player() {
		cout << "������" << endl;
	}
	~Player() {
		cout << "�Ҹ���" << endl;
	}
	void test() {
		cout << "�׽�Ʈ" << endl;
	}
};

void Pet::GetSome(Player& _player) {
	cout << _player.m_id << endl;
}

int main()
{
	//Player player;
	//Pet pet;
	//pet.GetSome(player);
	// r-value - �ӽð�ü(�͸� ��ü)
	Player player;
	player.test();
	Player().test();
	Player().test();		// �����ϰ� �׽�Ʈ�ϰ� �Ҹ��ϰ�
}