#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 50
using namespace std;

int n;
int arr[MAX][MAX];
int visit[MAX][MAX];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			visit[i][j] = 0x7FFFFFFF;
	}
	queue<pair<int, int>> q;
	q.push({ 0,0});
	visit[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			if (arr[nx][ny]){ // 흰 방
				if (visit[nx][ny] > visit[x][y]){
					visit[nx][ny] = visit[x][y];
					q.push(make_pair(nx, ny));
				}
			}
			else {// 검은 방
				if (visit[nx][ny] > visit[x][y] + 1) {
					visit[nx][ny] = visit[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string  s;
		cin >> s;
		for (int j = 0; j < n; j++)
			arr[i][j] = s[j]-'0';
	}

	bfs();
	cout << visit[n - 1][n - 1] << endl;

	return 0;
}