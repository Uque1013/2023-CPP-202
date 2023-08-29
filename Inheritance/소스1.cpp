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
        cout << "ĳ���� �̸� : " << name_ << endl;
        cout << "���� ü�� : " << hp_ << endl;
        cout << "���� ���ݷ� : " << attack_ << endl;
        cout << "���� ���� : " << defense_ << endl;
    }

private:
    string name_;
    T hp_;
    T attack_;
    T defense_;
};

int main(void) {
    Mydata<int>* char1 = new Mydata<int>("����", 10, 5, 7);
    char1->Print();

    delete char1;

    return 0;
}