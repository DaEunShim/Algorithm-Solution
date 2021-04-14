#include <iostream>
#include <vector>

using namespace std;

int W, H, cnt;
bool graph[51][51];
bool check[51][51];
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1 };

void init(){
    cnt = 0;
    for(int i =0; i < 51; i++){
        for(int j = 0; j < 51; j++){
            graph[i][j] = 0;
            check[i][j] = 0;
        }
    }
}

void dfs(int x, int y){
    if(check[x][y]) return;
    check[x][y] = 1;

    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!graph[nx][ny] || nx < 0 || nx >= W || ny < 0 || ny >= H || check[nx][ny]) continue;
        dfs(nx, ny);
        check[nx][ny] = 1;
    }
}

int main(){
    while(1){
        init();
        cin >> W >> H;
        if(W == 0 && H == 0) return 0; // 종료 조건
        
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                // 1:땅, 0:바다
                cin >> graph[j][i]; 
            }
        }

        for (int i = 0; i < H; i++){
            for (int j = 0; j < W; j++){
                if(graph[j][i] && !check[j][i]) {
                    dfs(j,i);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}