/*----------------------------------------------------------------------------------------
  2021 2학기 C++				               						  수34목23		   11주 1일 
  
  class 간의 관계 - 상속(inheritance)
  ----------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include "save.h"
using namespace std;

// 부모 - 자식 클래스 상속을 이용하여 표현해 본다.
// 메모리 관계는? 멤버함수 이용은?

class Animal {
	string name;
	int age;

public:
	Animal(string s, int n) : name{s}, age{n} {}
};

class Dog : public Animal {

public:
	Dog(string s, int n) : Animal(s, n) {}
	
	friend ostream& operator<<(ostream& os, const Dog& dog);

	string getName() const {
		return name;
	}
};

ostream& operator<<(ostream& os, const Dog& dog)
{
	os.dog.getName() << ", " << dog.getAge() << endl;
}

//---------
int main()   
//---------
{
	Dog dog{ "코코", 2 };

	cout << dog << endl;

	/*save("소스.cpp");*/  
}


