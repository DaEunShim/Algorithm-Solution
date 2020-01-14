#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
	int n, m;
	long long ans = 0;
	cin >> n >> m;
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	while (m--) {
		sort(v.begin(),v.end());
		long long sum = v[0] + v[1];
		v[0] = sum;
		v[1] = sum;
	}
	for (int i = 0; i < n; i++)
		ans += v[i];
	cout << ans << endl;
	return 0;
}