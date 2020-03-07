#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int miro[101][101];
int depth[101][101];
bool check[101][101] = {false};
int n, m;
int xx[4] = { 0,-1,0,1 };
int yy[4] = { 1,0,-1,0 };
queue <int> qx;
queue <int> qy;

void bfs(int x, int y) {
	if (x <= 0 || y <= 0) return;
	int temp_x, temp_y;
	check[x][y] = true;
	qx.push(x);
	qy.push(y);
	while (!qx.empty()&& !qy.empty()) {
		temp_x = qx.front();
		temp_y = qy.front();
		qx.pop(); qy.pop();
		for (int i = 0; i < 4; i++) {
			int nx = temp_x + xx[i];
			int ny = temp_y + yy[i];
			if (miro[nx][ny] && nx <= n && ny <= m && !check[nx][ny]) {
				check[nx][ny] = true;
				qx.push(nx);
				qy.push(ny);
				depth[nx][ny] = depth[temp_x][temp_y] + 1;
			}
		}
	}
}
int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf_s("%1d", &miro[i][j]);
		}
	}
	depth[1][1] = 1;
	bfs(1, 1);
	cout << depth[n][m] << endl;
	return 0;
}