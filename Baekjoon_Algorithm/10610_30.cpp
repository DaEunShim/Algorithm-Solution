#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	int n = s.length(),sum=0,ck=0;
	for (int i = 0; i < n; i++) {
		sum += s[i] - '0';
		if (s[i] == '0') ck = 1;
	}
	if (ck == 0 || sum % 3 != 0) cout << -1 << endl;
	else {
		sort(s.begin(), s.end());
		reverse(s.begin(), s.end());
		cout << s;
	}
	return 0;
}