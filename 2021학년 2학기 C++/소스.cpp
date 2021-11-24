/*----------------------------------------------------------------------------------------
  2021 2�б� C++				               						  ��34��23		   13�� 1��

  class ���� ���� - ���(inheritance)

  1. �θ�/ �ڽ� - �޸𸮴� ��� �����ǳ�?
  ----------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include "save.h"
using namespace std;


// Ŭ���� Animal�� ���������Լ��� �ֱ� ������
// ��ü�� ���� �� �ä���
// �̷� Ŭ������ Abstract Ŭ����(�߻�Ŭ����)
// �ݴ븻 - concrete Ŭ����
class Animal {
protected:

	string name;

public:
	
	// ���������Լ�(pure virtual function)
	virtual void move() const = 0;

};


class Dog : public Animal{

public:

	virtual void move() const override final {
		cout << name << "�޸���" << endl;
	}

};


class Bird : public Animal{

public:

	virtual void move() const override final {
		cout << name << "����" << endl;
	}

};


//---------
int main()
//---------
{
	// ������ Ȯ��
	// [����] ���� 2������ ����� �������� �������� Ȯ���ϴ� �ڵ带 �ۼ��϶�.

	Dog a{};
	Bird b{};

	Animal& p1 = a;
	Animal& p2 = b;

	p1.move();
	p2.move();

	/*save("�ҽ�.cpp");*/
}

