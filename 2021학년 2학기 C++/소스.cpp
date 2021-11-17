/*----------------------------------------------------------------------------------------
  2021 2학기 C++				               						  수34목23		   12주 1일

  class 간의 관계 - 상속(inheritance)

  1. 부모/ 자식 - 메모리는 어떻게 구성되나?
  ----------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include "save.h"
using namespace std;

class Animal {
protected:
	string name;

public:
	Animal() {}
	Animal(string s) : name {s} {}
	~Animal() {}

	void move() { cout << "Animal 움직인다" << endl; }
};

class Dog : public Animal {

public:

	Dog() {}
	Dog(string s) : Animal{ s } {  }
	~Dog() {
		cout << "소멸자생성" << endl;
	}

	void move() { cout << this->name << "뛴다" << endl; }

	// this가 숨어서 멤버 변수를 호출한다.
};

//---------
int main()
//---------
{
	Dog a{ "코코" };		// 코코가 뛴다
	Dog b{ "보리" };		// 보리가 뛴다

	a.move();
	b.move();
	
	/*save("소스.cpp");*/
}


