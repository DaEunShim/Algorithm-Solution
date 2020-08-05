#include <iostream>

using namespace std;
long long d[100][2];

int main() {
	int N;
	cin >> N;
	d[1][0] = 0;
	d[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}
	long long total;
	total = d[N][0] + d[N][1];
	cout << total <<endl;
	return 0;
}

