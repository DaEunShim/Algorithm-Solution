#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct INFO{
    int num;
    int dir; // 1~ 8
};
INFO info;
INFO graph[5][5];
int fish[17]; // i번 물고기의 위치
int answer = 0x80000000;
int dx[] = {0, 0,  -1, -1, -1, 0, 1, 1, 1};
int dy[] = {0, -1, -1,  0,  1, 1, 1, 0, -1};

INFO makeInfo(int num, int dir) {
    info.num = num;
    info.dir = dir;
    return info;
}

void move(int x, int y, int num, int dir, int cnt){
    if(cnt == 8) return;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    // 이동하려는 칸에 상어가 있거나, 공간 넘으면 안 됨
    if(nx >= 1 && nx <= 4 && ny >= 1 && ny <= 4 && graph[nx][ny].num != 17){
        // 자리 바꾸기
        int nNum = graph[nx][ny].num;
        int nDir = graph[nx][ny].dir;

        fish[num] = (ny - 1) * 4 + nx;
        fish[nNum] = (y - 1) * 4 + x;
        graph[x][y] = makeInfo(nNum, nDir);
        graph[nx][ny] = makeInfo(num, dir);
    }
    // 방향 바꾸기
    else {
        if(dir == 8) graph[x][y].dir = 1;
        else graph[x][y].dir++;
        move(x, y, num, graph[x][y].dir, cnt + 1);
    }
    return;
}

void moveFish(){
    // 작은 물고기부터. swap
    for(int i = 1; i<= 16; i++){
        int key = fish[i];
        int x = key % 4 ;
        int y = (key / 4) + 1;
        if (!x) {x = 4; y--;}
        int dir = graph[x][y].dir;
        // 상어한테 잡아먹힌 물고기, 상어는 패쓰
        if(!graph[x][y].num || graph[x][y].num == 17) continue;
        
        move(x, y, i, dir, 0);
    }
}

void copyArray(INFO fromArr[5][5], int fromFish[], INFO toArr[5][5], int toFish[]){
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            toArr[i][j].num = fromArr[i][j].num;
            toArr[i][j].dir = fromArr[i][j].dir;
            toFish[4 * (i - 1) + j] = fromFish[4 * (i-1) + j];
        }
    }
}

void dfs(int x, int y, int sum, int dir){
    //cout << "sum: " << sum << endl;

    // 배열 복사
    INFO tmpGraph[5][5];
    int tmpFish[17];
    copyArray(graph, fish, tmpGraph, tmpFish);

    answer = max(answer, sum);

    graph[x][y].num = 17;

    // 물고기 이동
    moveFish();

    // 상어 이동
    for(int i = 1; i< 4; i++){
        int nx = x + dx[dir] * i;
        int ny = y + dy[dir] * i;

        if (nx >= 1 && nx <= 4 && ny >= 1 && ny <= 4 && graph[nx][ny].num != 0) {
            int temp1 = graph[nx][ny].num;
            int temp2 = graph[nx][ny].dir;
            graph[x][y] = makeInfo(0,0);
            graph[nx][ny] = makeInfo(17, temp2);
            fish[temp1] = 0;

            dfs(nx, ny, sum + temp1, temp2);

            fish[temp1] = (ny - 1) * 4+ nx ;
            graph[nx][ny] = makeInfo(temp1, temp2);
            graph[x][y] = makeInfo(17, dir);
        }
    }
    copyArray(tmpGraph, tmpFish, graph, fish);
}

int main(){
    int num, dir;
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 4; j++){
            cin >> num >> dir;
            graph[j][i] = makeInfo(num, dir);
            fish[num] = (i - 1) * 4 + j;
        }
    }

    fish[graph[1][1].num] = 0;
    dfs(1, 1, graph[1][1].num, graph[1][1].dir);

    cout << answer << endl;

    return 0;
}