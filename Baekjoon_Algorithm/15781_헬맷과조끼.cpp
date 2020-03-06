#include <iostream>

using namespace std;

int main(void) {
	int n, m,nmax=0,mmax=0;
	cin >> n >> m;
	while (n--) {
		int a;
		cin >> a;
		if (a > nmax) nmax = a;
	}
	while (m--) {
		int b;
		cin >> b;
		if (b > mmax) mmax = b;
	}
	cout << nmax + mmax;
	return 0;
}