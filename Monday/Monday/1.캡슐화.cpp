#include <iostream>
using namespace std;

// Ä¸½¶È­ : get, set

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
	const int& GetId() { return m_id; }
};

int main()
{
	Player p;
	p.SetStat(1, 10, 12);
	//p.m_id = 1;
	//p.m_str = 10;
	//p.m_idx = 12;
}