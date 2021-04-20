#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, answer = 0x7fffffff;
int graph[9][9]; //0: 빈칸, 2-5: cctv, 6:벽
int temp[9][9];

struct INFO{
    int x;
    int y;
    int num;
    int dir;
};

INFO info;
vector<INFO> cctv;

INFO makeInfo(int x, int y, int num, int dir) {
    info.x = x;
    info.y = y;
    info.num = num;
    info.dir = dir;
    return info;
}

void left(int x, int y){
    // <-
    for (int i = x - 1; i >= 0; i--) {
        // 감시
        if (temp[i][y] == 0) {
            temp[i][y] = -1;
        }
        // 벽
        else if (temp[i][y] == 6)
            break;
    }
}

void right(int x, int y) {
    // ->
    for (int i = x + 1; i < M; i++) {
        // 감시
        if (temp[i][y] == 0) {
            temp[i][y] = -1;
        }
        // 벽
        else if (temp[i][y] == 6)
            break;
    }
}

void up(int x, int y) {
    // ^
    for (int i = y - 1; i >= 0; i--) {
        // 감시
        if (temp[x][i] == 0) {
            temp[x][i] = -1;
        }
        // 벽
        else if (temp[x][i] == 6)
            break;
    }
}

void down(int x, int y) {
    // v
    for (int i = y + 1; i < N; i++) {
        // 감시
        if (temp[x][i] == 0) {
            temp[x][i] = -1;
        }
        // 벽
        else if (temp[x][i] == 6)
            break;
    }
}

void cctv1(int x, int y, int dir){
    // 1: <-, 2: ->, 3: ^, 4: v
    switch(dir){
        case 1: left(x, y);break;
        case 2: right(x, y); break;
        case 3: up(x, y); break;
        case 4: down(x, y); break;
    }
}

void cctv2(int x, int y, int dir) {
    // 1: <-->, 2: ^v
    switch (dir) {
        case 1:
            left(x, y);
            right(x, y);
            break;
        case 2:
            up(x, y);
            down(x, y);
            break;
    }
}

void cctv3(int x, int y, int dir){
    // 1: <-^, 2: ^->, 3: <-v, 4: v->
    switch (dir) {
        case 1:
            left(x, y);
            up(x, y);
            break;
        case 2:
            right(x, y);
            up(x, y);
            break;
        case 3:
            left(x, y);
            down(x, y);
            break;
        case 4:
            right(x, y);
            down(x, y);
            break;
    }
}

void cctv4(int x, int y, int dir){
    // 1: <-^v, 2: ^v->, 3: <-^->, 4: <-v->
    switch (dir) {
        case 1:
            left(x, y);
            up(x, y);
            down(x, y);
            break;
        case 2:
            right(x, y);
            up(x, y);
            down(x, y);
            break;
        case 3:
            left(x, y);
            right(x, y);
            up(x, y);
            break;
        case 4:
            left(x, y);
            right(x, y);
            down(x, y);
            break;
    }
}

void cctv5(int x, int y){
    // 바로 cctv 달기
    left(x,y);
    right(x,y);
    up(x,y);
    down(x,y);
}

void setCctv(){
    for(int i = 0; i < cctv.size(); i++){
        int x = cctv[i].x;
        int y = cctv[i].y;
        int num = cctv[i].num;
        int dir = cctv[i].dir;

        switch (num){
        case 1:
            cctv1(x, y, dir);
            break;
        case 2:
            cctv2(x, y, dir);
            break;
        case 3:
            cctv3(x, y, dir);
            break;
        case 4:
            cctv4(x, y, dir);
            break;
        case 5:
            cctv5(x, y);
            break;
        }
    }
}

void copyArray(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            temp[j][i] = graph[j][i];
    }
}

int zeroCnt(){
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            if (!temp[j][i]) cnt++;
    }
    return cnt;
}

void dfs(int idx){
    if(idx == cctv.size()){
        // 배열 복사
        copyArray();

        // cctv 감시
        setCctv();

        // zeroCnt 비교 - 최솟값
        answer = min(answer, zeroCnt());
        return;
    }
    int x = cctv[idx].x;
    int y = cctv[idx].y;
    int num  = cctv[idx].num;
    
    for(int i = 1; i <= 4; i++){
        // 2,5 번 cctv는 방향이 각각 2,1 가지
        if(num == 2 && i > 2) continue;
        if(num == 5 && i > 1) continue;

        cctv[idx].dir = i;
        dfs(idx+1);
    }

}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> graph[j][i];
            if(graph[j][i] >=1 && graph[j][i] <= 5) cctv.push_back(makeInfo(j,i,graph[j][i],1));
        }   
    }

    dfs(0);

    cout << answer << endl;

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++)
    //         cout <<graph[j][i] << " ";
    //     cout << endl;
    // }

    return 0;
}