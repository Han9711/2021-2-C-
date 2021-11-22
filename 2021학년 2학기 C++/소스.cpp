/*----------------------------------------------------------------------------------------
  2021 2학기 C++				               						             9주 2일 - 2교시

  표준 string과 유사한 기능을 하는
	  string을 만들며 class 설계에 필요한 것들을 학습

 * - 내가 만든 클래스가 자원을 할당받는다면 (모든 이야기는 여기에서 시작)
	 1. 생성자에서 자원을 할당 받는다. (RAII)
	 2. 소멸자에서 자원을 반환한다.
	 3. 복사생성자를 만들어 깊은 복사를 한다.
	 4. 복사할당연산자를 만들어 깊은 복사를 한다.
	 5. 이동생성자를 만들어 복사보다 효율적인 동작이 되게 한다.
	 6. 이동할당연산자도 잊지 말고 만들어야 한다.

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
	size_t num{};	// 저장한 글자 수
	char* p;		// 글자가 있는 메모리

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
		cout << "소멸자 - 갯수:" << num << ", 주소:" << (void*)p << endl;
		delete[] p;
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

		cout << "복사할당연산자 - 갯수:" << num << ", 주소:" << (void*)p << endl;
		
		return *this;
	}

	// 이동 생성자
	String(String&& other) noexcept : num{ other.num }, p{ other.p } {
		other.num = 0;
		other.p = nullptr;
		cout << "이동생성자 - 갯수:" << num << ", 주소:" << (void*)p << endl;
	}

	// 이동할당연산자
	String& operator=(String&& other) noexcept {
		if (this == &other)
			return *this;

		delete[] p;
		num = other.num;
		p = other.p;

		other.num = 0;
		other.p = nullptr;

		cout << "이동할당연산자 - 갯수:" << num << ", 주소:" << (void*)p << endl;

		return *this;
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

// 입출력함수는 friend로 사용한다.
ostream& operator<<(ostream& os, const String& s)
{
	for (int i = 0; i < s.num; ++i)
		os << s.p[i];
	return os;
}

// name을 길이 내림차순으로 정렬한 후
// 화면에 출력하라. (20)


//---------
int main()
//---------
{
	String name[3] = { "파일", "Git", "창"};

	cout << endl;
	cout << "----------------------------------------------------------" << endl;
	sort(begin(name), end(name), [](const String& a, const String& b) {
		return a.size() > b.size();
	});

	/*save("소스.cpp");*/
}