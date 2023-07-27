#include <iostream>
using namespace std;

// ü�̴� �� : �����¼��..

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

	explicit Player(int m_id)		// ��ȯ �������ε� explicit�� �پ� ��������� ���̵� �־ ���ž�
		: m_id(m_id)
	{
		//cout << "int ���ڰ� �ϳ� �� ������" << endl;
		cout << "������" << m_id << endl;
		cout << this << endl;
	}

	~Player() {
		cout << "�Ҹ���" << endl;
	}

	Player(const int& _id, const int& _str, const int& _dex)
		: m_id(_id)
		, m_str(_str)
		, m_dex(_dex)
	{

	}

	// 1. �Լ� �ڿ� ���� const : �Լ����� �ɹ������� �������� ���ϰ� ���´�.
	// 2. �Լ� �տ� ���� const : ���ϰ��� ����Ǹ� �ȵ� �� (�̰� �� �𸣰ڴ�.)
	// 3. �Լ� �Ű������� const : �Ű����� ���� ���ٲٰ� ���´�.
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


	// �����ε�(over loading) ���� : �Ű�����, const
	//const int& GetId() { return m_id; }
	const int& GetId() const { cout << "const" << endl; return m_id; }		// �Լ� �ڿ� const �� ���̸� �����Ϸ��� ������.
	// �Լ� �̸� �ڿ� const : �ɹ����� �ȹٲ۴�.
	const int& GetId() { cout << "not const" << endl; return m_id; }

	void print() {
		//(*this).m_id;		//  �Ʒ��� ����
		//this->m_id;		// Ŭ���� ������ ���Ǵ� �ڱ��� ������ �̷��� ������ �ʴ� this �� ����
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
	//p1.StrUp(20).DexUp(20).print();		// �ڱ⸦ ������ ü�̴� �� ��. �Ʒ��� ����
	//p1.DexUp(20);
	//p1.print();

	//const int i = 0;
	//i = 1;		// const�� ���� ���ȭ �Ǽ���
	const Player p1(1, 1, 0);
	//p1.SetStat(10, 10, 10);		// ���� �տ� const �� ���̸� ���� �ٲٴ� ���� �Ұ�����.
	p1.GetId();		// ����Ʈ�� �տ� ���̸� ������

	Player p(10, 10, 0);
	p.GetId();

}