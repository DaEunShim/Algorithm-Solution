#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

int N, Q, L;
int graph[100][100];
int visited[100][100];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void print(){
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << graph[j][i] <<" ";
        }
        cout << endl;
    }
    cout << endl;
}


void copyArray(int temp[][100], int graph[][100]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            graph[j][i] = temp[j][i];
        }
    }
}

void melting(){
    bool check[100][100];
    memset(check, false, sizeof(check));
    // 주변 얼음 칸 3개 이상아니면 - 1
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 자기 얼음 0이면 패쓰
            if(!graph[j][i]) continue;
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int nx = j + dx[k];
                int ny = i + dy[k];

                if (!graph[nx][ny] || nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                cnt++;
            }
            if(cnt < 3){
                // 얼음 녹이자고 체크
                check[j][i] = 1;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (check[j][i] && graph[j][i]) {
                graph[j][i]--;
            }
        }
    }
}

void fireStorm(){
    // 부분 격자 나눔 
    int M = pow(2, L);
    int temp[100][100];
    memset(temp, 0, sizeof(temp));

    for (int i = 0; i < N / M; i++) {
        for (int j = 0; j < N / M; j++) {

            // 부분 격자 한 개
            for (int p = 0; p < M; p++) {
                for (int q = 0; q < M; q++) {
                    // 시계 방향으로 90도 회전
                    temp[M * j + (M - 1 -p)][M * i + q] = graph[M*j + q][M*i+p];
                }
            }
        }
    }
    // temp -> graph
    copyArray(temp, graph);

    //print();
    // 얼음이 있는 칸 3개 이상과 인접하지 않은 얼음 칸은 1 줄어듬
    melting();
    //print();
}

int totalIce(){
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum +=graph[j][i];
        }
    }
    return sum;
}

int bfs(int x, int y){
    int cnt = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (!graph[nx][ny] || nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) continue;

            visited[nx][ny] = 1;
            q.push(make_pair(nx, ny));
            cnt++;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> Q;
    N = pow(2, N);
    for(int i = 0; i< N; i++){
        for (int j = 0; j < N; j++) {
            cin >> graph[j][i];
        }
    }

    // 파이어스톰 Q번 실행
    while(Q--){
        cin >> L;
        fireStorm();
    }

    // 남아 있는 얼음의 합
    cout << totalIce() << endl;

    int maxCnt = 0;
    // 가장 큰 덩어리가 차지하는 칸의 개수
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(graph[j][i] && !visited[j][i]) {
                maxCnt = max(maxCnt, bfs(j, i));
            }
        }
    }
    cout << maxCnt << endl;

    return 0;
}