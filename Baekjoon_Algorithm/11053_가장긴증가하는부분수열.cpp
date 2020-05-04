#include <iostream>

using namespace std;
int a[1001];
int d[1001];

int main(void) {
	int n,max=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (d[j] >= d[i] &&a[j] < a[i]) d[i]=d[j]+1;
		}
		if (d[i] > max) max = d[i];
	}
	cout << max;
	return 0;
}