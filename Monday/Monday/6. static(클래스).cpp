#include <iostream>
using namespace std;

// static :
// 1. ���������� �޷��ִ�. : �� ����� ���� �������� �� ������ ���⼭�� ��밡���ϴ�. cf) extren
// 2. �Լ� �� ����� ������ static �� �޷��ִ�. : �ѹ��� �ʱ�ȭ�ǰ� ���������� �޸� �Լ��� ���������� �Ҹ����� �ʴ´�.

// 3. Ŭ����?
// static �ɹ� �Լ� :

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
	// �ɹ� ����
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
	//cout << &p2.m_id << endl;		// ���� ���� ����Ŵ
	test();
}