#include <iostream>

using namespace std;

class MString {

public :

	MString(const char* str) 
	{
		cout << "문자 : " << c_str() << endl;
		size_ = strlen(str);
		c_str_= new char[size_ + 1];
	}

public:
	unsigned int size(void) { return size_; }
	char* c_str(void) { return c_str_; }

private:
	unsigned int size_;					// 문자열의 길이
	char* c_str_;								// 문자열의 시작 주소
};

int main(void) {
	MString* str = new MString("I will be back");
	cout << str->c_str() << endl;

	return 0;
}