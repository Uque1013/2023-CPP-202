#include <iostream>

using namespace std;

int main(void)
{
	double arr[4] = { 1.1, 2.2, 3.3, 4.4 };

	// 누가봐도 a의 자료형은 int이다
	auto a = 4;

	// x의 자료형은 double로 자동설정
	for (auto x : arr)
		cout << x << endl;

	return 0;
}