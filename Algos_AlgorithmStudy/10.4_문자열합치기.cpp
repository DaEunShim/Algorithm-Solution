#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int c;
	cin >> c;
	while (c--) {
		int n, sum=0;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		
		for (int i = 0; i < n-1; i++) {
			sort(v.begin()+i, v.end());
			v[i + 1] += v[i];
			sum += v[i + 1];
		}
		cout << sum << endl;
	}


	return 0;
}