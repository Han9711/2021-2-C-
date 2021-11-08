/*----------------------------------------------------------------------------------------
  2021 2�б� C++														        8�� - 1����
  

  ǥ�� string�� ���� ����� ���� String�� ����� class ���迡 �ʿ��� �͵��� �н�

  class�� �������(�⺻ private)�� �����Ϸ��� �Լ��� �̿��Ѵ�.
  ���� ���� ���� getter
  ���� �� ���� setter �� ����Ѵ�.
  ----------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include "save.h"
using namespace std;

// [����] ���� main()�� �������� ����ǵ��� class String�� �ڵ��϶�.
// main() �� �����Ǹ� �ȵȴ�.

class String {
	size_t num{ };	// ������ ���� ��
	char* p{ };		// ���ڰ� �ִ� �޸�

public:
	String(const char* str) : num{ strlen(str) } {
		p = new char[num];
		memcpy(p, str, num);

		cout << "������(const char*) - ����: " << num << ", �ּ�:" << (void*)p << endl;
	}

	~String() {
		cout << "�Ҹ��� - ����:" << num << ", �ּ�:" << (void*)p << endl;
		delete[] p;
	}

	// �����ð� �̰� �����ϰ� ����
	String& operator=(const String& other) {
		if (this == &other) {
			return *this;
		}

		delete[] p;
		num = other.num;
		p = new char[num];

		memcpy(p, other.p, num);

		cout << "�Ҵ翬���� - ����:" << num << ", �ּ�" << (void*)p << endl;

		return *this;
	}


	// Ŭ������ �ٱ� ������ �����ϱ� ���� �Լ���

	void show() {
		for (int i = 0; i < num; ++i)
			cout << p[i];
		cout << endl;
	}


	// ���ڼ��� �˷��ִ� getter�� ���� �б⸸ �ϱ� ������ class�� �������� �ʴ�.
	// �ٸ� ���� �ϸ� ��������� ���� ���� ���� ���ٴ� ���̴�.
	// �� ��Ȳ�� ���� ��Ȯ�ϰ� �� �Լ��� �̿��ڿ��� �˸� �� �ִٸ� ���ڴ�.
	// -> �Լ��� ������ const�� �ٿ� �� �Լ��� ����ϴ��� ��������� ���� ������ ������ �����ϸ� �ȴ�.

	size_t size() const {
		return num;
	}
};

//---------
int main()   
//---------
{
	String s1{ "�ȳ��ϼ���" };
	String s2{ "C++ ���� ���� ���α׷��� ����̴�" };
	


	/*s1.show();
	s2.show();*/

	/*save("�ҽ�.cpp");*/  
 }