// has - a(클래스가 서브클래스를 포인터 형태로) 
// is - a(상속:
// 선생님은 사람이야? => 상속!
/*
	(Part - of):		1
	(Has - a):			2
	(Uses - a):			3
	(Depends - on):		4
	여기중에 정답없다:	5
	~가 ~다.
	~가 ~를 하고 있다.
	~가 뭘 가지고 있다.
	has - a
	is - a
	몬스터는 채력, 공격력, 충돌체를 가지고 있다. has - a
	class Monster{
	.....
	}
	// 슬라임. 주황버섯 같은 몬스터가 있다고 할 때. 슬라임은 몬스터다. is - a
*/

class Monster {
	//....
};
class OrangeMush : public Monster {
	//....
};

#include <iostream>
using namespace std;

// 함수 : 코드 반복적인 것을 재사용
// 상속 : 클래스 반복적인 것을 재사용

// 생성자 호출 순서 : 자식 -> 부모
// 생성자 실행 순서 : 부모 -> 자식

class Person
{
private:
public:
protected:		// 상속받은 애만 사용할 수 있게 해줄겡
	string m_name;
public:
	void SetName(const string& _name) { m_name = _name; }
	Person() { cout << "Person 생성" << endl; }
	Person(const string& _name) : m_name(_name) {}
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
	//Teacher() : Person() { cout << "Teacher 생성" << endl; }		// 저게 숨겨져 있음
	Teacher(const string& _sub, const string& _name) : m_subject(_sub), Person(_name) {
		// 자식은 부모의 것을 초기화해줄 수 없음
	}
};

int main() {
	//Person p;
	//p.SetName("Name");
	Teacher t("gamep", "ja");
	t.SetName("d");
	t.Person::SetName("d");		// 범위지정자로 부모의 것에 접근함
}
