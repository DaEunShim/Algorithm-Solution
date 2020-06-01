#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1001];
vector<int> degree(1001);
queue<int> q;
vector<int> result;
int main(void) {
	int n, m;
	cin >> n >> m;
	while (m--) {
		int k, first, second;
		cin >> k >> first;
		for(int i=0;i<k-1;i++){
			cin >> second;
			graph[first].push_back(second);
			degree[second]++;
			first = second;
		}
	}
	for (int i = 1; i <= n; i++)
		if(!degree[i]) q.push(i);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		result.push_back(cur);
		for (int i = 0; i < graph[cur].size(); i++) {
			degree[graph[cur][i]]--;
			if (!degree[graph[cur][i]]) q.push(graph[cur][i]);
		}
	}
	if (result.size() != n) cout << 0 << endl;
	else {
		for (int i = 0; i < n; i++)
			cout << result[i] << endl;
	}
}