#include <iostream>

using namespace std;
namespace SangSok {
	class Person {
	private:
		int age;
		string name;
	public:
		int GetAge() {};
		string GatName() {};
		Person(int age = 0, string name = "noname") {
			this->age = age;
			this->name = name;
		}
	};

	class Student : Person {
	private:
		string major;
	public:
		Student(string major = "computer") : Person(21, "unknown") {
			this->major = major;
		}
		string GetMajor() {}
		void ShowData() {}
	};

	int main(void) {

	}
}
namespace Friend {
	class A {
	private:
		int a;
	public :
		A() {
			a = 10;
		}
		friend class B;
	};
	class B {
	private:
		int b;
	public :
		void changeAMenber(A objectA) {
			objectA.a = 1;
		}
	};
}