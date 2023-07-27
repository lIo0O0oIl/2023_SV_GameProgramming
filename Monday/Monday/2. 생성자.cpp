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
	Player(char _val) = delete;		// �̷� �����ڴ� �ƿ� �Ⱦ��ž�

	explicit Player(int m_id)		// ��ȯ �������ε� explicit�� �پ� ��������� ���̵� �־ ���ž�
		: m_id (m_id)
	{
		cout << "int ���ڰ� �ϳ� �� ������" << endl;
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

class Test2 
{
	Test2() = default;		// �⺻�����ڰ� ���� �� �� ���ž�
	Test2() 
	{
	}
}

//void Test(Player _player) {
void Test(Player _player) {			// ������ ���̸� �ּ� ��ġ�� ������, �� ������ ���� ��������!
	cout << "TEST �Լ�" << _player.GetId() << endl;
	//cout << &_player << endl;
}

Player CreatePlayer() {
	Player temp(50, 50);
	return temp;
}

// ��ȯ ������ : �Ű������� �ϳ��� ������. Test �Լ��� int �Լ� �ϳ��� �δ� ������ ��밡��

int main()
{
	//Player p;		// �����ڰ� ��� Ŭ���� ���� �⺻������ �⺻ �����ڰ� ���ԵǾ� ����
	//p.print();

	//Player p(1, 10, 20);
	//Player p2(20, 20);
	//Player p3 = p;		// ���� ������
	//Player(1, 2);		// ��ȸ��. �ӽð�ü
	//Player p4(Player(1, 2));		// �ӽ� ��ü, ���ڷ� ������ ��. ���� ������ ȣ��
	//p.print();

	//Player player = CreatePlayer();		// ��������ڸ� ��ħ. RVO(return value Optimization) : ��ȯ�� ����ȭ�� ��. �� �Լ����� ��쿡��.(�ȿ��� ���� ����� ����)
														// �����Ϸ��� ���ʿ��� ���縦 �ּ�ȭ �ϴ� ���� (C++ 11����)

	//cout << &p << endl;
	//Test(p);		// ��ü�� �����ؼ� �ѱ�� ������ ���� ��ġ�� �ٸ�
	//Test(5);		// explicit �� �پ ���� ����� �ȵ�
	//Player p2(3);

	// delete :  ���� ������� ���� �͵��� ��� delete �� ������ �����ش�. (�Ǽ� ����)
	Player p3('a');		// �� ����~
	//default : �����ڸ� �������� �ʾ����� �⺻ �����ڸ� ���ž�?....?