#include <iostream>
using namespace std;

// c���� ���� ����� �ϰ� ���� ���� ����ü
// c++ ���� ��ü���� �����鼭 Ŭ������ ���°���

typedef int INT;		// �̸��� �����ذ�
struct  People	// 14 -> 16	(short �ڿ� 2 �����Ⱚ=�е�) = ����ü �е�
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
//alignas(32) ��Ʈ�� �����ٰ�. �忨



int main() {
	People p;
	p.age;
	p.height;
	p.id;
	cout << sizeof(People) << endl;
	cout << sizeof(People2) << endl;
}