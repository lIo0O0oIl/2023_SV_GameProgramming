#pragma once
class test2
{
public:
	void add();
	inline int sub(int a, int b) {		// ���ο��� ���谡 �Ǹ�(���� ���� ������) �ζ����� ���� ��.
		return a - b;
	}
	// �׷��� �Լ��� ���� �� �� ������ �ζ����� �ٿ���!
};
class Player {
private:
	int m_posx;
	int m_posy;
public:
	// set, get
	void SetPos();
	inline void SetPos(int x, int y) {		// �̷��� �Ǽ� ����ȭ�� ��. �ζ����� ���� ��� ������ ����� �پ��ִ°���.

	}
	int GetPos() { return m_posx };
};

