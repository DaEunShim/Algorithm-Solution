#include <iostream>

using namespace std;

int N, M, T, cleaner;
int graph[51][51];
int temp[51][51];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};


void print(){
    cout << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << graph[j][i] <<" ";
        }
        cout << endl;
    }
    cout << endl;
}

void initArray(){
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            temp[j][i] = 0;
        }
    }
}

// 확산
void spread(int x, int y){
    // 미세 먼지 없음
    if(!graph[x][y]) return;

    int cnt = 0;
    // 4 방향
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        // 공기 청정기 있거나 칸 없으면 확산 x
        if (graph[nx][ny] == -1 || nx < 1 || nx > M || ny < 1 || ny > N) continue;

        cnt++;
        // 더 해줘야할 미세먼지 양
        temp[nx][ny] += graph[x][y] / 5;
    }
    graph[x][y] = graph[x][y] - (graph[x][y] / 5) * cnt;
}

void cleanAir_up(){
    // 공기청정기 작동 - 한칸씩 이동
    // 위쪽 -> 반시계
    // 1. 오른쪽으로
    int dust = 0, tmp = 0;
    for (int i = 2; i <= M; i++) {
        tmp = graph[i][cleaner - 1];
        graph[i][cleaner - 1] = dust;
        dust = tmp;
    }

    // 2. 위로
    for(int i = cleaner - 2; i >= 1; i--){
        tmp = graph[M][i];
        graph[M][i] = dust;
        dust = tmp;
    }

    // 3. 왼쪽으로
    for (int i = M - 1; i >= 1; i--) {
        tmp = graph[i][1];
        graph[i][1] = dust;
        dust = tmp;
    }

    // 4. 아래로
    for (int i = 2; i < cleaner - 1; i++) {
        tmp = graph[1][i];
        graph[1][i] = dust;
        dust = tmp;
    }
}

void cleanAir_down(){
    // 아래쪽 -> 시계
    // 1. 오른쪽으로
    int dust = 0, tmp = 0;
    for (int i = 2; i <= M; i++) {
        tmp = graph[i][cleaner];
        graph[i][cleaner] = dust;
        dust = tmp;
    }

    // 2. 아래로
    for (int i = cleaner + 1; i <= N; i++) {
        tmp = graph[M][i];
        graph[M][i] = dust;
        dust = tmp;
    }

    // 3. 왼쪽으로
    for (int i = M - 1; i >= 1; i--) {
        tmp = graph[i][N];
        graph[i][N] = dust;
        dust = tmp;
    }

    // 4. 위로
    for (int i = N - 1; i > cleaner; i--) {
        tmp = graph[1][i];
        graph[1][i] = dust;
        dust = tmp;
    }
}

// 남은 미세먼지 양
int answer() {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (graph[j][i] != -1) sum += graph[j][i];
        }
    }
    return sum;
}

int main(){
    cin >> N >> M >> T;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> graph[j][i];
            if(graph[j][i] == -1) cleaner = i;
        }
    }

    while (T--) {
        initArray();
        // 미세먼지 확산
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                spread(j, i);
            }
        }

        //확산된 미세먼지 더해주기
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (graph[j][i] != -1) graph[j][i] += temp[j][i];
            }
        }

        cleanAir_up();
        cleanAir_down();
    }

    cout << answer() << endl;

    return 0;
}