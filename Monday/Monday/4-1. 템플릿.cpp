#include <iostream>
using namespace std;

template<typename T>
T add(T a, T b) {
	return a + b;
}

template<typename T1, typename T2>
T1 sub(T1 a, T2 b) {
	return a - b;
}

// 템플릿 특수화
template<typename T>
void print(T a) {
	cout << a << endl;
}

class Player {
	
};

std::ostream operater << (std::ostream& _out)

int main() {
	add(1, 2);
	add(1.234, 2.55);
}