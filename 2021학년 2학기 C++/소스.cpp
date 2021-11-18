/*----------------------------------------------------------------------------------------
  2021 2학기 C++				               						  수34목23		   12주 1일

  class 간의 관계 - 상속(inheritance)

  1. 부모/ 자식 - 메모리는 어떻게 구성되나?
  ----------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include "save.h"
using namespace std;

class Animal {
protected:				// 조상의 private 멤버를 자식의 private 멤버로
	string name;

public:
	Animal() {}
	Animal(string s) : name {s} {}
	~Animal() {}

	virtual void move() { cout << name << " 움직인다" << endl; }
};

class Dog : public Animal {

public:

	Dog() {}
	Dog(string s) : Animal{ s } {
		
	}
	~Dog(){}

	void move() {
		cout << name << " 달린다" << endl;
		PlaySound(L"bark.wav", 0, SND_FILENAME);
	}
	
};


class Bird : public Animal {

public:

	Bird(){}
	Bird(string s) : Animal{s} {}
	~Bird(){}

	void move() {
		cout << name << " 난다" << endl;
		PlaySound(L"새소리.wav", 0, SND_FILENAME); 
	}

};

// c++에서 다형성을 구현하는 핵심 키워드 virtual
// 1. 메모리 크기
// 2. 모든 객체가 vtable을 가리키는 vptr을 추가한다.

// 동물농장 관리자다
// 사용자가 몇 마리의 동물을 관리하는지 입력받아라.
// 임의의 홀짝값에 따라 
// 홀수이면 Dog를 짝수이면 Bird를 생성하라.
// 모든 동물의 move()를 호출하여 다형성이 구현됨을 확인하시오.

// 포인터 여러개를 정적으로 만들어야한다.

//---------
int main()
//---------
{
	cout << "몇 마리를 관리할까요?";
	int num;
	cin >> num;
	
	/*save("소스.cpp");*/
}


