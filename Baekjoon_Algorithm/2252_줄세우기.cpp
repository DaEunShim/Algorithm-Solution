#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> arr[32010];
int degree[32010];
int result[32010] = { 0, };

int main(void) {
	int n, m;
	cin >> n >> m;
	queue<int> pq;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		degree[b]++;
	}
	for (int i = 1; i <= n; i++)
		if (degree[i] == 0) pq.push(i);
	for (int i = 1; i <= n; i++) {
		int x = pq.front();
		result[i] = x;
		pq.pop();
		for (int j = 0; j < arr[x].size(); j++) {
			int y = arr[x][j];
			if (--degree[y] == 0)
				pq.push(y);
		}
	}
	for (int i = 1; i <= n; i++) 
		cout << result[i] << " ";
	return 0;
}