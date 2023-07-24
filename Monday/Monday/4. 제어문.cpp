#include <iostream>
#include <bitset>
using namespace std;
#define POISON 1
#define ATTACK 2
#define BURN 4

int main() {
	// ��Ʈ ������ 
	int a = 2;
	cout << bitset<4>(a) << endl;

	char c = 1;
	cout << bitset<8>(c) << endl;
	c <<= 1;	// c = c << 1;
	cout << bitset<8>(c) << endl;

	// ��Ʈ ��(&), ��(|), XOR(^), ����(~);
	// & = �Ѵ� 1 �϶��� 1 / | = ���� �ϳ��� 1�̿��� 1 / ^ = �ٸ��� 1, ������ 0
	// RPG ����
	int iStatus = POISON;		// ���ݻ��� �߰��Ϸ���?
	iStatus |= ATTACK;		// �̷���
	if (iStatus & ATTACK) {
		// �������̶���
	}
	// �̹��� �� � ������ ���ݻ��°� ��������
	iStatus &= ~ATTACK;
}