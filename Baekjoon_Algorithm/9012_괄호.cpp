#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main(void) {
	int n;
	cin >> n;
	while (n--) {
		stack <char> s;
		string str;
		bool check = 0; // YES
		cin >> str;
		int len = str.length();
		for (int i = 0; i < len;i++) {
			if (str[i] == '(')
				s.push(str[i]);
			else
				if (s.empty()) {
					check = 1;
					break;
				}
				else s.pop();
		}
		if(check || !s.empty()) cout << "NO" << endl;
		else if(!check) cout << "YES" << endl;
	}
	return 0;
}