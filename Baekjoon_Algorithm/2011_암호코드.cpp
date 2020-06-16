#include<iostream>
#include<string>

using namespace std;
int mod = 1000000;
int d[5001];

int main(void) {
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	d[0] = 1;
	for (int i = 1; i <= n; i++) {
		int x = s[i] - '0';
		if (1 <= x && x <= 9) {
			d[i] = (d[i] + d[i - 1]) % mod;
		}
		if (i == 1) continue;
		x = (s[i - 1] - '0') * 10 + (s[i] - '0');
		if (10 <= x && x <= 26) {
			d[i] = (d[i] + d[i - 2]) % mod;
		}
	}
	cout << d[n];
	return 0;
}