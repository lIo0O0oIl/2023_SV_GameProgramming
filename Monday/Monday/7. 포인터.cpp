#include <iostream>
using namespace std;

int main() {
	//int x = 5;
	//cout << x << endl;
	//cout << &x << endl;
	//cout << *(&x) << endl;		// ������

	//int i = 100;
	//float f = 3.f;
	//int* ptr = &i;
	//int* fptr = (int*) & f;		// ������ �ٲ���� �ٶ���
	//i = *fptr;		// 1077936128 �̶� ���� ����
	//// �ּҴ� �޸� �ȿ� ����ִ����� �� �� �ִ� ��, �ּ��� ������ ����Ʈ,
	////i = 400;
	////(*ptr) = 400;
	//int a = 0;

	//int* iptr = nullptr;			// 4
	//char* cptr = nullptr;		// 1
	//short* sptr = nullptr;		// 2

	//cout << sizeof(iptr) << endl;		// 8		// 64bit �� ������� �ϰ� �ֱ� ������
	//cout << sizeof(cptr) << endl;		// 8		// 32��Ʈ�� 4�Ⱑ ram �� 4�Ⱑ�� ������ �ǹ̰� ����
	//cout << sizeof(sptr) << endl;		//8

	//int i = 0;
	//int* ptr = &i;
	//i += i;
	//ptr += 1;	// �̰� ��Ʈ�� ���� �ܰ�� �Ѿ.
	//int arr[5] = {1, 2, 3, 4, 5};
	////*(arr + 1) = 10;
	////arr[1] = 10;		// �������� ������
	////[] == *(0 + ?)		// ������
	//cout << arr[0] << endl;		// 1
	//cout << arr << endl;		// 1�� �ּ�
	//cout << &(arr[0]) << endl;		// 1�� �ּ�
	//cout << *arr << endl;		// 1
	//char name[] = "ja";
	//cout << *name << endl;		// j

	// 1. ����
	short sArr[10] = { 1, 2, 3, 4, 5, 6,7, 8, 9, 10 };
	int* ptr = (int*)sArr;
	int data = *((short*)(ptr + 2));
	cout << data << endl;		// 5

	// 2. ����
	char cArr[2] = { 1, 1 };
	short* sPtr = (short*)cArr;
	data = *sPtr;
	cout << data << endl;		//257
}