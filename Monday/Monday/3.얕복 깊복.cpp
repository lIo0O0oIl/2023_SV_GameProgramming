#include <iostream>
using namespace std;

/*
얕은 복사 (shallow copy) vs 깊은 복사(deep copy)
=> 클래스를 만들

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
	//복사 생성자
	MyData(const MyData& _data) {
		m_pval = new int;
		*m_pval = *_data.m_pval;
	}
public:
	int m_val;
	int* m_pval = nullptr;
};

int main() {
	MyData a;			// 기본 생성자
	a.m_val = 10;
	cout << a.m_val << endl;
	MyData b(a);		// 복사 생성자
	cout << b.m_val << endl;
}