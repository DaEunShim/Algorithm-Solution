#include <algorithm>
#include <iostream>

using namespace std;

int N, M, answer = 0x80000000;
int paper[501][501];
bool check[501][501];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, int cnt, int sum) {
    // 종료조건
    if (cnt == 4) {
        answer = max(answer, sum);
        return;
    }
    check[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= M || ny >= N || check[nx][ny]) continue;

        check[nx][ny] = 1;
        dfs(nx, ny, cnt + 1, sum + paper[nx][ny]);
        check[nx][ny] = 0;
    }
}

void shape(int x, int y) {
    int sh1 = 0, sh2 = 0, sh3 = 0, sh4 = 0;
    // ㅗ
    if (x + 2 < M && y - 1 >= 0) {
        sh1 = paper[x][y] + paper[x + 1][y] + paper[x + 2][y] + paper[x + 1][y - 1];
    }
    // ㅜ
    if (x + 2 < M && y + 1 < N) {
        sh2 = paper[x][y] + paper[x + 1][y] + paper[x + 2][y] + paper[x + 1][y + 1];
    }
    // ㅏ
    if (x + 1 < M && y + 2 < N) {
        sh3 = paper[x][y] + paper[x][y + 1] + paper[x][y + 2] + paper[x + 1][y + 1];
    }
    // ㅓ
    if (x - 1 >= 0 && y + 2 < N) {
        sh4 = paper[x][y] + paper[x][y + 1] + paper[x][y + 2] + paper[x - 1][y + 1];
    }

    answer = max(answer, max(max(sh1, sh2), max(sh3, sh4)));
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> paper[j][i];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            check[j][i] = 1;
            dfs(j, i, 1, paper[j][i]);
            check[j][i] = 0;

            // ㅗ, ㅜ, ㅏ, ㅓ 모양 처리
            shape(j, i);
        }
    }

    cout << answer << endl;

    return 0;
}
