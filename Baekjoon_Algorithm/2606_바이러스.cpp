#include <iostream>

using namespace std;

int pc[101][101] = { 0 };
int visit[101] = { 0 };
int cnt = 0, n;

void dfs(int x) {
	if (visit[x]) return;
	visit[x]= 1;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]&&pc[x][i]) {
			cnt++;
			dfs(i);
		}
	}
	return;
}

int main() {
	int edge;
	cin >> n >> edge;
	for (int i = 0; i < edge; i++) {
		int a, b;
		cin >> a >> b;
		pc[a][b] = 1;
		pc[b][a] = 1;
	}
	dfs(1);
	cout << cnt << endl;
	return 0;
}