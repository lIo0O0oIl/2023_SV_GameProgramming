#include <iostream>
using namespace std;

// 입출력 연산자

class Player {
private:
	int m_posx;
	int m_posy;
public:
	Player(int _x, int _y) : m_posx(_x), m_posy(_y) {}
	void PlayerPrint()
	{
		cout << "X : " << m_posx << " Y : " << m_posy;
	}
	// 실제로 cout 이 이렇게 생김(비슷), friend 는 stream 이 스트림들이랑 친구먹을려고임
	friend ostream& operator << (ostream& _out, const Player& _other) 
	{
		_out << "X: " <<_other.m_posx <<" Y: " << _other.m_posy << endl;
		return _out;
	}
	friend istream& operator >> (istream& _in, Player& _other)
	{
		_in >> _other.m_posx >> _other.m_posy;
		return _in;
	}
	// 비교 연산자 오버로딩
	bool operator == (const Player& _other) {
		return (m_posx == _other.m_posx) && (m_posy == _other.m_posy);
	}
	// 증감연산자
	Player& operator ++() {		// 전위형의 오버로딩
		++m_posx;
		++m_posy;
		return *this;		// this = 주소, *this = 값
	}
	Player operator ++ (int) {		// 후위형, 구분을 위해서 int를 넣음
		Player temp(m_posx, m_posy);
		++m_posx;
		++m_posy;
		return temp;		// 그리고 동작을 이렇게 하기떄문에 후위가 안좋다.
	}
};

int main() {
	// 증감연산자.
	int a = 0;
	cout << ++a << endl;		// 1
	cout << a << endl;		// 1
	cout << a++ << endl;		// 1
	cout << a << endl;		// 2

	Player p1(1, 1);
	cout << ++p1 << endl;
	cout << p1++ << endl;

	Player p2(10, 10);
	p1.PlayerPrint();
	p2.PlayerPrint();

	int a;
	cin >> a;		// cin
	cout << p1 << p2 << endl;		// cout
	if (p1 == p2) {
		cout << "같음";
	}
}