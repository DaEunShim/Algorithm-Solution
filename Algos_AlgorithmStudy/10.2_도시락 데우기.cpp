#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

bool compare(const pair<int, int> &v1, const pair<int, int> &v2) {
	return (v1.second > v2.second);
}

int main() {
	int c;
	cin >> c;

	while (c--) {
		int n, heat_t=0, total_t=0, max=0;
		cin >> n;
		vector<pair<int, int>> v(n);
		vector<int> eat(n);
		int temp = 0;

		for (int j = 0; j < n; j++) {
			cin >> v[j].first;
		}
		for (int j = 0; j < n; j++) {
			cin >> v[j].second;
			//eat[j] = v[j].second;
		}

		sort(v.begin(), v.end(), compare);

		for (int i = 0; i < n; i++) {
			heat_t += v[i].first;
			total_t = heat_t + v[i].second;
			if (total_t > max) max = total_t;
		}
		cout << max << endl;				
	}


	return 0;
}