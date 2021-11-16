/*----------------------------------------------------------------------------------------
  2021 2�б� C++				               						         		   9�� 2�� 
  
  ǥ�� string�� ������ ����� �ϴ�
      string�� ����� class ���迡 �ʿ��� �͵��� �н�

  å - 10�� Ŭ���� �����ڿ� �Ҹ���
       11�� ģ�� ����� ������ �����ε�
	   13.01 ���ڿ� Ŭ����
  ----------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <algorithm>
#include "save.h"
using namespace std;

class String {
	size_t num{};
	char* p;

public:
	String() {
		cout << "����Ʈ ������() - ����:" << num << ", �ּ�:" << (void*)p << endl;
	}

	String(const char* str) : num{ strlen(str) } {
		p = new char[num];
		memcpy(p, str, num);

		cout << "������(const char*) - ����: " << num << ", �ּ�:" << (void*)p << endl;
	}

	~String() {
		delete[] p;

		cout << "dtor - Mem(int), ����:" << num << ", �ּ�:" << p << endl;

	}

	String(const String& other) : num{ other.num }, p{ new char[num] } {
		memcpy(p, other.p, num);

		cout << "���������(const String&) - ����: " << num << ", �ּ�:" << (void*)p << endl;
	}

 	String& operator=(const String& other) {
		if (this == &other) {
			return *this;
		}

		delete[] p;
		num = other.num;
		p = new char[num];

		memcpy(p, other.p, num);

		cout << "�Ҵ翬���� - ����:" << num << ", �ּ�:" << (void*)p << endl;
	}

	// ������ �����ε�

	String operator+(const String& rhs) const {
		String temp;
		temp.num = num + rhs.num;
		temp.p = new char[temp.num];

		memcpy(temp.p, p, num);
		memcpy(temp.p + num, rhs.p, rhs.num);

		return temp;
	}


	size_t size() const {
		return num;
	}

	friend ostream& operator<<(ostream&, const String&);
};

ostream& operator<<(ostream& os, const String& s)
{
	for (int i = 0; i < s.num; ++i)
		os << s.p[i];
	return os;
}

// �ڿ��� �����ϴ� Ŭ����
// �ڱⰡ �����ϴ� �ڿ��� �̵���ų ���� �ִ�.
// �̵��� ���纸�� ȿ������ ������ �� �� �ִ�.

//---------
int main()   
//---------
{
	printf("Hello World\n");

	/*save("�ҽ�.cpp");*/  
}

