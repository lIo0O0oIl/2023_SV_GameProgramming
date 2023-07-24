#include <iostream>
#include <bitset>
using namespace std;
#define POISON 1
#define ATTACK 2
#define BURN 4

int main() {
	// 비트 연산자 
	int a = 2;
	cout << bitset<4>(a) << endl;

	char c = 1;
	cout << bitset<8>(c) << endl;
	c <<= 1;	// c = c << 1;
	cout << bitset<8>(c) << endl;

	// 비트 곱(&), 합(|), XOR(^), 반전(~);
	// & = 둘다 1 일때만 1 / | = 둘중 하나만 1이여도 1 / ^ = 다르면 1, 같으면 0
	// RPG 게임
	int iStatus = POISON;		// 공격상태 추가하려면?
	iStatus |= ATTACK;		// 이렇게
	if (iStatus & ATTACK) {
		// 공격중이란다
	}
	// 이번엔 딱 어떤 시점에 공격상태가 지워지기
	iStatus &= ~ATTACK;
}