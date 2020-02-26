#include <iostream>

using namespace std;
int ck[1000000];

int pow(int x, int p) {
	int ans = 1;
	for (int i = 0; i < p; i++) {
		ans = ans * x;
	}
	return ans;
}

int next(int a, int p) {
	int na = 0;
	while (a > 0) {
		na += pow(a % 10, p);
		a /= 10;
	}
	return na;
}
int len(int a, int p, int cnt) {
	if (ck[a] != 0) {
		return ck[a] - 1;
	}
	ck[a] = cnt;
	int b = next(a, p);
	return len(b, p, cnt + 1);
}
int main(void) {
	int a, p;
	cin >> a >> p;
	cout<<len(a, p, 1);
	return 0;
}