#include <iostream>
#include <cmath>

using namespace std;

int N, L, answer = 0;
int graph[101][101];

void solve(){
    bool check1[101][101] = {0,};
    // 행
    for(int i = 0; i < N; i++){
        bool flag = true;
        for (int j = 0; j < N - 1; j++){
            // 같을 때
            if(graph[j][i] == graph[j+1][i]) continue;
            // 1칸 차이날 때 (경사로 가능) - 왼쪽이 더 높음
            else if (graph[j][i] - graph[j + 1][i] == 1){
                if (check1[j + 1][i]) {
                    flag = false;
                    break;
                }
                check1[j+1][i] = 1;
                // 연속된 같은 높이의 L개의 칸....
                for (int k = 0; k < L - 1; k++) {
                    // 경사로 못 놓음(범위 벗어남, 이미 놓음, 높이 안맞음)
                    if (j + k + 2 >= N || check1[j + k + 2][i] || graph[j + k + 1][i] != graph[j + k + 2][i]) {
                        flag = false;
                        break;
                    };
                    check1[j + k + 2][i] = 1;
                }
                if (!flag) break;
            }
            // 1칸 차이날 때 (경사로 가능) - 오른쪽이 더 높음
            else if (graph[j + 1][i] - graph[j][i] == 1) {
                if (check1[j][i]) {
                    flag = false;
                    break;
                }
                check1[j][i] = 1;
                // 연속된 같은 높이의 L개의 칸....
                for (int k = 0; k < L - 1; k++) {
                    // 경사로 못 놓음(범위 벗어남, 이미 놓음, 높이 안맞음)
                    if (j - k - 1 < 0 || check1[j - k - 1][i] || graph[j - k][i] != graph[j - k - 1][i]) {
                        flag = false;
                        break;
                    };
                    check1[j - k - 1][i] = 1;
                }
                if (!flag) break;
            }
            // 2칸 이상 차이날 때 - 지나갈 수 없는 길
            else {
                flag = false;
                break;
            }
        }
        if(flag) answer++; 
    }

    bool check2[101][101] = {0,};
    // 열
    for (int i = 0; i < N; i++) {
        bool flag = true;
        for (int j = 0; j < N - 1; j++) {
            // 같을 때
            if (graph[i][j] == graph[i][j + 1]) continue;
            // 1칸 차이날 때 (경사로 가능) - 윗쪽이 더 높음
            else if (graph[i][j] - graph[i][j+1] == 1) {
                if (check2[i][j + 1]) {
                    flag = false;
                    break;
                }
                check2[i][j + 1] = 1;
                // 연속된 같은 높이의 L개의 칸....
                for (int k = 0; k < L - 1; k++) {
                    // 경사로 못 놓음(범위 벗어남, 이미 놓음, 높이 안맞음)
                    if (j + k + 2 >= N || check2[i][j + k + 2] || graph[i][j + k + 1] != graph[i][j + k + 2]) {
                        flag = false;
                        break;
                    };
                    check2[i][j + k + 2] = 1;
                }
                if (!flag) break;
            }
            // 1칸 차이날 때 (경사로 가능) - 아래쪽이 더 높음
            else if (graph[i][j + 1] - graph[i][j] == 1) {
                if (check2[i][j]) {
                    flag = false;
                    break;
                }
                check2[i][j] = 1;
                // 연속된 같은 높이의 L개의 칸....
                for (int k = 0; k < L - 1; k++) {
                    // 경사로 못 놓음(범위 벗어남, 이미 놓음, 높이 안맞음)
                    if (j - k - 1 < 0 || check2[i][j - k - 1] || graph[i][j - k] != graph[i][j - k - 1]) {
                        flag = false;
                        break;
                    };
                    check2[i][j - k - 1] = 1;
                }
                if (!flag) break;
            }
            // 2칸 이상 차이날 때 - 지나갈 수 없는 길
            else {
                flag = false;
                break;
            }
        }
        if (flag) answer++;
    }
}

int main(){
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cin >> graph[j][i];
    }

    solve();

    cout << answer << endl;
    return 0;
}