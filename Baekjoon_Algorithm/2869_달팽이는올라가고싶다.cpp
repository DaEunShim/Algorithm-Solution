#include <iostream>

using namespace std;

int main() {
	int a, b, v, days = 1;
	cin >> a >> b >> v;
	days = v == a ? 1 : (v - b - 1) / (a - b) + 1;
	cout << days << endl;
	return 0;
}