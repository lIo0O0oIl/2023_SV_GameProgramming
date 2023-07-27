#include <iostream>
using namespace std;

// �Ҹ��� : ��ü�� ������ ����� ��ü�� �� �ڵ����� ȣ��Ǵ� �Լ�

class Player
{
private:
	int m_id;
	int m_str;
	int m_dex;
public:
	Player(char _val) = delete;		// �̷� �����ڴ� �ƿ� �Ⱦ��ž�

	explicit Player(int m_id)		// ��ȯ �������ε� explicit�� �پ� ��������� ���̵� �־ ���ž�
		: m_id(m_id)
	{
		//cout << "int ���ڰ� �ϳ� �� ������" << endl;
		cout << "������" << m_id << endl;
	}

	~Player() {
		cout << "�Ҹ���" << endl;
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

	// ���� ������
	Player(const int& _str, const int& _dex)
		: Player(0, _str, _dex)
	{

	}

	// ���� ������
	Player(const Player& _player)
		: m_str(_player.m_str)
		, m_dex(_player.m_dex)
		, m_id(_player.m_id)
	{
		cout << "���� ������" << endl;
	}
};

//Player p3(3);
int main() {
	// ������ : 3 1 2
	// �Ҹ��� : 2 1 3 (���� ������ �ƴϰ� 3��°�� ���� ��)
	//Player p1(1);
	Player* p1 = new Player(1);		// ���� ����
	Player p2(2);
	// ������ : 1 2
	// �Ҹ��� : p1�� delete �ϴ� ������ ����...
}