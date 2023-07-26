#include <iostream>
using namespace std;

// const : 상수화
int main() {
	//volatile const int data = 100;			// volatile(휘발성) : 을 하면 값이 바뀜
	//100;		// 이건 찐 상수라 못바꿈
	//int* ptr = (int*) & data;		// 변환을해서 넣어줌
	//*ptr = 200;
	//cout << data << endl;
	//data = 101;
	
	// l-value : 변수
	// r-value : 상수
	//string a = "jun";
	//string b = a;
	//string& b = a;			// l-value ref
	//string&& b = a;			// r-value ref
	//a = "yong";

	// 지금까진 const + 포인터 합친 것.
	// const 포인터 : 포인터의 기능을 상수화함
	// 1. const 포인터 : 내가 가르키고 있는 값을 상수화
	//int a = 0;
	//int b = 0;
	//const int* ptr = &a;		// 안에 들어간 값을 상수화
	//ptr = &b;		// 들어간 값은 못 바꿔도 가르키는 대상을 바꿀 순 있음.
	//*ptr = 10;

	// 2. 포인터 const : 한 놈만 바라봐
	//int* const ptr2 = &a;
	//*ptr2 = 100;
	//ptr2 = &b;

	//const int* const ptr3 = &a;		// 바라보는 애도, 바라본 애의 값도 고정됨

	// const 는 포인터에 두가지 행동을 할 수 있음
	// 1. 나 자신을 고정 => 변경대상을 고정. 못바꾸게
	// 2. 타고들어간 친구의 값을 못바꾸게 (앞과 뒤에 붙이기)

	//const int test = 0;			// 값이 안바뀌게한것
	//const int* ptr4 = &test;
	//test = 5;	// 변수에 const 가 없으면 가능!
	//*ptr4 = 4;		// 값을 상수와하니까 안됨!

	// 참조
	//int val = 10;
	//int* const ptr = &val;
	//*ptr = 100;

	//int& ref = val;
	//ref = 200;
	// 아래와 위는 차이가 없음
	//cout << &val << endl;
	//cout << &ref << endl;
	//cout << ptr << endl;
	//cout << &ptr << endl;

	//int& ref2;		// 이건 같이 살 친구가 없어서 불가능함
	//int& ref3 = 20;		// 20이 메모리를 안잡고 있어서 불가능함

	//int arr[4] = { 1, 2, 3, 4 };
	//int (&ref2)[4] = arr;		// 이렇게 크기도 알려줘야함. 참조는 같이 사는것. 포인터는 너를 가르키는 것

	// 댕그링 현상. 댕글링 레퍼런스
	int& num = GetNumber();		// 메서드들 올려줘야함. 메인보다 위로가게
	num = 10;

	// void 포인터
	int a = 0;
	int* ptr = &a;		// 정수형의 형태로 해석함
	ptr + 1;		// int 의 다음단계로 넘어감

	float f = 1.f;
	double d = 0.;
	long long ll = 0;
	void* pvptr = nullptr;			// 어떤 식으로 해석할 지 정하지 않음
	pvptr = &a;
	pvptr = &f;
	pvptr = &d;
	pvptr = &ll;
	// *pvptr		// 뭘로 해석할지 몰라 역참조가 불가능함
	// pvptr + 1;		// 이건 다음단계를 몰라서 물가능함

	//int arr[100] = { 0 };
	float arr[100] = { 0 };
	memset(arr, 0, 100 * sizeof(int));		// 이 함수는 확장성을 위해서 매개변수가 보이드형의 포인터이다.
}

void test2(const int& _a) {
	// 이거와
	//const int* const ptr = &val;		// 이게 같음. 일편단심.
}

int& GetNumber() {
	int temp = 1;
	return temp;
}