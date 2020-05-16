#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define MAX 20001

using namespace std;

int V, E, K;
vector < pair<int, int>> graph[MAX];
vector <int> dist(MAX,0x7FFFFFFF);

void dp(int x) {
	dist[x] = 0;
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int, int>>> pq;
	pq.push(make_pair(0,x));

	while (!pq.empty()) {
		int vertex = pq.top().second; //pq는 pair에서 first를 우선순위로 둠
		int cost = pq.top().first;
		pq.pop();

		if (dist[vertex] < cost) continue; // 최소거리

		for (int i = 0; i < graph[vertex].size(); i++) {
			int nextVertex = graph[vertex][i].first;
			int nextCost = cost + graph[vertex][i].second;

			if (dist[nextVertex] > nextCost) {
				dist[nextVertex] = nextCost;
				pq.push(make_pair(nextCost, nextVertex));
			}
		}
	}

}
int main() {
	cin >> V >> E >> K;
	int u, v, w;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d",&u,&v,&w);
		graph[u].push_back(make_pair(v, w));
	}
	dp(K);
	for (int i = 1; i <= V; i++) {
		if (dist[i]==0x7FFFFFFF && i != K) printf("INF\n");
		else printf("%d\n",dist[i]);
	}
	return 0;
}