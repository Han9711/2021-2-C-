/*----------------------------------------------------------------------------------------
  2021 2�б� C++				               						             9�� 2�� - 2����

  ǥ�� string�� ������ ����� �ϴ�
	  string�� ����� class ���迡 �ʿ��� �͵��� �н�

 * - ���� ���� Ŭ������ �ڿ��� �Ҵ�޴´ٸ� (��� �̾߱�� ���⿡�� ����)
	 1. �����ڿ��� �ڿ��� �Ҵ� �޴´�. (RAII)
	 2. �Ҹ��ڿ��� �ڿ��� ��ȯ�Ѵ�.
	 3. ��������ڸ� ����� ���� ���縦 �Ѵ�.
	 4. �����Ҵ翬���ڸ� ����� ���� ���縦 �Ѵ�.
	 5. �̵������ڸ� ����� ���纸�� ȿ������ ������ �ǰ� �Ѵ�.
	 6. �̵��Ҵ翬���ڵ� ���� ���� ������ �Ѵ�.

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
	size_t num{};	// ������ ���� ��
	char* p;		// ���ڰ� �ִ� �޸�

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
		cout << "�Ҹ��� - ����:" << num << ", �ּ�:" << (void*)p << endl;
		delete[] p;
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

		cout << "�����Ҵ翬���� - ����:" << num << ", �ּ�:" << (void*)p << endl;
		
		return *this;
	}

	// �̵� ������
	String(String&& other) noexcept : num{ other.num }, p{ other.p } {
		other.num = 0;
		other.p = nullptr;
		cout << "�̵������� - ����:" << num << ", �ּ�:" << (void*)p << endl;
	}

	// �̵��Ҵ翬����
	String& operator=(String&& other) noexcept {
		if (this == &other)
			return *this;

		delete[] p;
		num = other.num;
		p = other.p;

		other.num = 0;
		other.p = nullptr;

		cout << "�̵��Ҵ翬���� - ����:" << num << ", �ּ�:" << (void*)p << endl;

		return *this;
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

// ������Լ��� friend�� ����Ѵ�.
ostream& operator<<(ostream& os, const String& s)
{
	for (int i = 0; i < s.num; ++i)
		os << s.p[i];
	return os;
}

// name�� ���� ������������ ������ ��
// ȭ�鿡 ����϶�. (20)


//---------
int main()
//---------
{
	String name[3] = { "����", "Git", "â"};

	cout << endl;
	cout << "----------------------------------------------------------" << endl;
	sort(begin(name), end(name), [](const String& a, const String& b) {
		return a.size() > b.size();
	});

	/*save("�ҽ�.cpp");*/
}