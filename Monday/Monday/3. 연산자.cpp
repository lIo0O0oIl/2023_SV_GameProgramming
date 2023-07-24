#include <iostream>
using namespace std;

class Vec2 {
public:
	int posx;
	int posy;
};

int main() {
	// 연산자
	// 1. 산술, 증감, 논리 => ??  클래스는 (사용자정의)자료형(위같은거)이고, 연산자 오버로딩을 알아햐한다.
	// +, -. *, /
	//int val = 10 + 10;		// 레지스터 메모리
	//int val2 = 10;
	//val = 10 % 3;
	int data = 0;
	++data;		// 이게 더 효율적
	data++;		//data += 1;, 다음단계로 증가한다. 포인터에서 다음단계? 다음주소?
}