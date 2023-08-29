#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Mydata {
public:
    Mydata(string name, T hp, T attack, T defense) :
        name_(name), hp_(hp), attack_(attack), defense_(defense)
    {    }

    void Print()
    {
        cout << "캐릭터 이름 : " << name_ << endl;
        cout << "현재 체력 : " << hp_ << endl;
        cout << "현재 공격력 : " << attack_ << endl;
        cout << "현재 방어력 : " << defense_ << endl;
    }

private:
    string name_;
    T hp_;
    T attack_;
    T defense_;
};

int main(void) {
    Mydata<int>* char1 = new Mydata<int>("예은", 10, 5, 7);
    char1->Print();

    delete char1;

    return 0;
}