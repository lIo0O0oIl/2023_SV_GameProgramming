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
	Player(char _val) = delete;		// 이런 생성자는 아예 안쓸거야

	explicit Player(int m_id)		// 변환 생성자인데 explicit가 붙어 명시적으로 아이디만 넣어서 쓸거양
		: m_id (m_id)
	{
		cout << "int 인자가 하나 들어간 생성자" << endl;
	}

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

class Test2 
{
	Test2() = default;		// 기본생성자가 없을 때 널 쓸거야
	Test2() 
	{
	}
}

//void Test(Player _player) {
void Test(Player _player) {			// 참조를 붙이면 주소 위치가 같아짐, 또 변경을 하지 않으려고!
	cout << "TEST 함수" << _player.GetId() << endl;
	//cout << &_player << endl;
}

Player CreatePlayer() {
	Player temp(50, 50);
	return temp;
}

// 변환 생성자 : 매개변수가 하나인 생성자. Test 함수에 int 함수 하나를 두는 것으로 사용가능

int main()
{
	//Player p;		// 생성자가 없어도 클래스 내에 기본적으로 기본 생성자가 포함되어 있음
	//p.print();

	//Player p(1, 10, 20);
	//Player p2(20, 20);
	//Player p3 = p;		// 복사 생성자
	//Player(1, 2);		// 일회용. 임시객체
	//Player p4(Player(1, 2));		// 임시 객체, 인자로 전달이 됨. 복사 생성자 호출
	//p.print();

	//Player player = CreatePlayer();		// 복사생성자를 거침. RVO(return value Optimization) : 변환값 최적화를 함. 이 함수같은 경우에서.(안에서 새로 만들고 리턴)
														// 컴파일러가 불필요한 복사를 최소화 하는 것임 (C++ 11부터)

	//cout << &p << endl;
	//Test(p);		// 객체를 복사해서 넘기기 때문에 주조 위치가 다름
	//Test(5);		// explicit 가 붙어서 이제 사용이 안됨
	//Player p2(3);

	// delete :  내가 사용하지 않은 것들은 모두 delete 로 삭제를 시켜준다. (실수 ㄴㄴ)
	Player p3('a');		// 응 못써~
	//default : 생성자를 만들어두지 않았으면 기본 생성자를 쓸거야?....?