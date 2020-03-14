#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue <int> q;
bool check[100001] = { false, };
int visited[100001] = { 0, };

void bfs() {
	q.push(n); 
	check[n] = true;
	while (!q.empty()) {
		int nx = q.front(); 
		q.pop();
		if (nx == k) return;
		if (nx - 1 >= 0 && !check[nx - 1]) {
			q.push(nx - 1);
			visited[nx - 1] = visited[nx] + 1;
			check[nx - 1] = true;
		}
		if (nx + 1 <= 100000 && !check[nx + 1]) {
			q.push(nx + 1);
			visited[nx + 1] = visited[nx] + 1;
			check[nx + 1] = true;
		}
		if (nx * 2 <= 100000 && !check[nx * 2]) {
			q.push(nx * 2);
			visited[nx * 2] = visited[nx] + 1;
			check[nx * 2] = true;
		}

	}
}
int main(void) {
	cin >> n >> k;
	bfs();
	cout << visited[k] << endl;
	return 0;
}