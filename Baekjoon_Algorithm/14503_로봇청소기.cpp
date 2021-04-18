#include <iostream>

using namespace std;

int N, M, cnt = 0;
int graph[51][51];
bool check[51][51];
int dx[] = {0, 1, 0, -1};  // 0:북 1:동 2:남 3:서
int dy[] = {-1, 0, 1, 0};

void dfs(int x, int y, int dir){
    // 1번 - 청소
    if(!graph[x][y]){
        cnt++;
        graph[x][y] = 2;
    }
    check[x][y] = 1;

    // 2번
    // a번
    if(dir == 0) dir = 4;
    int nx = x + dx[dir - 1];
    int ny = y + dy[dir - 1];
    if(!graph[nx][ny] && !check[nx][ny]){ // 왼쪽 방향 청소 안했을 때
        dfs(nx, ny, dir - 1);
    } 
    // 네 방향 체크

    bool flag = false;
    for(int i = 0; i < 4; i++){
        int nx2 = x + dx[i];
        int ny2 = y + dy[i];
        if(!graph[nx2][ny2] && !check[nx2][ny2]) { // 네 방향 중 갈 수 있다면
            flag = true;
            break;
        }
    }

    if(!flag){
        // c번
        switch(dir){
            case 1:
                // 동
                if (graph[x - 1][y] != 1) dfs(x - 1, y, 1);
                else {cout << cnt << endl; exit(0);} //d번
                break;  
            case 2:
                // 남
                if (graph[x][y - 1] != 1) dfs(x, y - 1, 2);
                else {cout << cnt << endl; exit(0);} //d번
                break;
            case 3:
                // 서
                if (graph[x + 1][y] != 1) dfs(x + 1, y, 3);
                else {cout << cnt << endl; exit(0);} //d번
                break;
            case 4:
                // 북
                if (graph[x][y + 1] != 1) dfs(x, y + 1, 0);
                else {cout << cnt << endl; exit(0);} //d번
                break;
        }
    }
    // b번
    else {
        dfs(x, y, dir - 1);
    }
}

int main(){
    cin >> N >> M;
    int r,c,d;
    cin >> r >> c >> d; 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            cin >> graph[j][i];
    }

    dfs(c, r, d);

    return 0;
}