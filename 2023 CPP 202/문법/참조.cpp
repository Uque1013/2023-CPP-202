﻿#include <iostream>

using namespace std;

int main(void) {
	int a = 30;				// a : 30
	int* pa = &a;			// pa : a의 주소값(&a)

	*pa = 100;				// pa가 가리키고 있는 대상 : 100

	cout << "a의 값은 " << a << endl;

	return 0;
}