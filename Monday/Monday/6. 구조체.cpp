#include <iostream>
using namespace std;

// c에서 내가 맘대로 하고 싶은 것이 구조체
// c++ 에서 객체지향 나오면서 클래스가 나온거임

typedef int INT;		// 이름만 정해준것
struct  People	// 14 -> 16	(short 뒤에 2 쓰레기값=패딩) = 구조체 패딩
{
	short id;		//2
	int age;			//4
	double height;		//8
};
struct alignas(32) People2		// 17 -> 24 (17+24)
{
	double height;		//8
	int id;		//4
	int age;			//4byte
	char c1;		//1
};
//alignas(32) 비트씩 보낸다고. 흐엥



int main() {
	People p;
	p.age;
	p.height;
	p.id;
	cout << sizeof(People) << endl;
	cout << sizeof(People2) << endl;
}