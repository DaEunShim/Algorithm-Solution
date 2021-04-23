// 4:00 ~ 55
#include <iostream>
#include <vector>

using namespace std;

int N, answer = 0;
int graph[501][501];
int dx[] = {-1,0,1,0}; // 왼쪽, 아래, 오른쪽, 위
int dy[] = {0,1,0,-1};
struct INFO{
    int x;
    int y;
    vector<double> percent[4];
};
INFO info;
INFO dir[12];

INFO makeInfo(int x, int y, double left, double down, double up, double right) { 
    info.x = x;
    info.y = y;
    info.percent[0].push_back(left);
    info.percent[1].push_back(down);
    info.percent[2].push_back(right); 
    info.percent[3].push_back(up);
    return info;
}

// 토네이도가 (x1, y1) -> (x2, y2)
void tornado(int x, int y, int direction){ 
    int total = graph[x][y];
    graph[x][y] = 0;

    int sum = 0, ax, ay;

    for(int i = 0; i < 12; i++){
        int nx = x + dir[i].x;
        int ny = y + dir[i].y;

        if (dir[i].percent[direction][i] == 0.55) {
            ax = nx;
            ay = ny;
            continue;
        }
        sum += total * dir[i].percent[direction][i];

        // 범위 밖
        if(nx < 1 || nx > N || ny < 1|| ny > N){
            answer += total * dir[i].percent[direction][i];
        }
        // 범위 안
        else{
            graph[nx][ny] += total * dir[i].percent[direction][i];
        }
    }

    // a
    // 범위 밖
    if (ax < 1 || ax > N || ay < 1 || ay > N) {
        answer += total - sum;
    }
    // 범위 안
    else {
        graph[ax][ay] += total - sum;
    }
    //print();
}

void solve(){

    // 초기 토네이도 위치
    int x = N/2 + 1; 
    int y = N/2 + 1;
    // 1, 1, 2, 2, .... N-1, N-1, N 칸씩 이동.
    int M = 1, cnt = 1;

    // (N-1)/4 +1 번 4방향을 돌음
    for(int i = 0; i < (N - 1)/2; i++){ 
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < M; k++){
                x += dx[j];
                y += dy[j];

                tornado(x, y, j);
            }
            if (cnt == 2) {
                M++;
                cnt = 1;
            } else {
                cnt++;
            }
        }
    }

    // 마지막으로 (N-1,1)에서 (1,1)으로 왼쪽으로 이동함
    for(int i = N; i > 1 ; i--){
        x--;
        tornado(x, y, 0);
    }

}

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> graph[j][i];
        }
    }

    // int x, int y, double left, double down, double up, double right
    dir[0] = makeInfo(-2, 0, 0.05, 0.02, 0.02, 0);
    dir[1] = makeInfo(-1, -1, 0.1, 0.01, 0.1, 0.01);
    dir[2] = makeInfo(-1, 0, 0.55, 0.07, 0.07,0);
    dir[3] = makeInfo(-1, 1, 0.1, 0.1, 0.01, 0.01);
    dir[4] = makeInfo(0, -2, 0.02, 0, 0.05, 0.02);
    dir[5] = makeInfo(0, -1, 0.07, 0, 0.55, 0.07);
    dir[6] = makeInfo(0, 1, 0.07, 0.55, 0, 0.07);
    dir[7] = makeInfo(0, 2, 0.02, 0.05, 0, 0.02);
    dir[8] = makeInfo(1, -1, 0.01, 0.01, 0.1, 0.1);
    dir[9] = makeInfo(1, 0, 0, 0.07, 0.07, 0.55);
    dir[10] = makeInfo(1, 1, 0.01, 0.1, 0.01,0.1);
    dir[11] = makeInfo(2, 0, 0, 0.02, 0.02, 0.05);


    solve();
    cout << answer << endl;
    return 0;
}