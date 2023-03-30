// C
#include <stdio.h>
#include <string.h>

// C++
#include <iostream>
#include <string>

using namespace std;
struct pizza {
	string brand;
	string menu;
};	// 여러 데이터를 한 곳에 담고 있는게 구조체

int main(void) {
	struct pizza 오늘먹을피자;
	오늘먹을피자.brand = "피자스쿨";
	오늘먹을피자.menu = "고구마피자";

	cout << "브랜드 : " << 오늘먹을피자.brand << endl;
	cout << "메뉴 : " << 오늘먹을피자.menu << endl;

	return 0;
}