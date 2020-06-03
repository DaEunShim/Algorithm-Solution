#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[32001];
vector<int> degree(32001);
priority_queue<int, vector<int>,greater<int>> pq;
vector<int> result;
int main(void) {
	int n, m;
	cin >> n >> m;
	while (m--) {
		int first, second;
		cin >> first >> second;
		graph[first].push_back(second);
		degree[second]++;
	}
	for (int i = 1; i <= n; i++)
		if(!degree[i]) pq.push(i);

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		result.push_back(cur);
		for (int i = 0; i < graph[cur].size(); i++) {
			degree[graph[cur][i]]--;
			if (!degree[graph[cur][i]]) pq.push(graph[cur][i]);
		}
	}

	for (int i = 0; i < n; i++)
		cout << result[i] << " ";
	cout << endl;
}