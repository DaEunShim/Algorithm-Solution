#include<iostream>
#include<vector>

using namespace std;
vector<int>a[1001];
bool ck[1001];

void dfs(int node) {
	ck[node] = true;
	for (int i = 0; i<a[node].size(); i++) {
		int next = a[node][i];
		if (ck[next] == false) {
			dfs(next);
		}
	}
}
int main(void) {
	int n, m, c=0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (ck[i] == false) {
			dfs(i);
			c++;
		}
	}
	cout << c;
	return 0;
}