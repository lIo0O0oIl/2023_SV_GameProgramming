/*
������ ����
1. ��������, �Ű�����
2. ��������
3. ��������
4. �ܺκ���

�޸� ����
1. ���� ����
2. ������ ����
3. �� ����
4. �ڵ� ����
*/

#include <iostream>
#include "test.h"
using namespace std;

extern int g_i = 100;		// ��������
static int g_si = 0;		// ��������
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

	//int* ptr = new int[1000000];		// �����迭 ������ٰ� �����
	//delete[] ptr;

	// =, (), {}(C++ 11)
	int a = 0;	// c ��� ��Ÿ��
	int b(1);		// C++ ��Ÿ��
	int c{ 3.5 };	// ������. �� �����.

	test();

	int arr[3] = { 1, 2, 3 };	// ũ�Ⱑ ������������ �̸��� ù��°�� ����Ŵ, ���� �������� ��
	arr[5];
}