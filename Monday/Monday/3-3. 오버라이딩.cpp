#define ATTACK 2

// 다형성 : 형태가 다양하다.
// 오버로딩 : 로딩이 오버된다. 같은 이름의 함수를 여러개(중복 정의) => 조건? 매개변수가 다르고 반환값이 다를 때
// 오버라이딩 : 라이딩이 오버하는 것. 같은 이름의 함수를 재정의

// 재정의가 될 가능성이 있는 함수들은 virtual 을 붙여라
// 자식에서 오버라이딩 한 함수들은 ovrride 를 붙여서 실수를 줄여라.
// 내가 오버라이딩을 그만할거면 final 키워드를 붙인다
// 내가 삭제가 될 가능성이 있는 부모 클래스 소멸자에는 virtual 을 붙여서 가상 소멸자를 만들어라


#include <iostream>
#include <vector>
using namespace std;

// defualt, delete : C++11
// ovrride, final : C++11

class Person
{
private:
public:
protected:		// 상속받은 애만 사용할 수 있게 해줄겡
	string m_name;
public:
	void SetName(const string& _name) { m_name = _name; }
	Person() { cout << "Person 생성" << endl; }
	virtual ~Person() { cout << "Person 소멸" << endl; }
	Person(const string& _name) : m_name(_name) {}
	virtual void print() { cout << "Person" << endl; }		// 버쥬얼을 붙이면 자식클래스에 함수 이름이 같은 함수 앞에 똑같이 달림 중요!!!!
	// 만약에 const 가 붙으면 컴파일러가 오버로딩이라고 생각되어서 오버라이딩이 안됨
};

class Teacher : public Person // 선생님
{
	// Person 이 차지하고 있음
private:
	string m_subject;
public:
	void test() {
		Person::SetName("");
	}
	Teacher() { cout << "Teacher 생성" << endl; }
	~Teacher() { cout << "Teacher 소멸" << endl; }
	//Teacher() : Person() { cout << "Teacher 생성" << endl; }		// 저게 숨겨져 있음
	Teacher(const string& _sub, const string& _name) : m_subject(_sub), Person(_name) {
		// 자식은 부모의 것을 초기화해줄 수 없음
	}
	void print() override final { cout << "teacher" << endl; }		// 상속받았는데 이렇게 이름 다시 쓰는 것이 오버라이딩. 그리고 버츄얼 대신 ovrride 쓴 것도 오버라이딩. 그냥 보기 쉽게 할려고
	using Person::m_name;		// 유징문을 사용해서 이렇게도 가능함
};

class GGmt : public Teacher {
public:
	//void print() {		// 위 처럼 파이널 키워드가 붙으면 더이상의 오버라이딩이 안됨
	//}
};

// 추상 클래스 : 객체 생성이 불가능한거지?
class Test {
public:
	//virtual void func1() = 0;		// 순수 가상함수
	virtual void func1() abstract;		// 위와 같은데 이를 쓰는 이유는 상속받는 클래스들에게 이 함수를 짜달라고 하는것
	virtual void func2() {};
};
class SubTest : public Test{
public:
	void func1() {};
	void func2() {};
};

// 다중상속 -> 
//class MyMachine {	// 추상클래스(변수가 있음) <-> 인터페이스클래스(이건 다 순수가상함수만 있음)
//private:
//	
//public:
//	virtual int GetId() abstract;
//public:
//	int id;
//};

class elec
{
public:
	int m_id;
};

class Phone : virtual public elec {
	virtual int GetId() {};		// 버츄얼 생략 가능해보임...?
private:
	int m_id;
public:
	void Calling() {};
	int GetId() { return m_id; }
	Phone(int _id) : m_id(_id) {}
};

class Keyboard : virtual public elec {
	virtual int GetId() {};
private:
	int m_id;
public:
	void Gameing() {};
	const int GetId() const { return m_id; }
	Keyboard(int _id) : m_id(_id) {}
	virtual void print() { cout << "keyboard" << endl; }
};

class Me : public Phone, public Keyboard {
public:
	Me(int _cellphone_id, int _notebook_id) : Phone(_cellphone_id), Keyboard(_notebook_id) {}
	void print() { cout << "me" << endl; }
};

/*
정적 바인딩(early) vs 동적 바인딩(late)
 정적바인딩 : 컴파일 시간에 메모리를 할당함 ex) 일반함수
 동적바인딩 : 가상함수를 통해서 얘가 어디를 찾아가는구나 ex) 오버라이딩...
*/
int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }

int main() {
	Person p;
	//p.print();
	Teacher t;
	//t.print();

	//Person* pPerson = &t;
	//Teacther* pTeacher = &p;		// 위에것은 가능하나 이건 공간이 없기에 불가능함

	Person* pPerson = nullptr;
	p.print();		// person;
	pPerson = &p;
	pPerson->print();		//person

	t.print();	// teacher
	pPerson = &t;
	pPerson->print();		//person		펄슨으로 해석을 하기 때문에 펄슨 프린트가 찍힘. 그러나 버츄얼읇 붙이면 티져나옴

	//int a = 0;
	//(float)a;
	//static_cast<int>(a);		// 가장보편화
	//dynamic_cast<int>(a);
	//const_cast<int>(a);		// 상수 땔 때..?
	//reinterpret_cast<int>(a);		// 무조껀 강제로 형변환 할거야

	//cout << p << endl;
	//cout << t << endl;		// 연산자 오버로딩함. 상속받고있어서 Person으로 형변환 가능함

	//t.m_name;		// 유징문써서 사용가능

	Teacher* tea = new Teacher;
	Person* per = tea;
	delete per;		// 티쳐는 소멸자가 안불러짐, 그러나 펄슨에 소멸자에 버츄얼을 붙이면 가능해짐. 삭제하고 올라와서 내꺼도 삭제함

	cout << sizeof(Test) << endl;			// 포인터를 안에서 사용이 되어서 포인터 크키가 출력됨
	cout << sizeof(SubTest) << endl;		// 8 혹은 1~
	cout << sizeof(int*) << endl;

	//Test test;		// 추상 클래스라서 못만들어용~
	SubTest subTest;		// 구현이 되어있어야 객체를 만드는 것이 가능함
	//Phone phone;

	int x, y, select, result;
	cin >> x >> y;
	cout << "0: 덧셈, 1: 뺄셈";
	cin >> select;
	switch (select)
	{
	case 0:
		result = add(x, y);
	default:
		break;
	}		// 정적 바인딩! 잘 보임

	Me me(1, 2);
	Keyboard k(3);
	k = me;
	vector<Keyboard*> vec_key;		// *, &(넣을때, 넣을 때가 아닌 이 줄에 &를 써서 vec를 만들면 안됨), -> 을 사용하지 않으면 객체 잘림
	// 참조를 하는 어쩌구도 있음 ㅇㅇ
	vec_key.push_back(&k);
	vec_key.push_back(&me);
	for (auto& e : vec_key) {
		e->print();
	}
	cout << &me.Phone::elec::m_id << endl;
	cout << &me.Keyboard::elec::m_id << endl;		// 본래 위와 주소가 다른데 상속 전에 버츄얼을 붙이면 똑같은 것을 상속받게 되는 것임. 사실 나는 하나였오
	me.Calling();
	me.Gameing();
	me.Phone::GetId();
	//me.Keyboard::GetId();	// 얘 와이러노!
}
