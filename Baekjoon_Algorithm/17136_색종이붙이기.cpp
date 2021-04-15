#include <iostream>
#include <algorithm>

using namespace std;

int result = 26;
bool graph[10][10];
int paper[6];

void put(int x, int y, int k) {  // 종이 붙임
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            graph[x + j][y + i] = 0;
        }
    }
    paper[k]++;
}

void clean(int x, int y, int k) {  // 종이 다시 뗌
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            graph[x + j][y + i] = 1;
        }
    }
    paper[k]--;
}

bool promising(int x, int y, int k){ // k * k 색중이 붙일 수 있는지
    if(x + k > 10 || y + k > 10 || paper[k] >= 5) return false;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            if(!graph[x+j][y+i]) return false;
            // if (graph[x + j][y + i] < k) 
        }
    }
    return true;
}

int zeroAll() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if(graph[j][i]) return false;
        }
    }
    return true;
}

int count(){
    int cnt= 0;
    for (int i = 1; i <= 5; i++) {
        cnt += paper[i];
    }
    return cnt;
}

void DFS(int x, int y){ //0,0 시작해서 하나하나 다함.
    if(count() > result) return;
    if(zeroAll()){
        result = min(result, count());
        return;
    }
    for (int i = y; i < 10; i++) {
        for (int j = x; j < 10; j++) {
            if (!graph[j][i]) continue; // 못붙이면 패스
            for(int k = 5; k > 0; k--){
                if (promising(j, i, k)) {
                    put(j, i, k);
                    DFS(j+k, i);
                    clean(j, i, k);
                }
            }
            return;
        }
        x = 0;
    }
    return;
}

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> graph[j][i];
        }
    }
    DFS(0, 0);

    if(result == 26) cout << -1 << endl;
    else cout << result << endl;
    return 0;
}