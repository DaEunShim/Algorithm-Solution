#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 100000001
using namespace std;


int solution(int n, int s, int a, int b, vector<vector<int> > fares) {
    vector<vector<int> > floyd(201, vector<int>(201, MAX));
    // 배열 정리
    for (int i = 1; i <= n; i++) {
        floyd[i][i] = 0;
    }
    for(int i = 0; i < fares.size(); i++){
        floyd[fares[i][0]][fares[i][1]] = fares[i][2];
        floyd[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    // 플로이드와샬 -> 최단거리
    for (int k = 1; k <= n; k++) {                                          // k 는 거쳐가는 정점
        for (int i = 1; i <= n; i++) {                                      // i 는 행 (출발 정점)
            for (int j = 1; j <= n; j++) {                                  // j 는 열 (도착 정점)
                if(floyd[i][k] == MAX || floyd[k][j] == MAX) continue;                             
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);  // 점화식 distance[i,j] = min(distance[i,j], distance[i,n] + distance[n,j])
            }
        }
    }

    // start에서 어디까지 같이가기. 거기서 각자 가기-> 브루트포스
    int answer = floyd[s][a] + floyd[s][b];
    for(int i = 1; i <= n; i++){
        answer = min(answer, floyd[s][i] + floyd[i][a] + floyd[i][b]);
    }

    return answer;
}
