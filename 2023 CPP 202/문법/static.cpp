#include <iostream>
#include <string>

using namespace std;

class Champ {
public:
	Champ(const string& name);
	// static 멤버함수는 객체 생성없이도 호출가능하다
	static int get_cnt(void) {
		return cnt_;
	}
private:
	static int cnt_;
	int non_static;
};

// static 멤버변수는 무조건 바깥에서 정의한다(const 같은거 제외)
int Champ::cnt_ = 0;

// 바깥에서 멤버를 정의할 때는 멤버변수나 멤버함수 이름앞에 클래스이름::
Champ::Champ(const string& name) {
	++cnt_;
}

int main(void)
{
	Champ* a = new Champ("오리아나");
	Champ* b = new Champ("아지르");
	// Champ형 객체의 갯누느 2
	// 메모리에 cnt_ 변수는 한 개만 존재
	// cnt_의 최종값은? 2 

	// static 멤버함수는 객체를 생성하지 않아도 호출할 수 있다
	cout << Champ::get_cnt() << endl;

	/*cout << a->get_cnt() << endl;
	cout << b->get_cnt() << endl;*/

	return 0;
}