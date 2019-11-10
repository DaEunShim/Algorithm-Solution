#include<iostream>

using namespace std;

int main() {
	int n, m, k, max=0;
	cin >> n >> m >> k;
	while(n>=2 && m>=1 && n+m>=3+k){
		max++;
		n -= 2;
		m--;
	}
	cout << max<<endl;
	return 0;
}
