#include <iostream>
using namespace std;

// const : ���ȭ
int main() {
	//volatile const int data = 100;			// volatile(�ֹ߼�) : �� �ϸ� ���� �ٲ�
	//100;		// �̰� �� ����� ���ٲ�
	//int* ptr = (int*) & data;		// ��ȯ���ؼ� �־���
	//*ptr = 200;
	//cout << data << endl;
	//data = 101;
	
	// l-value : ����
	// r-value : ���
	//string a = "jun";
	//string b = a;
	//string& b = a;			// l-value ref
	//string&& b = a;			// r-value ref
	//a = "yong";

	// ���ݱ��� const + ������ ��ģ ��.
	// const ������ : �������� ����� ���ȭ��
	// 1. const ������ : ���� ����Ű�� �ִ� ���� ���ȭ
	//int a = 0;
	//int b = 0;
	//const int* ptr = &a;		// �ȿ� �� ���� ���ȭ
	//ptr = &b;		// �� ���� �� �ٲ㵵 ����Ű�� ����� �ٲ� �� ����.
	//*ptr = 10;

	// 2. ������ const : �� �� �ٶ��
	//int* const ptr2 = &a;
	//*ptr2 = 100;
	//ptr2 = &b;

	//const int* const ptr3 = &a;		// �ٶ󺸴� �ֵ�, �ٶ� ���� ���� ������

	// const �� �����Ϳ� �ΰ��� �ൿ�� �� �� ����
	// 1. �� �ڽ��� ���� => �������� ����. ���ٲٰ�
	// 2. Ÿ��� ģ���� ���� ���ٲٰ� (�հ� �ڿ� ���̱�)

	//const int test = 0;			// ���� �ȹٲ���Ѱ�
	//const int* ptr4 = &test;
	//test = 5;	// ������ const �� ������ ����!
	//*ptr4 = 4;		// ���� ������ϴϱ� �ȵ�!

	// ����
	//int val = 10;
	//int* const ptr = &val;
	//*ptr = 100;

	//int& ref = val;
	//ref = 200;
	// �Ʒ��� ���� ���̰� ����
	//cout << &val << endl;
	//cout << &ref << endl;
	//cout << ptr << endl;
	//cout << &ptr << endl;

	//int& ref2;		// �̰� ���� �� ģ���� ��� �Ұ�����
	//int& ref3 = 20;		// 20�� �޸𸮸� ����� �־ �Ұ�����

	//int arr[4] = { 1, 2, 3, 4 };
	//int (&ref2)[4] = arr;		// �̷��� ũ�⵵ �˷������. ������ ���� ��°�. �����ʹ� �ʸ� ����Ű�� ��

	// ��׸� ����. ��۸� ���۷���
	int& num = GetNumber();		// �޼���� �÷������. ���κ��� ���ΰ���
	num = 10;

	// void ������
	int a = 0;
	int* ptr = &a;		// �������� ���·� �ؼ���
	ptr + 1;		// int �� �����ܰ�� �Ѿ

	float f = 1.f;
	double d = 0.;
	long long ll = 0;
	void* pvptr = nullptr;			// � ������ �ؼ��� �� ������ ����
	pvptr = &a;
	pvptr = &f;
	pvptr = &d;
	pvptr = &ll;
	// *pvptr		// ���� �ؼ����� ���� �������� �Ұ�����
	// pvptr + 1;		// �̰� �����ܰ踦 ���� ��������

	//int arr[100] = { 0 };
	float arr[100] = { 0 };
	memset(arr, 0, 100 * sizeof(int));		// �� �Լ��� Ȯ�强�� ���ؼ� �Ű������� ���̵����� �������̴�.
}

void test2(const int& _a) {
	// �̰ſ�
	//const int* const ptr = &val;		// �̰� ����. ����ܽ�.
}

int& GetNumber() {
	int temp = 1;
	return temp;
}