#include <iostream>
#include <algorithm>

using namespace std;

int n, cnt = 0;
bool col[15];
bool d1[30];
bool d2[30];

void DFS(int y){
    if(y == n) {
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(!col[i] && !d1[i + y] && !d2[n + i - y]){
            col[i] = d1[i + y] = d2[n + i - y]= 1;
            DFS(y+1);
            col[i] = d1[i + y] = d2[n + i - y] = 0;  // 백트래킹
        }
    }
    return;
}

int main(){
    cin >> n;
    DFS(0);
    cout << cnt << endl;
}