#include <iostream>
#include <queue>

using namespace std;
int n, x, y, total = 0, sharksize = 2, eatfish = 0;
int eatx = 21, eaty = 21;
int arr[30][30] = { 0, };
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int visit[30][30] = { 0,};

int bfs(int x, int y) {
		int minLen = 500;
		queue<pair<int,int>> q;
		q.push(make_pair(x,y));	
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++)
				visit[i][j] = 0;
		}
		while (!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();
			int cx = p.first; // 현재 위치
			int cy = p.second;
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 경로 벗어남
				if (visit[nx][ny] || arr[nx][ny] > sharksize) continue; // 지나왔거나, 크기 크면
				 //cout << "cx : " << x << " cy: " << y << " ";
				 // cout << visit[cx][cy] << endl;
				 // cout << "nx : " << nx << " ny: " << ny << " ";
				 visit[nx][ny] = visit[cx][cy] + 1;
				 // cout << visit[nx][ny] << endl;
				
				if (arr[nx][ny] && arr[nx][ny] < sharksize) { // 먹을 수 있음
					if (visit[nx][ny] < minLen) { 
						minLen = visit[nx][ny];
						eatx = nx; eaty = ny;
					}
					else if (visit[nx][ny] == minLen) { // 거리 같을 경우
						if (nx < eatx || (nx == eatx && ny < eaty)) {
							eatx = nx;
							eaty = ny;
						}			
					}
				}
				q.push(make_pair(nx,ny));
			}
		}
		return visit[eatx][eaty];
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) { // 아기상어 위치
				x = i;
				y = j;
				arr[i][j] = 0;
			}
		}
	}

	while (1) {
		int time = bfs(x, y);
		if(time){
			eatfish++;
			total += time;
			arr[eatx][eaty] = 0;
			if (eatfish == sharksize) {
				sharksize++;
				eatfish = 0;
			}
			x = eatx; y = eaty;
			eatx = 21; eaty = 21;
		}
		else break;
	}
	cout << total << endl;
	return 0;
}