#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
	int n, m, cnt = 0;
	cin >> n >> m;
	deque<int> v(n);
	for (int i = 0; i < n; i++)
		v[i] = i + 1;
	for(int i=0;i<m;i++){
		int pos, location = 0;
		cin >> pos;
		for (; location < v.size();location++) {
			if (v[location] == pos) break;
		}

		cnt += min(location, (int)v.size()-location);

		int dir = 0;
		if (location < (int)v.size() - location) dir = 1;
		while (1) {
			if (v.front() == pos) {
				v.pop_front(); 
				break;
			}
			if (dir) {
				v.push_back(v.front());
				v.pop_front();
			}
			else {
				v.push_front(v.back());
				v.pop_back();
			}
		}
	}
	cout << cnt << endl;
	return 0;
}