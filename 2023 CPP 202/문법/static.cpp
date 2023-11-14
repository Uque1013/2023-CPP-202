#include <iostream>
#include <string>

using namespace std;

class Champ {
public:
	Champ(const string& name);
private:
	static int cnt_;
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

	return 0;
}