#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void Palindrom(string s, int st, int dr) {

	if (st == dr && s[st] == s[dr] || st > dr) {

		cout << "Palindrom.";
	}
	else {

		if (s[st] == s[dr]) {

			st++; dr--;
			Palindrom(s, st++, dr--);
		}
		else {
			cout << "Nu este palindrom.";
		}
	}
}

int main()
{
	string s = "abba";

	Palindrom(s, 0, s.size()-1);
}
