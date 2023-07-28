// has - a(Ŭ������ ����Ŭ������ ������ ���·�) 
// is - a(���:
// �������� ����̾�? => ���!
/*
	(Part - of):		1
	(Has - a):			2
	(Uses - a):			3
	(Depends - on):		4
	�����߿� �������:	5
	~�� ~��.
	~�� ~�� �ϰ� �ִ�.
	~�� �� ������ �ִ�.
	has - a
	is - a
	���ʹ� ä��, ���ݷ�, �浹ü�� ������ �ִ�. has - a
	class Monster{
	.....
	}
	// ������. ��Ȳ���� ���� ���Ͱ� �ִٰ� �� ��. �������� ���ʹ�. is - a
*/

class Monster {
	//....
};
class OrangeMush : public Monster {
	//....
};

#include <iostream>
using namespace std;

// �Լ� : �ڵ� �ݺ����� ���� ����
// ��� : Ŭ���� �ݺ����� ���� ����

// ������ ȣ�� ���� : �ڽ� -> �θ�
// ������ ���� ���� : �θ� -> �ڽ�

class Person
{
private:
public:
protected:		// ��ӹ��� �ָ� ����� �� �ְ� ���ٰ�
	string m_name;
public:
	void SetName(const string& _name) { m_name = _name; }
	Person() { cout << "Person ����" << endl; }
	Person(const string& _name) : m_name(_name) {}
};
class Teacher : public Person // ������
{
	// Person �� �����ϰ� ����
private:
	string m_subject;
public:
	void test() {
		Person::SetName("");
	}
	Teacher() { cout << "Teacher ����" << endl; }
	//Teacher() : Person() { cout << "Teacher ����" << endl; }		// ���� ������ ����
	Teacher(const string& _sub, const string& _name) : m_subject(_sub), Person(_name) {
		// �ڽ��� �θ��� ���� �ʱ�ȭ���� �� ����
	}
};

int main() {
	//Person p;
	//p.SetName("Name");
	Teacher t("gamep", "ja");
	t.SetName("d");
	t.Person::SetName("d");		// ���������ڷ� �θ��� �Ϳ� ������
}
