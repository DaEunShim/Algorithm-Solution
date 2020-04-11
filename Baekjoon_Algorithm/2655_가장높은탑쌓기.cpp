#include <iostream>
#include <algorithm>

using namespace std;

struct block {
	int s;
	int h;
	int w;
	int num;
};
bool cmp(const block &b1, const block &b2) {
	if (b1.s < b2.s) return true;
	else return false;
}

block blocks[101];
int dp[101];
int path[101] = { 0 };

int main() {
	int n, _max=0, last_index = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> blocks[i].s >> blocks[i].h >> blocks[i].w;
		blocks[i].num = i;
	}
	sort(blocks + 1, blocks + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		dp[i] = 0 ;
		for (int j = i-1; j >= 0; j--) {
			if (blocks[i].w > blocks[j].w && dp[i] <= dp[j]) {
				dp[i] = dp[j];
				path[i] = j;
			}
		}
		dp[i] += blocks[i].h;
		if (dp[i] > _max) {
			last_index = i;
			_max = dp[i];
		}
	}
	int cnt = 1;
	int printArr[101] = { 0 };
	while (1) {
		if (path[last_index] == 0) {
			printArr[cnt - 1] = blocks[last_index].num;
			break;
		}
		else {
			printArr[cnt - 1] = blocks[last_index].num;
			last_index = path[last_index];
			cnt++;
		}
	}
	cout << cnt << endl;
	for (int i = cnt-1; i >= 0; i--)
		cout << printArr[i] << endl;
	return 0;
}