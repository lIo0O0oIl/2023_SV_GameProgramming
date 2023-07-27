#include <iostream>
using namespace std;

// ����� ������

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
	// ������ cout �� �̷��� ����(���), friend �� stream �� ��Ʈ�����̶� ģ������������
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
	// �� ������ �����ε�
	bool operator == (const Player& _other) {
		return (m_posx == _other.m_posx) && (m_posy == _other.m_posy);
	}
	// ����������
	Player& operator ++() {		// �������� �����ε�
		++m_posx;
		++m_posy;
		return *this;		// this = �ּ�, *this = ��
	}
	Player operator ++ (int) {		// ������, ������ ���ؼ� int�� ����
		Player temp(m_posx, m_posy);
		++m_posx;
		++m_posy;
		return temp;		// �׸��� ������ �̷��� �ϱ⋚���� ������ ������.
	}
};

int main() {
	// ����������.
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
		cout << "����";
	}
}