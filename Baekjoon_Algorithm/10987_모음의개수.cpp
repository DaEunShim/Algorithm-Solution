#include<iostream>
#include<string>
using namespace std;

string word = {'a','e','i','o','u'};
int main(void) {
	string s;
	int cnt = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < word.length(); j++) {
			if (s[i] == word[j]) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}