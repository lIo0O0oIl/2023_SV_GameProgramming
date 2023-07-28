class Test {
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;
};

class SubTest : private Test {
public:
	SubTest() {
		m_public;		// public ������,  protected ����� �ϸ� �̰� protected �� �ٲ�
		m_protected;
		m_private;
	}
};

class SuperSubTest : public SubTest {		// ������ private �� �Ǹ� �ƹ��͵� ��ӹ��� ����
public:
	SuperSubTest() {
		m_public;
		m_protected;
		m_private;
	}
};

int main() {
	Test t;
	t.m_public = 123;
	t.m_protected;
	t.m_private;
}