// 50분
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, answer = 0x80000000;
int graph[9][9];
bool check[9][9];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void virus(int x, int y) {
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    check[x][y] = 1;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(graph[nx][ny] == 1 || nx < 0 || nx >= M || ny < 0 || ny >= N || check[nx][ny]) continue;

            if(graph[nx][ny] == 0) graph[nx][ny] = 3;
            check[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }
    }
}

void safeArea(){
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++){
            if(!graph[j][i]) cnt++;
        }
    }
    answer = max(answer, cnt);
}

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            check[j][i] = 0;
        }
    }
}

int main(){
    // 0은 빈 칸, 1은 벽, 2는 바이러스
    int zeroCnt = 0;
    vector<pair<int, int> > zero(N);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> graph[j][i];
            if(!graph[j][i]) {
                zeroCnt++;
                zero.push_back(make_pair(j, i));
            }
        }
    }
    
    // 0 인 것 중에 3개 골라서 벽 세우기 - 조합
    vector<int> temp(zero.size(), true);
    for(int i = 0; i < zero.size() - 3; i++) temp[i]= false;

    do{
        vector<pair<int, int> > wall;
        // 1. 벽 3개 세움
        for(int i = 0; i < zero.size(); i++){
            if(temp[i]) {
                wall.push_back(make_pair(zero[i].first, zero[i].second));
                graph[zero[i].first][zero[i].second] = 1;
            }
        }

        // 2. 바이러스 퍼짐
        init();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (graph[j][i] == 2 && !check[j][i]) virus(j, i);
            }
        }

        // 3. 안전영역 구함
        safeArea();

        // 4. 백트래킹
        // 4-1 벽 허물기
        while(wall.size()){
            graph[wall.back().first][wall.back().second] = 0;
            wall.pop_back();
        }
        // 4-2 바이러스 치료
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (graph[j][i] == 3) graph[j][i] = 0;
            }
        }

    }while(next_permutation(temp.begin(), temp.end()));

    cout << answer << endl;

    return 0;
}