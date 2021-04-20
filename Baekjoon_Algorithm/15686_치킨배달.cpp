#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, M, answer = 0x7fffffff;  // 치킨 집 1 ~ M개 사이
int graph[51][51]; // 0:빈 칸, 1:집 2: 치킨 집
vector<pair<int, int> > store;
vector<pair<int, int> > house;
int perm[14];

void chickenDistance() {
    int sum = 0;
    for(int i = 0; i < house.size(); i++){
        int minValue = 0x7fffffff;
        int hx = house[i].first;
        int hy = house[i].second;
        for (int j = 0; j < M; j++) {
            int cx = store[perm[j]].first;
            int cy = store[perm[j]].second;
            minValue = min(minValue, abs(hx - cx) + abs(hy - cy));
        }
        sum += minValue;
    }
    answer = min(answer, sum);
}

void permutation(int idx, int next){
    if(idx == M) {
        // 치킨 거리 구하기
        chickenDistance();
        return;
    }

    for(int i = next; i < store.size(); i++){
        perm[idx] = i;
        permutation(idx+1, i + 1);
    }
    
}

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> graph[j][i];
            if (graph[j][i] == 1) {
                house.push_back(make_pair(j, i));
            }
            else if(graph[j][i] == 2) {
                store.push_back(make_pair(j,i));
                graph[j][i] = 0;
            }
        }
    }

    permutation(0, 0);

    cout << answer << endl;

    return 0;
}