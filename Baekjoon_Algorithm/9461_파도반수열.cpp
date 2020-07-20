#include <iostream>

using namespace std;

long long p[101] = { 0,1,1,1,2,2};
int main(void) {
	int m;
	cin >> m;
	while (m--) {
		int n;
		cin >> n;
		if (n <= 5) {
			cout << p[n] << endl;
			continue;
		}
		for (int i = 6; i <= n; i++)
			p[i]=p[i - 1] + p[i - 5];
		cout << p[n] << endl;
	}
	return 0;
}