#include <iostream>

using namespace std;

int main() {
	int n, cnt = 1;
	cin >> n;
	for (int i = 11; i <= n; i = i * 10 +1 ) 
		cnt++;
	cout << cnt <<endl;
	return 0;
}