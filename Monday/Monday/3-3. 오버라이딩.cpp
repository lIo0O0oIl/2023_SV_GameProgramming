#define ATTACK 2

// ������ : ���°� �پ��ϴ�.
// �����ε� : �ε��� �����ȴ�. ���� �̸��� �Լ��� ������(�ߺ� ����) => ����? �Ű������� �ٸ��� ��ȯ���� �ٸ� ��
// �������̵� : ���̵��� �����ϴ� ��. ���� �̸��� �Լ��� ������

// �����ǰ� �� ���ɼ��� �ִ� �Լ����� virtual �� �ٿ���
// �ڽĿ��� �������̵� �� �Լ����� ovrride �� �ٿ��� �Ǽ��� �ٿ���.
// ���� �������̵��� �׸��ҰŸ� final Ű���带 ���δ�
// ���� ������ �� ���ɼ��� �ִ� �θ� Ŭ���� �Ҹ��ڿ��� virtual �� �ٿ��� ���� �Ҹ��ڸ� ������


#include <iostream>
#include <vector>
using namespace std;

// defualt, delete : C++11
// ovrride, final : C++11

class Person
{
private:
public:
protected:		// ��ӹ��� �ָ� ����� �� �ְ� ���ٰ�
	string m_name;
public:
	void SetName(const string& _name) { m_name = _name; }
	Person() { cout << "Person ����" << endl; }
	virtual ~Person() { cout << "Person �Ҹ�" << endl; }
	Person(const string& _name) : m_name(_name) {}
	virtual void print() { cout << "Person" << endl; }		// ������� ���̸� �ڽ�Ŭ������ �Լ� �̸��� ���� �Լ� �տ� �Ȱ��� �޸� �߿�!!!!
	// ���࿡ const �� ������ �����Ϸ��� �����ε��̶�� �����Ǿ �������̵��� �ȵ�
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
	~Teacher() { cout << "Teacher �Ҹ�" << endl; }
	//Teacher() : Person() { cout << "Teacher ����" << endl; }		// ���� ������ ����
	Teacher(const string& _sub, const string& _name) : m_subject(_sub), Person(_name) {
		// �ڽ��� �θ��� ���� �ʱ�ȭ���� �� ����
	}
	void print() override final { cout << "teacher" << endl; }		// ��ӹ޾Ҵµ� �̷��� �̸� �ٽ� ���� ���� �������̵�. �׸��� ����� ��� ovrride �� �͵� �������̵�. �׳� ���� ���� �ҷ���
	using Person::m_name;		// ��¡���� ����ؼ� �̷��Ե� ������
};

class GGmt : public Teacher {
public:
	//void print() {		// �� ó�� ���̳� Ű���尡 ������ ���̻��� �������̵��� �ȵ�
	//}
};

// �߻� Ŭ���� : ��ü ������ �Ұ����Ѱ���?
class Test {
public:
	//virtual void func1() = 0;		// ���� �����Լ�
	virtual void func1() abstract;		// ���� ������ �̸� ���� ������ ��ӹ޴� Ŭ�����鿡�� �� �Լ��� ¥�޶�� �ϴ°�
	virtual void func2() {};
};
class SubTest : public Test{
public:
	void func1() {};
	void func2() {};
};

// ���߻�� -> 
//class MyMachine {	// �߻�Ŭ����(������ ����) <-> �������̽�Ŭ����(�̰� �� ���������Լ��� ����)
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
	virtual int GetId() {};		// ����� ���� �����غ���...?
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
���� ���ε�(early) vs ���� ���ε�(late)
 �������ε� : ������ �ð��� �޸𸮸� �Ҵ��� ex) �Ϲ��Լ�
 �������ε� : �����Լ��� ���ؼ� �갡 ��� ã�ư��±��� ex) �������̵�...
*/
int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }

int main() {
	Person p;
	//p.print();
	Teacher t;
	//t.print();

	//Person* pPerson = &t;
	//Teacther* pTeacher = &p;		// �������� �����ϳ� �̰� ������ ���⿡ �Ұ�����

	Person* pPerson = nullptr;
	p.print();		// person;
	pPerson = &p;
	pPerson->print();		//person

	t.print();	// teacher
	pPerson = &t;
	pPerson->print();		//person		�޽����� �ؼ��� �ϱ� ������ �޽� ����Ʈ�� ����. �׷��� ����� ���̸� Ƽ������

	//int a = 0;
	//(float)a;
	//static_cast<int>(a);		// ���庸��ȭ
	//dynamic_cast<int>(a);
	//const_cast<int>(a);		// ��� �� ��..?
	//reinterpret_cast<int>(a);		// ������ ������ ����ȯ �Ұž�

	//cout << p << endl;
	//cout << t << endl;		// ������ �����ε���. ��ӹް��־ Person���� ����ȯ ������

	//t.m_name;		// ��¡���Ἥ ��밡��

	Teacher* tea = new Teacher;
	Person* per = tea;
	delete per;		// Ƽ�Ĵ� �Ҹ��ڰ� �Ⱥҷ���, �׷��� �޽��� �Ҹ��ڿ� ������� ���̸� ��������. �����ϰ� �ö�ͼ� ������ ������

	cout << sizeof(Test) << endl;			// �����͸� �ȿ��� ����� �Ǿ ������ ũŰ�� ��µ�
	cout << sizeof(SubTest) << endl;		// 8 Ȥ�� 1~
	cout << sizeof(int*) << endl;

	//Test test;		// �߻� Ŭ������ ��������~
	SubTest subTest;		// ������ �Ǿ��־�� ��ü�� ����� ���� ������
	//Phone phone;

	int x, y, select, result;
	cin >> x >> y;
	cout << "0: ����, 1: ����";
	cin >> select;
	switch (select)
	{
	case 0:
		result = add(x, y);
	default:
		break;
	}		// ���� ���ε�! �� ����

	Me me(1, 2);
	Keyboard k(3);
	k = me;
	vector<Keyboard*> vec_key;		// *, &(������, ���� ���� �ƴ� �� �ٿ� &�� �Ἥ vec�� ����� �ȵ�), -> �� ������� ������ ��ü �߸�
	// ������ �ϴ� ��¼���� ���� ����
	vec_key.push_back(&k);
	vec_key.push_back(&me);
	for (auto& e : vec_key) {
		e->print();
	}
	cout << &me.Phone::elec::m_id << endl;
	cout << &me.Keyboard::elec::m_id << endl;		// ���� ���� �ּҰ� �ٸ��� ��� ���� ������� ���̸� �Ȱ��� ���� ��ӹް� �Ǵ� ����. ��� ���� �ϳ�����
	me.Calling();
	me.Gameing();
	me.Phone::GetId();
	//me.Keyboard::GetId();	// �� ���̷���!
}
