#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

/*
메모리 영역
1. 스택 영역 : 지역, 매개
2. 데이터 영역 : 정적, 전역.. extern(외부변수)
3. 힙 영역 : 동적할당
4. 코드 영역(ROM) : 읽기만 가능해, 문자열
*/

int main() {
	// 1학기 - char(1)		1byte -> 8bit -> 2^8		256까지, 아스키 코드는 2^7 로 127까지 있음
	// utf-8
	// 2학기 - wchar(2)	2byte
	//wchar_t wc = L'a';
	//char c = 1;
	//char c2 = '1';		// 위에꺼랑 다름
	//int a = 0;
	//cout << _getch() << endl;		// 아스키코드가 뜸

	const wchar_t* wptr = L"abcd";	// 포인터 - 가르긴 것
	wchar_t warr[10] = L"abcd";			// 배열	- 복사함
	warr[1] = 's';		// 이게 되는 이유는 복사한 것이기 때문에 바꿔지는 것임
	//wptr[1] = 's';
	//*(wptr + 1) = 's';		// 위에 꺼랑 같은 것		// 두번째 공간에 가서 바꿔라

	char cArr[10] = "abc부석";		// 멀티바이트 ㅇㅇ
	wchar_t cArr[10] = TEXT("abc부석");		// 이건 되는거지
	int a = 0;

	// c언어 동적할당 : malloc(), free();
	// C++ 동적할당 : new, delete		// 딱 빌려서 하겠다.
	int a = 0;
	//int* ptr = &a;
	int* ptr = new int;		// 빌려서 쓴 것
	delete ptr;		
	delete& a;		//빌려서 쓴 것이 아니기 때문에. 스택메모리에 있는 거임. 힙이 아니라
}