/*----------------------------------------------------------------------------------------
  2021 2학기 C++														        7주 2일 - 2교시
  
  사용자가 새로운 자료형 You를 만든다.

  string과 같은 기능을 갖는 String을 만들며 class 설계에 필요한 것들을 학습
  ----------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include "save.h"
using namespace std;

// [문제] 다음 main()이 문제없이 실행되도록 class String을 코딩하라.
// main() 이 수정되면 안된다.

class String {
	size_t num{};	// 저장한 글자 수
	char* p{};	// 글자가 있는 메모리

public:
	String (const char* str) : num{ strlen(str) } {
		// 1. 글자 수를 센다
		num = strlen(str);
		// 2. 센 수 만큼 글자를 저장할 공간을 요청한다.
		p = new char[num];
		// 3. 그 공간에 p가 가리키는 글자를 저장한다.
		memcpy(p, str, num);

		cout << "생성자(const char*) - 갯수:" << num << ", 주소:" << (void*)p << endl;
	}
	
	~String() {
		cout << "소멸자 -" << num << ", 주소:" << (void*)p << endl;
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
	String s1{ "안녕하세요" };
	String s2{ "C++ 정말 좋은 프로그래밍 언어이다." };

	s2 = s1;

	s1.show();
	s2.show();

	/*save("소스.cpp");*/  
}