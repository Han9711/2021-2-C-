/*----------------------------------------------------------------------------------------
  2021 2�б� C++				               						  ��34��23		   12�� 1��

  class ���� ���� - ���(inheritance)

  1. �θ�/ �ڽ� - �޸𸮴� ��� �����ǳ�?
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

	void move() { cout << "Animal �����δ�" << endl; }
};

class Dog : public Animal {

public:

	Dog() {}
	Dog(string s) : Animal{ s } {  }
	~Dog() {
		cout << "�Ҹ��ڻ���" << endl;
	}

	void move() { cout << this->name << "�ڴ�" << endl; }

	// this�� ��� ��� ������ ȣ���Ѵ�.
};

//---------
int main()
//---------
{
	Dog a{ "����" };		// ���ڰ� �ڴ�
	Dog b{ "����" };		// ������ �ڴ�

	a.move();
	b.move();
	
	/*save("�ҽ�.cpp");*/
}


