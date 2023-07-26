#include <iostream>
using namespace std;

// 생성자

class Player
{
private:
	int m_id;
	int m_str;
	int m_dex;
public:
	/*Player() : m_id(3)
	{
		m_id = 2;
	}*/
	//void SetStat(const int& _id, const int& _str, const int& _dex) {
	//	//void SetStat() {
	//	m_id = _id;
	//	m_str = _str;
	//	m_dex = _dex;
	//}
	 Player (const int& _id, const int& _str, const int& _dex)
		: m_id(_id)
		, m_str(_str)
		, m_dex(_dex)
		{

		}
	//const int& GetId() { return m_id; }
	void print() {
		cout << "id : " << m_id << endl;
	}
	//Player(const int& _id, const int& _str = 20)
	//{
	//	m_id = _id;
	//	m_str = _str;
	//}
	
	// 위임 생성자
	Player(const int& _str, const int& _dex)
		: Player(0, _str, _dex)
	{

	}

	// 복사 생성자
	Player(const Player& _player)
		: m_str(_player.m_str)
		, m_dex(_player.m_dex)
		, m_id(_player.m_id)
	{
		cout << "복사 생성자" << endl;
	}
};

//void Test(Player _player) {
void Test(const Player& _player) {			// 참조를 붙이면 주소 위치가 같아짐, 또 변경을 하지 않으려고!
	cout << &_player << endl;
}

Player CreatePlayer() {
	Player temp(50, 50);
	return temp;
}

int main()
{
	//Player p;		// 생성자가 없어도 클래스 내에 기본적으로 기본 생성자가 포함되어 있음
	//p.print();

	Player p(1, 10, 20);
	Player p2(20, 20);
	Player p3 = p;		// 복사 생성자
	Player(1, 2);		// 일회용. 임시객체
	Player p4(Player(1, 2));		// 임시 객체, 인자로 전달이 됨. 복사 생성자 호출
	//p.print();

	Player player = CreatePlayer();

	cout << &p << endl;
	Test(p);		// 객체를 복사해서 넘기기 때문에 주조 위치가 다름
}