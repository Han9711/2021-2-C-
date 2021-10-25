//------------------------------------------------------------------------------------------
// 전달된 파일이름에 있는 글자를 읽어 "2021 2 C++ 강의저장.txt"에 저장한다.
//
// 2021. 2학기 C++                                                              2021. 8. 31
//------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>

using namespace std;

//-------------------------- 
void save(string fileName)
//--------------------------
{
	ifstream in{ fileName };

	char ch;
	in >> noskipws;

	ofstream out{ "2021 2 C++ 강의저장.txt", ios::app };

	time_t t = chrono::system_clock::to_time_t(chrono::system_clock::now());
	out.imbue(locale(("korean")));

	out << endl << endl;
	out << "--------------------------------------" << endl;
	out << fileName << "저장시간 - " << put_time(localtime(&t), "%c %A") << endl;
	out << "--------------------------------------" << endl;
	out << endl;

	// ctrl + o

	while (in >> ch) {

		out << ch;
	}
	out << endl;

	cout << endl;
	cout << fileName << " - 저장하였습니다" << endl;
}