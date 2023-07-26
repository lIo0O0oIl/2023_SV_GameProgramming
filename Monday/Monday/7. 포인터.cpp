#include <iostream>
using namespace std;

int main() {
	//int x = 5;
	//cout << x << endl;
	//cout << &x << endl;
	//cout << *(&x) << endl;		// 역참조

	//int i = 100;
	//float f = 3.f;
	//int* ptr = &i;
	//int* fptr = (int*) & f;		// 강제로 바꿔버린 바람에
	//i = *fptr;		// 1077936128 이란 값이 나옴
	//// 주소는 메모리 안에 어디있는지를 알 수 있는 값, 주소의 단위는 바이트,
	////i = 400;
	////(*ptr) = 400;
	//int a = 0;

	//int* iptr = nullptr;			// 4
	//char* cptr = nullptr;		// 1
	//short* sptr = nullptr;		// 2

	//cout << sizeof(iptr) << endl;		// 8		// 64bit 로 디버깅을 하고 있기 때문임
	//cout << sizeof(cptr) << endl;		// 8		// 32비트는 4기가 ram 을 4기가로 뽑으면 의미가 없음
	//cout << sizeof(sptr) << endl;		//8

	//int i = 0;
	//int* ptr = &i;
	//i += i;
	//ptr += 1;	// 이건 인트의 다음 단계로 넘어감.
	//int arr[5] = {1, 2, 3, 4, 5};
	////*(arr + 1) = 10;
	////arr[1] = 10;		// 위에꺼랑 같은거
	////[] == *(0 + ?)		// 역참조
	//cout << arr[0] << endl;		// 1
	//cout << arr << endl;		// 1의 주소
	//cout << &(arr[0]) << endl;		// 1의 주소
	//cout << *arr << endl;		// 1
	//char name[] = "ja";
	//cout << *name << endl;		// j

	// 1. 문제
	short sArr[10] = { 1, 2, 3, 4, 5, 6,7, 8, 9, 10 };
	int* ptr = (int*)sArr;
	int data = *((short*)(ptr + 2));
	cout << data << endl;		// 5

	// 2. 문제
	char cArr[2] = { 1, 1 };
	short* sPtr = (short*)cArr;
	data = *sPtr;
	cout << data << endl;		//257
}