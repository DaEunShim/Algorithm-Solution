#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K, L, second = 0;
int graph[101][101];
int snake[101][101];
int dx[] = {1, 0, -1, 0}; // 동, 북, 서, 남
int dy[] = {0, -1, 0, 1};
queue<pair<int, char> > dir;
int dirIdx = 0;

void solve(int x, int y, int direction) {
    // 방향 바꿔야 됨
    if (!dir.empty() && dir.front().first == second) {
        int c = dir.front().second;
        dir.pop();
        if (c == 'L') {
            // L -> dir + 1
            if(direction == 3) direction = 0;
            else direction++;
        } else {
            // R -> dir - 1
            if(direction == 0) direction = 3;
            else direction--;
        }
    }

    second++;
    // 다음 위치
    int nx = x + dx[direction];
    int ny = y + dy[direction];

    // 종료 - 범위 밖, 자기 몸
    if (snake[nx][ny] || nx < 1 || nx > N || ny < 1 || ny > N) {
        cout << second << endl;
        exit(0);
    }

    // 머리 이동
    snake[nx][ny] = second + 1;

    // 사과 있음
    if(graph[nx][ny]){
        graph[nx][ny] = 0;
    }
    // 사과 없음
    else{
        // 꼬리 칸 비워줌 - 0제외하고 숫자 제일 적은 칸이 꼬리 칸
        int minValue = second + 1, tail_x, tail_y;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <=N; j++){
                if(snake[j][i] && snake[j][i] < minValue){
                    minValue = snake[j][i];
                    tail_x = j;
                    tail_y = i;
                }
            }
        }
        snake[tail_x][tail_y] = 0;
    }

    solve(nx, ny, direction);
}

int main(){
    cin >> N >> K;
    int a,b;
    for(int i = 0; i < K; i++){
        cin >> a >> b;
        graph[b][a] = 1;
    }

    cin >> L;
    int x; char c;
    for(int i = 0; i < L; i++){
        cin >> x >> c;
        dir.push(make_pair(x,c));
    }

    snake[1][1] = 1;
    solve(1, 1, 0);

    return 0;
}