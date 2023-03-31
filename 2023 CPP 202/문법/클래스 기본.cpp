// C
#include <stdio.h>
#include <string.h>

// C++
#include <iostream>
#include <string>

using namespace std;

// 여러  data들을 하나의 의미있는 구조체로 묶어서 관리
// 구조체, 클래스는 일반적으로 단어의 첫 글자를 대문자로 함
struct Student {
	// 성능때문에 hakbun을 문자열로 하지 않음
	// 일반적으로 문자열은 정수형 데이터보다 많은 메모리 공간을 요구하며
	// 정수는 비교연산을 한번에 할 수 있으나, 문자열은 글자수만큼 반복하여 비교해야함
	int hakbun;
	string name;
	string tel;
	string sub;
	string address;
};	

int main(void) {
	
	struct Student 학생1;
	학생1.hakbun = 2204;
	학생1.name = "김예은";
	학생1.tel = "010-1234-5678";
	학생1.sub = "뉴미디어소프트웨어과";
	학생1.address = "서울시 관악구";

	cout << "학생기본정보\n " << endl;
	cout << "학생 학번 :  " << 학생1.hakbun << endl;
	cout << "학생 이름 : " << 학생1.name << endl;
	cout << "학생 전화번호 :" << 학생1.tel << endl;
	cout << "학생 학과 :  " << 학생1.sub << endl;
	cout << "학생 주소 : " << 학생1.address << endl;

	return 0;
}