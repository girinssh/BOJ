#include <iostream>

using namespace std;

namespace test1 {
	void print() {
		cout << "test1" << endl;
	}
}
namespace test2 {
	void print() {
		cout << "test2" << endl;
	}
}
int main(void) {

	test1::print();
	test2::print();
	
	return 0;
}

// "::" == 범위 지정 연산자