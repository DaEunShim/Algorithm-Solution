#include <iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> kmp(const string &s) {
	int M = s.size();
	vector<int> pi(M, 0);
	int begin = 1, match = 0;
	while (begin + match < M) {
		if (s[begin + match] == s[match]) {
			match++;
			pi[begin + match - 1] = match;
		}
		else {
			if (match == 0) begin++;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}
	return pi;
}
int main(void) {
	string s;
	int n;
	cin >> n >> s;
	vector<int> pi = kmp(s);
	cout << n - pi[n - 1] << endl;
	return 0;
}