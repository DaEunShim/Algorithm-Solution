#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int>a(n);
	vector<int>d(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int max = a[0];
	d[0] = a[0];
	for (int i = 1; i < n; i++) {
		d[i] = a[i];
		if (d[i - 1] +a[i]> d[i]) 
			d[i] = d[i - 1]+a[i];
		if (max < d[i]) max = d[i];
	}
	cout << max;
	return 0;
}