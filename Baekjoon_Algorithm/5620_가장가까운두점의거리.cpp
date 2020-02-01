#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

long long min_d=1000000000;
bool compare (const pair<int, int> &v1, const pair<int, int> &v2) {
	return (v1.first < v2.second);
}
int main() {
	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		cin >> v[i].second;
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 1; i < n; i++) {
		if (min_d > pow(v[0].first-v[i].first,2)+pow(v[0].second-v[i].second,2))
			min_d = pow(v[0].first - v[i].first, 2) + pow(v[0].second - v[i].second, 2);
	}
	for (int i = 1; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[j].first - v[i].first > min_d) break;
			if(min_d > pow(v[j].first - v[i].first, 2) + pow(v[j].second - v[i].second, 2))
			min_d = pow(v[j].first - v[i].first, 2) + pow(v[j].second - v[i].second, 2);
		}
	}
	cout << min_d << endl;
	return 0;
}