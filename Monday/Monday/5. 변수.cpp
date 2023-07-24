/*
변수의 종류
1. 지역변수, 매개변수
2. 전역변수
3. 정적변수
4. 외부변수

메모리 영역
1. 스택 영역
2. 데이터 영역
3. 힙 영역
4. 코드 영역
*/

#include <iostream>
#include "test.h"
using namespace std;

extern int g_i = 100;		// 전역변수
static int g_si = 0;		// 정적변수
//void tset() {
//	cout << g_si << endl;
//}
//int test2(int _val) {
//	return 2 + _val;
//}
//int test(int _val) {
//	int y = 3;
//	return test2(_val + y);
//}

int main() {
	//int a = 1, b;
	//b = test(a);
	//cout << b << endl;		// 8

	//int* ptr = new int[1000000];		// 동적배열 만들었다가 지우기
	//delete[] ptr;

	// =, (), {}(C++ 11)
	int a = 0;	// c 언어 스타일
	int b(1);		// C++ 스타일
	int c{ 3.5 };	// 엄격함. 잘 잡아줌.

	test();

	int arr[3] = { 1, 2, 3 };	// 크기가 정해져있으며 이름이 첫번째를 가리킴, 서로 연결해준 것
	arr[5];
}