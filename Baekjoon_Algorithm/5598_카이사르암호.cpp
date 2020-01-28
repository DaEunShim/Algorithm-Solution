#include <iostream>
#include <string>
using namespace std;


int main(void) {
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		int word = str[i];
		word -= 3;
		if (word < 'A')
			word += 26;
		cout << (char)word;
	}
	cout << endl;
	return 0;
}