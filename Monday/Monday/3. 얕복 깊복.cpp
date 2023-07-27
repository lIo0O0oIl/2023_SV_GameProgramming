#include <iostream>
using namespace std;

/*
* 얕은복사(shallow copy) vs 깊은복사(deep copy)
* => 클래스를 만들잖아? 자료형을 쓰겠다는게 아니라. 내맘대로 하나 구현
* => 그 자료형에 포인터를 넣는 경우가 꽤나 많아
* => 멤버를 포인터로 가지고 있을때 너희들은 얕복, 깊복에 대해서 꼭 생각
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