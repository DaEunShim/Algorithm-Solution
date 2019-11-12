#include <iostream>

using namespace std;

int main() {
	int T,n,m;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		long long cnt = 1;
		for (int i = 1; i <= n; i++) {
			cnt = cnt*(m-i+1)/i;
		}
		cout << cnt<<endl;
	}
	return 0;
}