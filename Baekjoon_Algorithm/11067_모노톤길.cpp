#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//x비교 -> 같으면 현재 y랑 가까운 y
vector<pair<int, int>> v;

bool sorting(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first != p2.first)
		return p1.first < p2.first;
	else
		return p1.second < p2.second;
}
int main() {
	int T, n, x, y, count;
	bool rev = false, flag = false;
	cin >> T;
	while (T--) {
		cin >> n;
		while (n--) {   //입력
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}
		count = 0;
		int prev = 0;
		sort(v.begin(), v.end(), sorting);
		for (int i = 0; i < v.size(); i++) {
			if (i < v.size() - 1 && v[i].first == v[i + 1].first) {
				if (!flag) {
					flag = true;
					if (i == 0) prev = 0;
					else prev = v[i - 1].second;
					if (abs(prev - v[i].second) >= abs(prev - v[i + 1].second))
						rev = true;
				}
				count++;
			}
			else {
				if (flag) {
					if (rev)
						reverse(v.begin() + i - count, v.begin() + i + 1);
					count = 0;
					flag = false;
					rev = false;
				}
			}
		}
		int m, num;
		cin >> m;
		while (m--) {
			cin >> num;
			cout << v[num - 1].first << " " << v[num - 1].second << endl;
		}
		v.clear();
	}

	return 0;
}