#include <iostream>
using namespace std;

// 체이닝 콜 : 연쇄어쩌고..

class Player
{
private:
	int m_id;
	int m_str;
	int m_dex;
public:

	void SetStat(const int& _id, const int& _str, const int& _dex) {
		//void SetStat() {
		m_id = _id;
		m_str = _str;
		m_dex = _dex;
	}

	explicit Player(int m_id)		// 변환 생성자인데 explicit가 붙어 명시적으로 아이디만 넣어서 쓸거양
		: m_id(m_id)
	{
		//cout << "int 인자가 하나 들어간 생성자" << endl;
		cout << "생성자" << m_id << endl;
		cout << this << endl;
	}

	~Player() {
		cout << "소멸자" << endl;
	}

	Player(const int& _id, const int& _str, const int& _dex)
		: m_id(_id)
		, m_str(_str)
		, m_dex(_dex)
	{

	}

	// 1. 함수 뒤에 붙은 const : 함수에서 맴버변수를 변경하지 못하게 막는다.
	// 2. 함수 앞에 붙은 const : 리턴값이 변경되면 안될 때 (이거 잘 모르겠다.)
	// 3. 함수 매개변수에 const : 매개변수 값을 못바꾸게 막는다.
	void consttest() const
	{
		m_id = 3;
	}
	const int consttest2() {
		int temp;
		return temp;
	}
	void SetStat(const int& _id, const int& _str, const int& _dex) {
		//void SetStat() {
		m_id = _id;
		m_str = _str;
		m_dex = _dex;
	}


	// 오버로딩(over loading) 조건 : 매개변수, const
	//const int& GetId() { return m_id; }
	const int& GetId() const { cout << "const" << endl; return m_id; }		// 함수 뒤에 const 를 붙이면 컴파일러가 아하함.
	// 함수 이름 뒤에 const : 맴버변수 안바꾼다.
	const int& GetId() { cout << "not const" << endl; return m_id; }

	void print() {
		//(*this).m_id;		//  아래랑 같지
		//this->m_id;		// 클래스 내에서 사용되는 자기의 변수는 이렇게 보이지 않는 this 가 있음
		cout << "str : " << m_str << " " << "dex : " << m_dex << endl;
	}

	Player& StrUp(int _str) { m_str += _str; return *this; }
	Player& DexUp(int _dex) { m_dex += _dex; return *this; }
};

void test(const Player& player) {

}

int main() {
	//Player p1(1);
	//Player p2(2);
	//cout << &p1 << " " << &p2 << endl;

	//Player p1(1, 1, 0);
	//p1.StrUp(20).DexUp(20).print();		// 자기를 돌려서 체이닝 콜 함. 아래와 같음
	//p1.DexUp(20);
	//p1.print();

	//const int i = 0;
	//i = 1;		// const로 인해 상수화 되서임
	const Player p1(1, 1, 0);
	//p1.SetStat(10, 10, 10);		// 만약 앞에 const 를 붙이면 값을 바꾸는 것이 불가능함.
	p1.GetId();		// 컨스트를 앞에 붙이면 가능함

	Player p(10, 10, 0);
	p.GetId();

}