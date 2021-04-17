#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
char board[11][11];
bool check[11][11][11][11];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct VALUE{
    int Rx, Ry, Bx, By;
};
VALUE info;

VALUE makeInfo(int Rx, int Ry, int Bx, int By){
    info.Rx = Rx;
    info.Ry = Ry;
    info.Bx = Bx;
    info.By = By;
    return info;
}

int bfs(int Rx, int Ry, int Bx, int By) {
    int cnt = 0;
    queue<VALUE> q;
    q.push(makeInfo(Rx, Ry, Bx, By));
    check[Rx][Ry][Bx][By] = 1;

    while(!q.empty()){
        int size = q.size();
        while(size--){
        int rx = q.front().Rx;
        int ry = q.front().Ry;
        int bx = q.front().Bx;
        int by = q.front().By;
        q.pop();

        // 구멍 탈출 성공!
        if (board[rx][ry] == 'O' && board[bx][by] != 'O') { 
            return cnt;
        }

        // 갈 수 있는 방향 4가지
        for(int i = 0; i < 4; i++){
            int nRx = rx;
            int nRy = ry;
            int nBx = bx;
            int nBy = by;

            // 빨간 구슬 이동
            while(board[nRx + dx[i]][nRy + dy[i]] != '#' && board[nRx][nRy] != 'O'){
                nRx += dx[i];
                nRy += dy[i];
            }

            // 파란 구슬 이동
            while(board[nBx + dx[i]][nBy + dy[i]] != '#' && board[nBx][nBy] != 'O'){
                nBx += dx[i];
                nBy += dy[i];
            }

            // 겹쳤을 때 
            if(nRx == nBx && nRy == nBy){
                if (board[nRx][nRy] == 'O') continue;

                // 더 많이 움직인 쪽이 한 칸 움직이기
                if (abs(nRx - rx) + abs(nRy - ry) < abs(nBx - bx) + abs(nBy - by)){
                    // 파란공이 움직이기
                    nBx -= dx[i];
                    nBy -= dy[i];
                }
                else{
                    // 빨간공이 움직이기
                    nRx -= dx[i];
                    nRy -= dy[i];
                }
            }

            // 왔었다면 돌아가
            if(check[nRx][nRy][nBx][nBy]) continue;
            
            check[nRx][nRy][nBx][nBy] = 1;
            q.push(makeInfo(nRx, nRy, nBx, nBy));
        }
        }
        if(cnt >= 10) return -1;
        cnt++;
    }
    return -1;
}

int main(){
    int Rx, Ry, Bx, By;
    cin >> N >> M;
    for(int i =0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[j][i];
            if (board[j][i] == 'R'){
                Rx = j; Ry = i;
            } else if (board[j][i] == 'B'){
                Bx = j; By = i;
            }
        }
    }

    cout << bfs(Rx, Ry, Bx, By) << endl;

    return 0;
}