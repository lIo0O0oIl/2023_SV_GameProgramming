#include <iostream>
using namespace std;

// ������

class Player
{
private:
	int m_id;
	int m_str;
	int m_dex;
public:
	/*Player() : m_id(3)
	{
		m_id = 2;
	}*/
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
	//const int& GetId() { return m_id; }
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

//void Test(Player _player) {
void Test(const Player& _player) {			// ������ ���̸� �ּ� ��ġ�� ������, �� ������ ���� ��������!
	cout << &_player << endl;
}

Player CreatePlayer() {
	Player temp(50, 50);
	return temp;
}

int main()
{
	//Player p;		// �����ڰ� ��� Ŭ���� ���� �⺻������ �⺻ �����ڰ� ���ԵǾ� ����
	//p.print();

	Player p(1, 10, 20);
	Player p2(20, 20);
	Player p3 = p;		// ���� ������
	Player(1, 2);		// ��ȸ��. �ӽð�ü
	Player p4(Player(1, 2));		// �ӽ� ��ü, ���ڷ� ������ ��. ���� ������ ȣ��
	//p.print();

	Player player = CreatePlayer();

	cout << &p << endl;
	Test(p);		// ��ü�� �����ؼ� �ѱ�� ������ ���� ��ġ�� �ٸ�
}