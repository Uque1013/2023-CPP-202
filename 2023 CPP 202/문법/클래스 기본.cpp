// C
#include <stdio.h>
#include <string.h>

// C++
#include <iostream>
#include <string>

using namespace std;

// 여러  data들을 하나의 의미있는 구조체로 묶어서 관리
// 구조체, 클래스는 일반적으로 단어의 첫 글자를 대문자로 함
// class는 디폴트 private (struct는 디폴트가 public)
class Student {

public:
	// 생성자(constructor) : 객체를 생성할 때 호출되는 함수
	// 생성자를 정의하지 않으면 default로 매개변수가 없는 생성자가 정의된다
	Student() {
		hakbun = 2204;
		name = "김예은";
		tel = "010-1234-5678";
		sub = "뉴미디어소프트웨어과";
		address = "서울시 관악구";
	}

private:
	// 성능때문에 hakbun을 문자열로 하지 않음
	// 일반적으로 문자열은 정수형 데이터보다 많은 메모리 공간을 요구하며
	// 정수는 비교연산을 한번에 할 수 있으나, 문자열은 글자수만큼 반복하여 비교해야함
	int hakbun;
	string name;
	string tel;
	string sub;
	string address;

	// class 멤버 함수를 가질 수 있다
	void print() {
		cout << "학생기본정보\n " << endl;
		cout << "학생 학번 :  " << hakbun << endl;
		cout << "학생 이름 : " << name << endl;
		cout << "학생 전화번호 :" << tel << endl;
		cout << "학생 학과 :  " << sub << endl;
		cout << "학생 주소 : " << address << endl;
	}

};

int main(void) {
	// 자료형 : Student(class 생략가능)
	Student 학생1;


	학생1.print();

	return 0;
}