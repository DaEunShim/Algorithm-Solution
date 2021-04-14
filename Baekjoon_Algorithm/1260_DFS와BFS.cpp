#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
bool check[1001];

void init(){
    for(int i = 0; i <= 1001; i++)
        check[i] = 0;
}

void dfs(int start){
    if(check[start]) return;
    check[start] = 1;
    cout << start << " ";

    for(int i = 0; i < graph[start].size(); i++){
        dfs(graph[start][i]);
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    check[start] = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout << x << " ";
        for(int i = 0; i < graph[x].size(); i++){
            int nx = graph[x][i];
            if (!check[nx])
            {
                check[nx] = 1;
                q.push(nx);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, V, x, y;
    cin >> N >> M >> V;
    for(int i = 0; i < M; i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());

    init();
    dfs(V);
    cout << endl;

    init();
    bfs(V);
    cout << endl;
    return 0;
}