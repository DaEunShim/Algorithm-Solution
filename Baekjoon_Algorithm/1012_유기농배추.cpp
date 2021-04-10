#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int T, M, N, K, cnt = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool graph[51][51];
bool check[51][51];

void reset(){
    for(int i = 0; i < 51; i++){
        for(int j = 0; j < 51; j++){
            graph[i][j] = 0;
            check[i][j] = 0;
        }
    }
}

void bfs(int a, int b){
    queue< pair<int, int> > q;
    q.push(make_pair(a,b));
    check[a][b] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(graph[nx][ny] && nx >=0 && nx < M && ny >=0 && ny < N && !check[nx][ny]){ 
                q.push(make_pair(nx, ny));
                check[nx][ny] = 1;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int a, b;
    cin >> T;
    while(T--){
        cin >> M >> N >> K;
        for(int i = 0; i < K; i++){
            cin >> a >> b;
            graph[a][b] = 1;
        }
        cnt = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(!check[i][j] && graph[i][j]){
                    bfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
        reset();
    }
    return 0;
}

