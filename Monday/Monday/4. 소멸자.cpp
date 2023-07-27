#include <iostream>
using namespace std;

// 소멸자 : 객체가 영역을 벗어나서 해체될 때 자동으로 호출되는 함수

class Player
{
private:
	int m_id;
	int m_str;
	int m_dex;
public:
	Player(char _val) = delete;		// 이런 생성자는 아예 안쓸거야

	explicit Player(int m_id)		// 변환 생성자인데 explicit가 붙어 명시적으로 아이디만 넣어서 쓸거양
		: m_id(m_id)
	{
		//cout << "int 인자가 하나 들어간 생성자" << endl;
		cout << "생성자" << m_id << endl;
	}

	~Player() {
		cout << "소멸자" << endl;
	}

	//void SetStat(const int& _id, const int& _str, const int& _dex) {
	//	//void SetStat() {
	//	m_id = _id;
	//	m_str = _str;
	//	m_dex = _dex;
	//}

	Player(const int& _id, const int& _str, const int& _dex)
		: m_id(_id)
		, m_str(_str)
		, m_dex(_dex)
	{

	}

	const int& GetId() { return m_id; }

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

//Player p3(3);
int main() {
	// 생성자 : 3 1 2
	// 소멸자 : 2 1 3 (힙에 쌓은게 아니고 3번째꺼 있을 때)
	//Player p1(1);
	Player* p1 = new Player(1);		// 힙에 쌓임
	Player p2(2);
	// 생성자 : 1 2
	// 소멸자 : p1을 delete 하는 순서에 따라서...
}