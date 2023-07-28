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
		m_public;		// public 이지만,  protected 상속을 하면 이게 protected 로 바뀜
		m_protected;
		m_private;
	}
};

class SuperSubTest : public SubTest {		// 위에서 private 가 되면 아무것도 상속받지 않음
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