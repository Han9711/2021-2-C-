/*----------------------------------------------------------------------------------------
  2021 2�б� C++				               						  ��34��23		   11�� 1�� 
  
  class ���� ���� - ���(inheritance)
  ----------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include "save.h"
using namespace std;

// �θ� - �ڽ� Ŭ���� ����� �̿��Ͽ� ǥ���� ����.
// �޸� �����? ����Լ� �̿���?

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
	Dog dog{ "����", 2 };

	cout << dog << endl;

	/*save("�ҽ�.cpp");*/  
}


