#pragma once
class test2
{
public:
	void add();
	inline int sub(int a, int b) {		// 내부에서 설계가 되면(많이 쓰기 때문에) 인라인이 붙은 것.
		return a - b;
	}
	// 그러니 함수를 많이 쓸 것 같으면 인라인을 붙여라!
};
class Player {
private:
	int m_posx;
	int m_posy;
public:
	// set, get
	void SetPos();
	inline void SetPos(int x, int y) {		// 이렇게 되서 최적화가 됨. 인라인이 지금 없어도 ㅇ렇게 만들면 붙어있는거임.

	}
	int GetPos() { return m_posx };
};

