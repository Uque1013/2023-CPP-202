﻿// C
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
	// 생성자는 반환형을 쓰지 않는다.
	// 생성자를 정의하지 않으면 default로 매개변수가 없는 생성자가 정의된다
	Student( ) {
		
	}

	// class 멤버 함수를 가질 수 있다
	void print() {
		cout << "학생기본정보\n " << endl;
		cout << "학생 학번 :  " << hakbun << endl;
		cout << "학생 이름 : " << name << endl;
		cout << "학생 전화번호 :" << tel << endl;
		cout << "학생 학과 :  " << sub << endl;
		cout << "학생 주소 : " << address << endl; 
	}

	void set_hakbun(int _hakbun) { hakbun = _hakbun; }
	void set_name(string _name) { name = _name; }
	void set_tel(string _tel) { tel = _tel; }
	void set_sub(string _sub) {sub = _sub; }
	void set_address(string _address) { address = _address; }
	
public : 
	Student(int _hakbun, string _name, string _tel, string _sub, string _address)
		// 멤버변수 초기화, const/참조형 멤버변수 사용 가능	
		: hakbun(_hakbun), name(_name), tel(_tel), sub(_sub), address(_address)
	{
		
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
};

int main(void) {
	// 매개변수가 없는 생성자
	// Student 학생1;
	Student 학생1 = Student();
	// 학생1.print();

	// 정적할당 : 컴파일 시간에 메모리 크키가 결정
	//Student 학생2 = Student(1004, "이용복", "010-0000-0000", "뉴미디어소프트웨어", "호주");
	//학생2.print();

	/*Student 학생3[2];
	
	for (int i = 0; i < 2; i++) {
		학생3[i].print();
	}*/

	// 동적할당 : 실행시간(runtime)에 메모리 크기가 결정(메모리 heap영역)
	//동적할당된 공간은 포인터로 접근한다
	//Student* 학생3 = new Student(1004, "용복", "010-0000-0000", "kpop", "호주");
	//학생3->print();							// 학생3의 멤버는 ->로 접근
	//	
	//// 동적할당 해제(안하면 메모리 누수현상이 발생)
	//delete 학생3;

	Student* 학생4 = new Student[2];
	학생4[0].set_name("이용복");
	학생4[0].set_address("호주");
	학생4[0].set_hakbun(1004);
	학생4[0].set_sub("댄스라차");
	학생4[0].set_tel("000-0000-0000");

	학생4[1].set_name("최범규");
	학생4[1].set_address("서울");
	학생4[1].set_hakbun(313);
	학생4[1].set_sub("천사");
	학생4[1].set_tel("000-0000-0001");


	for (int i = 0; i < 2; i++) {
		학생4[i].print();		// 배열의 요소에 해당하는 객체는 멤버를 .으로 접근
	}
	delete[] 학생4;

	return 0;
}