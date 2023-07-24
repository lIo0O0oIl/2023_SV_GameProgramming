#include <iostream>
using namespace std;
extern int g_i = 0;
static int g_si = 0;		// 0;
void test() {
	cout << g_si << endl;
}