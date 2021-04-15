// 3:40 ~
#include <iostream>
#include <vector>

using namespace std;

int arr[9][9];
vector< pair<int,int> > v;

void print(){
    // 출력
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << arr[j][i] << " ";
        cout << endl;
    }
    exit(0);
}

bool isCorrect(int x, int y, int num) {
    // 행
    for (int i = 0; i < 9; i++) {
        if(i == x) continue;
        if(arr[i][y] == num) return false;
    }
    
    // 열
    for (int i = 0; i < 9; i++) {
        if (i == y) continue;
        if(arr[x][i] == num) return false;
    }

    // 네모
    int bx = x / 3;
    int by = y / 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j == x && i == y) continue;
            if (arr[bx * 3 + j][by * 3 + i] == num) return false;
        }
    }
    
    return true;
}

void DFS(int idx){
    if (idx == v.size()) print();
    int x = v[idx].first;
    int y = v[idx].second;

    // 적합?
    for(int i = 1; i <= 9; i++){
        if(isCorrect(x, y, i)){ // 적합하면
            arr[x][y] = i;
            DFS(idx+1); // 다음 depth
            arr[x][y] = 0; // 백트래킹
        }
    }
    return;
}

int main() {
    // 입략
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            scanf("%1d", &arr[j][i]);
            if (!arr[j][i]) v.push_back(make_pair(j, i));
        }
    }

    // 풀이
    DFS(0);

    return 0;
}