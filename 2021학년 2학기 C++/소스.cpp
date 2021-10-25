/*----------------------------------------------------------------------------------------
  2021 2�б� C++														        7�� 2�� - 2����
  
  ����ڰ� ���ο� �ڷ��� You�� �����.

  string�� ���� ����� ���� String�� ����� class ���迡 �ʿ��� �͵��� �н�
  ----------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include "save.h"
using namespace std;

// [����] ���� main()�� �������� ����ǵ��� class String�� �ڵ��϶�.
// main() �� �����Ǹ� �ȵȴ�.

class String {
	size_t num{};	// ������ ���� ��
	char* p{};	// ���ڰ� �ִ� �޸�

public:
	String (const char* str) : num{ strlen(str) } {
		// 1. ���� ���� ����
		num = strlen(str);
		// 2. �� �� ��ŭ ���ڸ� ������ ������ ��û�Ѵ�.
		p = new char[num];
		// 3. �� ������ p�� ����Ű�� ���ڸ� �����Ѵ�.
		memcpy(p, str, num);

		cout << "������(const char*) - ����:" << num << ", �ּ�:" << (void*)p << endl;
	}
	
	~String() {
		cout << "�Ҹ��� -" << num << ", �ּ�:" << (void*)p << endl;
		delete[] p;
	}

	String& operator=(const String& other) {
		if (this == &other) {
			return *this;
		}

		delete[] p;
		num = other.num;
		p = new char[num];

		memcpy(p, other.p, num);

		return *this;
	}

	void show() {
		for (int i = 0; i < num; ++i)
			cout << p[i];
		cout << endl;
	}
};

//---------
int main()   
//---------
{
	String s1{ "�ȳ��ϼ���" };
	String s2{ "C++ ���� ���� ���α׷��� ����̴�." };

	s2 = s1;

	s1.show();
	s2.show();

	/*save("�ҽ�.cpp");*/  
}