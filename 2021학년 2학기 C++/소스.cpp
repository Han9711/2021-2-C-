/*----------------------------------------------------------------------------------------
  2021 2학기 C++				               						  수34목23		   13주 1일

  class 간의 관계 - 상속(inheritance)

  1. 부모/ 자식 - 메모리는 어떻게 구성되나?
  ----------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include "save.h"
using namespace std;


// 클래스 Animal은 순수가상함수가 있기 때문에
// 객체를 만들 수 ㅓㅄ다
// 이런 클래스를 Abstract 클래스(추상클래스)
// 반대말 - concrete 클래스
class Animal {
protected:

	string name;

public:
	
	// 순수가상함수(pure virtual function)
	virtual void move() const = 0;

};


class Dog : public Animal{

public:

	virtual void move() const override final {
		cout << name << "달린다" << endl;
	}

};


class Bird : public Animal{

public:

	virtual void move() const override final {
		cout << name << "난다" << endl;
	}

};


//---------
int main()
//---------
{
	// 다형성 확인
	// [문제] 동물 2마리를 만들고 다형성이 구현됨을 확인하는 코드를 작성하라.

	Dog a{};
	Bird b{};

	Animal& p1 = a;
	Animal& p2 = b;

	p1.move();
	p2.move();

	/*save("소스.cpp");*/
}

