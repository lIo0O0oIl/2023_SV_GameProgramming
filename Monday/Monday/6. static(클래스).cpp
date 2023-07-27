#include <iostream>
using namespace std;

// static :
// 1. 전역변수에 달려있다. : 그 선언된 파일 내에서만 콕 박혀서 여기서만 사용가능하다. cf) extren
// 2. 함수 내 선언된 변수에 static 이 달려있다. : 한번만 초기화되고 지역변수랑 달리 함수를 빠져나가도 소멸하지 않는다.

// 3. 클래스?
// static 맴버 함수 :

void test() {
	static int a;
}

class Player
{
public:
	static int m_id;
	int m_str;
	int m_dex;
public:
	static int GetId() { return m_id; }
	void test() {
		this->m_str;
	}
};

class Core {
private:
	// 맴버 변수
	static Core* Inst;
public:
	static;
};

int Player::m_id = 1;

int main() 
{
	Player p1;
	Player p2;
	p2.test();
	Player::GetId();
	//cout << &p1.m_id << endl;
	//cout << &p2.m_id << endl;		// 같은 곳을 가르킴
	test();
}