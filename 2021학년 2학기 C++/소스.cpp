/*----------------------------------------------------------------------------------------
  2021 2학기 C++				               						         		   9주 2일 
  
  표준 string과 유사한 기능을 하는
      string을 만들며 class 설계에 필요한 것들을 학습

  책 - 10장 클래스 생성자와 소멸자
       11장 친구 관계와 연산자 오버로딩
	   13.01 문자열 클래스
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
		cout << "디폴트 생성자() - 갯수:" << num << ", 주소:" << (void*)p << endl;
	}

	String(const char* str) : num{ strlen(str) } {
		p = new char[num];
		memcpy(p, str, num);

		cout << "생성자(const char*) - 갯수: " << num << ", 주소:" << (void*)p << endl;
	}

	~String() {
		delete[] p;

		cout << "dtor - Mem(int), 갯수:" << num << ", 주소:" << p << endl;

	}

	String(const String& other) : num{ other.num }, p{ new char[num] } {
		memcpy(p, other.p, num);

		cout << "복사생성자(const String&) - 갯수: " << num << ", 주소:" << (void*)p << endl;
	}

 	String& operator=(const String& other) {
		if (this == &other) {
			return *this;
		}

		delete[] p;
		num = other.num;
		p = new char[num];

		memcpy(p, other.p, num);

		cout << "할당연산자 - 갯수:" << num << ", 주소:" << (void*)p << endl;
	}

	// 연산자 오버로딩

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

// 자원을 관리하는 클래스
// 자기가 관리하는 자원을 이동시킬 수도 있다.
// 이동은 복사보다 효율적이 동작이 될 수 있다.

//---------
int main()   
//---------
{
	printf("Hello World\n");

	/*save("소스.cpp");*/  
}

