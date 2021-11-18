/*----------------------------------------------------------------------------------------
  2021 2�б� C++				               						  ��34��23		   12�� 1��

  class ���� ���� - ���(inheritance)

  1. �θ�/ �ڽ� - �޸𸮴� ��� �����ǳ�?
  ----------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include "save.h"
using namespace std;

class Animal {
protected:				// ������ private ����� �ڽ��� private �����
	string name;

public:
	Animal() {}
	Animal(string s) : name {s} {}
	~Animal() {}

	virtual void move() { cout << name << " �����δ�" << endl; }
};

class Dog : public Animal {

public:

	Dog() {}
	Dog(string s) : Animal{ s } {
		
	}
	~Dog(){}

	void move() {
		cout << name << " �޸���" << endl;
		PlaySound(L"bark.wav", 0, SND_FILENAME);
	}
	
};


class Bird : public Animal {

public:

	Bird(){}
	Bird(string s) : Animal{s} {}
	~Bird(){}

	void move() {
		cout << name << " ����" << endl;
		PlaySound(L"���Ҹ�.wav", 0, SND_FILENAME); 
	}

};

// c++���� �������� �����ϴ� �ٽ� Ű���� virtual
// 1. �޸� ũ��
// 2. ��� ��ü�� vtable�� ����Ű�� vptr�� �߰��Ѵ�.

// �������� �����ڴ�
// ����ڰ� �� ������ ������ �����ϴ��� �Է¹޾ƶ�.
// ������ Ȧ¦���� ���� 
// Ȧ���̸� Dog�� ¦���̸� Bird�� �����϶�.
// ��� ������ move()�� ȣ���Ͽ� �������� �������� Ȯ���Ͻÿ�.

// ������ �������� �������� �������Ѵ�.

//---------
int main()
//---------
{
	cout << "�� ������ �����ұ��?";
	int num;
	cin >> num;
	
	/*save("�ҽ�.cpp");*/
}


