#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) 
{

	map<string, int> music;

	music["eta"] = 2023;
	music["hype boy"] = 2022;
	music["asap"] = 2023;
	music["eleven"] = 2021;

	cout << music["eta"] << endl;

	map<string, int>::iterator iter;
	for(iter = music.begin(); iter!=music.end(); iter++)
		cout << iter->first << iter->second << " ";


	return 0;
}