#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, a, b;
vector<pair<int, int>> arr[1001];

int dijkstra() {
	vector<int> dp(n+1,0x7FFFFFFF);
	dp[a] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,a }); // 비용, 시작점

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int vertex = pq.top().second;
		pq.pop();
		
		if (dp[vertex] < cost) continue;

		for (int i = 0; i < arr[vertex].size(); i++) {
			int nCost = cost + arr[vertex][i].second;
			int nVertex = arr[vertex][i].first;
			if(dp[nVertex] < nCost) continue;
			// 최소거리 갱신
			dp[nVertex] = nCost;
			pq.push({-nCost,nVertex});
		}
	}
	return dp[b];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, w;
			cin >> x >> y >> w;
			arr[x].push_back({y,w});
	}
	cin >> a >> b;
	cout << dijkstra() << endl;
	return 0;
}