#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int n, max = 0;
	cin >> n;
	vector<int> v(n);
	vector<int> dx(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		dx[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[j] > v[i] && dx[i] < dx[j] + 1) {
				dx[i]++;
			}
		}
		if (max < dx[i]) max = dx[i];
	}
	cout << max << endl;
	return 0;
}