#include <iostream>

using namespace std;

int N, M, x, y, K;
int map[21][21];
int dx[] = {1,-1,0,0}; // 동, 서, 남, 북
int dy[] = {0,0,-1,1};
int dice[7] = {0,}; // 1: 윗면 2: 뒷면 3: 오른쪽 옆면 4: 왼쪽 옆면 5: 앞면 6: 아랫면

void north(){
    int temp = dice[2];
    dice[2] = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[6];
    dice[6] = temp;
}

void south(){
    int temp = dice[5];
    dice[5] = dice[1];
    dice[1] = dice[2];
    dice[2] = dice[6];
    dice[6] = temp;
}

void west(){
    int temp = dice[1];
    dice[1] = dice[3];
    dice[3] = dice[6];
    dice[6] = dice[4];
    dice[4] = temp;
}

void east(){
    int temp = dice[6];
    dice[6] = dice[3];
    dice[3] = dice[1];
    dice[1] = dice[4];
    dice[4] = temp;
}

int main(){
    cin >> N >> M >> y >> x >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            cin >> map[j][i];
    }

    int dir;
    while(K--){ // K번의 케이스
        cin >> dir;
        x += dx[dir-1];
        y += dy[dir-1];

        // 이동 한 좌표가 범위 벗어나면 continue;
        if(x < 0 || x >= M || y < 0 || y >= N){
            x -= dx[dir - 1];
            y -= dy[dir - 1];
            continue;
        }

        // 주사위 이동
        switch(dir){
            case 1: east(); break;
            case 2: west(); break;
            case 3: north(); break;
            case 4: south(); break;
        }

        // // 1. 맵 0이면 -> 주사위 바닥면(6) 숫자 복사
        if(map[x][y] == 0){
            map[x][y] = dice[6];
        }
        // 2. 0 아니면 -> 맵 숫자가 바닥면(6)으로 복사 -> 맵 0
        else{
            dice[6] = map[x][y];
            map[x][y] = 0;
        }

        // 출력은 윗면(1)
        cout << dice[1] << endl;
    }
    return 0;
}