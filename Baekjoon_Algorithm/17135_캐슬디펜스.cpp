#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, D, maxCnt = 0, cnt = 0;
bool arr[16][16];
int graph[16][16];
bool check[16][16];
vector< pair<int,int> > kill;
int dx[] = { -1, 0 , 1};
int dy[] = { 0, -1, 0};

void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            graph[j][i] = arr[j][i];
    }
}

void initCheck(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)
            check[j][i] = 0;
    }
}

void move(int n){ 
    for(int i = N-1 ; i >= N- n; i--){
        for(int j = 0; j < M; j++){
            graph[j][i] = graph[j][i - 1];
        }
    }
    for(int i = 0; i < N-n; i++){
        for(int j = 0; j < M; j++)
            graph[j][i] = 0;
    }
}

void bfs(int X, int Y){
    initCheck();
    queue< pair<int,int> > q;
    // 적이 있다!
    if (graph[X][Y-1] > 0)
    {
        if (graph[X][Y - 1] == 1) cnt++;
        graph[X][Y - 1] = 2;
        kill.push_back(make_pair(X,Y-1));
        return;
    }
    q.push(make_pair(X,Y-1));
    check[X][Y-1] = 1;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i = 0; i < 3; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || nx >= M || ny < 0 || ny >= N || check[nx][ny]) continue;
            // 사정거리 안인지 확인
            if(abs(X - nx) + abs(Y - ny) > D) continue;
            // 적이 있다!
            if(graph[nx][ny] > 0) {
                if(graph[nx][ny] == 1) cnt++;
                graph[nx][ny] = 2;
                kill.push_back(make_pair(nx, ny));
                return;
            }
            q.push(make_pair(nx,ny));
            check[nx][ny] = 1;
        }
    }
}


int main(){
    cin >> N >> M >> D;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[j][i];
        }
    }


    int a, b, c;
    // 궁수 위치 M중에 a,b,c 선정 후 반복
    vector<int> v(M);
    for (int i = 0; i < M; i++) v[i] = i;
    vector<bool> temp(M, true);
    for(int i = 0; i < M -3; i++) temp[i] = false;
    
    do{
        for(int i = 0, k = 0; i < M; i++){
            if(temp[i]) {
                switch(k){
                    case 0: a = v[i]; break;
                    case 1: b = v[i]; break;
                    case 2: c = v[i]; break;
                }
                k++;
            }
        }

        init();
        cnt = 0;
        for (int i = N - 1; i >= 0; i--)
        {
            bfs(a, N);
            bfs(b, N);
            bfs(c, N);

            // 죽음 한 번에 처리 0: 죽음 1: 살았음 2: 방금 죽음
            for(int j = 0; j < kill.size(); j++)
                graph[kill[j].first][kill[j].second] = 0;

            kill.clear();
            move(i);
        }
        
        maxCnt = max(maxCnt, cnt);

    }while(next_permutation(temp.begin(), temp.end()));

    cout << maxCnt << endl;
    return 0;
}