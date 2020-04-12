#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string st;
	cin >> st;
	cout << st[0];
	for (int i = 1; i < st.length(); i++) 
		if (st[i - 1] == 45) cout << st[i];
	return 0;
}