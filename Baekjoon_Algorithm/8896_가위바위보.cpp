#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int main() {
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		vector<string> v;

		bool robot[11];
		memset(robot, true, sizeof(robot));
		string str;
		int cnt, winner = 0;
		for (int i = 0; i < n; i++) {
			cin >> str;
			v.push_back(str);
		}
		for (int i = 0; i < v[0].length(); i++) {
			bool rsp[3] = { false, };
			vector<int> r, s, p;
			for (int j = 0; j < n; j++) {
				if (rsp[0] && rsp[1] && rsp[2])
					break;
				if (!robot[j])
					continue;
				if (v[j][i] == 'R') {
					rsp[0] = true;
					r.push_back(j);
				}
				else if (v[j][i] == 'S') {
					rsp[1] = true;
					s.push_back(j);
				}
				else {
					rsp[2] = true;
					p.push_back(j);
				}
			}
			if (rsp[0] && rsp[1] && rsp[2])
				continue;
			int lose = 0;
			if (rsp[0] && rsp[1]) {
				lose = 1;
			}
			else if (rsp[1] && rsp[2]) {
				lose = 2;
			}
			else if (rsp[0] && rsp[2]) {
				lose = 0;
			}
			else continue;

			switch (lose) {
			case 0:
				for (int j = 0; j < r.size(); j++) {
					robot[r[j]] = false;
				}
				break;
			case 1:
				for (int j = 0; j < s.size(); j++) {
					robot[s[j]] = false;
				}
				break;
			case 2:
				for (int j = 0; j < p.size(); j++) {
					robot[p[j]] = false;
				}
				break;
			}
			cnt = 0;
			for (int j = 0; j < n; j++) {
				if (robot[j]) {
					cnt++;
					winner = j + 1;
				}
			}
			if (cnt <= 1) {
				break;
			}
		}
		//출력
		if (cnt > 1) {
			cout << 0 << endl;
		}
		else {
			cout << winner << endl;
		}
	}

	return 0;
}