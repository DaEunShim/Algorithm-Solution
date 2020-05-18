#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, ans = 987654321, cnt = 0;
int arr[101][101];
bool visit[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int islandNum = 2;
void number(int a, int b, int num) {
    queue<pair<int, int>> q;
    q.push({a,b});
    arr[a][b] = num;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (!visit[nx][ny] && arr[nx][ny]) {
                arr[nx][ny] = num;
                visit[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
    
}
void bfs(int num) {
    queue < pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j]==num) { // 섬이면
                visit[i][j] = 1;
                q.push({ i,j });
            }
        }
    }
    
   cnt=0;
    while (!q.empty()) {
        int size = q.size();
        for (int k = 0; k < size; k++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
            
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(visit[nx][ny])continue;
                if (arr[nx][ny] != num && arr[nx][ny]) { // 다른 섬 도착
                    return;
                }
                else if (arr[nx][ny] == 0) { //방문 안 한 바다
                    visit[nx][ny] = 1;
                    q.push({ nx,ny });
                }
            }
        }
        cnt++;
    }
}
int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j]==1) {
               number(i, j, islandNum);
               islandNum++;
         }
        }
    }
   
    for (int i = 2; i < islandNum; i++) {
        memset(visit, 0, sizeof(visit));
        bfs(i);
        ans = min(ans,cnt);
        cnt = 0;
    }
    cout << ans << endl;
    return 0;
}