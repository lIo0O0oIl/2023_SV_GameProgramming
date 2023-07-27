#include <iostream>
using namespace std;

// 파일 받아서 작성하기!![

class Player {
private:
	int m_posx;
	int m_posy;
public:
	Player() = default;
	Player(int _x, int _y) : m_posx(_x), m_posy(_y) {}
	int GetPosX() { return m_posx; }
};

void AddPosX(const Player& _p1, const Player& _p2, Player& _out) {
	_out.GetPosX() = _p1.GetPosX() + _p2.GetPosX();
}

Player operator +(const Player& _p1, const Player& _p2) {
	return = _p1.GetPosX() + _p2.GetPosX();
}

int main() {
	Player p1(1, 1);
	Player p2(2, 2);
	Player result;
	AddPosX(p1, p2, result);
}