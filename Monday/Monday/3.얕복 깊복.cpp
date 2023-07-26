#include <iostream>
using namespace std;

/*
���� ���� (shallow copy) vs ���� ����(deep copy)
=> Ŭ������ ����

*/

class MyData {
public:
	MyData();
	MyData(int _val) {
		m_pval = new int;
		*m_pval = _val;
	}
	~MyData() {
		delete m_pval;
	}
	//���� ������
	MyData(const MyData& _data) {
		m_pval = new int;
		*m_pval = *_data.m_pval;
	}
public:
	int m_val;
	int* m_pval = nullptr;
};

int main() {
	MyData a;			// �⺻ ������
	a.m_val = 10;
	cout << a.m_val << endl;
	MyData b(a);		// ���� ������
	cout << b.m_val << endl;
}