#pragma once
#include <iostream>
#include "animal.h"
using namespace std;

class Dog : public Animal {
public:
	void bark(void) {
		cout << "�۸�" << endl;
	}
private:
	int speed;
};