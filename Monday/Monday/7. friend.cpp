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
	friend void Pet::GetSome(Player& _player);		// 함수만도 가능함
public:
	Player() {
		cout << "생성자" << endl;
	}
	~Player() {
		cout << "소멸자" << endl;
	}
	void test() {
		cout << "테스트" << endl;
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
	// r-value - 임시객체(익명 개체)
	Player player;
	player.test();
	Player().test();
	Player().test();		// 생성하고 테스트하고 소멸하고
}