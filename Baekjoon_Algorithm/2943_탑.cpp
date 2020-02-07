#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, noTop=0;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++) {
		noTop = 0;
		for (int j = i-1; j >= 0; j--) {
			if (v[j] >= v[i]) {
				cout << j + 1 << " ";
				noTop = 1;
				break;
			}
		}
		if(!noTop) cout << 0 <<" ";
	}
	return 0;
}