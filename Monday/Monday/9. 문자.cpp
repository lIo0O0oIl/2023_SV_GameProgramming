#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

/*
�޸� ����
1. ���� ���� : ����, �Ű�
2. ������ ���� : ����, ����.. extern(�ܺκ���)
3. �� ���� : �����Ҵ�
4. �ڵ� ����(ROM) : �б⸸ ������, ���ڿ�
*/

int main() {
	// 1�б� - char(1)		1byte -> 8bit -> 2^8		256����, �ƽ�Ű �ڵ�� 2^7 �� 127���� ����
	// utf-8
	// 2�б� - wchar(2)	2byte
	//wchar_t wc = L'a';
	//char c = 1;
	//char c2 = '1';		// �������� �ٸ�
	//int a = 0;
	//cout << _getch() << endl;		// �ƽ�Ű�ڵ尡 ��

	const wchar_t* wptr = L"abcd";	// ������ - ������ ��
	wchar_t warr[10] = L"abcd";			// �迭	- ������
	warr[1] = 's';		// �̰� �Ǵ� ������ ������ ���̱� ������ �ٲ����� ����
	//wptr[1] = 's';
	//*(wptr + 1) = 's';		// ���� ���� ���� ��		// �ι�° ������ ���� �ٲ��

	char cArr[10] = "abc�μ�";		// ��Ƽ����Ʈ ����
	wchar_t cArr[10] = TEXT("abc�μ�");		// �̰� �Ǵ°���
	int a = 0;

	// c��� �����Ҵ� : malloc(), free();
	// C++ �����Ҵ� : new, delete		// �� ������ �ϰڴ�.
	int a = 0;
	//int* ptr = &a;
	int* ptr = new int;		// ������ �� ��
	delete ptr;		
	delete& a;		//������ �� ���� �ƴϱ� ������. ���ø޸𸮿� �ִ� ����. ���� �ƴ϶�
}