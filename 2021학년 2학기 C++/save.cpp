//------------------------------------------------------------------------------------------
// ���޵� �����̸��� �ִ� ���ڸ� �о� "2021 2 C++ ��������.txt"�� �����Ѵ�.
//
// 2021. 2�б� C++                                                              2021. 8. 31
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

	ofstream out{ "2021 2 C++ ��������.txt", ios::app };

	time_t t = chrono::system_clock::to_time_t(chrono::system_clock::now());
	out.imbue(locale(("korean")));

	out << endl << endl;
	out << "--------------------------------------" << endl;
	out << fileName << "����ð� - " << put_time(localtime(&t), "%c %A") << endl;
	out << "--------------------------------------" << endl;
	out << endl;

	// ctrl + o

	while (in >> ch) {

		out << ch;
	}
	out << endl;

	cout << endl;
	cout << fileName << " - �����Ͽ����ϴ�" << endl;
}