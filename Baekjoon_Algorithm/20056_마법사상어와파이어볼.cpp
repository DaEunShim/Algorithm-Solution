#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
struct INFO{
    int x, y, weight, speed, dir;
};
INFO info;
vector<INFO> fireball;
vector<INFO> graph[51][51];
int dx[] = {0,1,1,1,0,-1,-1,-1}; // 0~7
int dy[] = {-1,-1,0,1,1,1,0,-1};

INFO makeInfo(int x, int y, int weight, int speed, int dir) {
    info.x = x;
    info.y  = y;
    info.weight = weight;
    info.speed = speed;
    info.dir = dir;
    return info;
}

void move(){
    // graph 초기화
    for(int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++) {
            graph[j][i].clear();
        }
    }

    // 모든 파이어볼 자신의 방향으로 속력칸 만큼 이동
    for (int i = 0; i < fireball.size(); i++) {
        int x = fireball[i].x;
        int y = fireball[i].y;
        int dir = fireball[i].dir;
        int speed = fireball[i].speed;

        int nx = (x + dx[dir] * speed) % N;
        int ny = (y + dy[dir] * speed) % N;
        if(nx > N) {while(nx > N) nx -= N;}
        if(nx <= 0) {while(nx <= 0) nx += N;}
        if(ny > N) {while(ny > N) ny -= N;}
        if(ny <= 0 ) {while (ny <= 0) ny += N;}

        // 파이어볼 이동
        fireball[i].x = nx;
        fireball[i].y = ny;
        graph[nx][ny].push_back(fireball[i]);

    }

    // 이동 다 끝나고 2개 이상 파이어볼 있는 칸
    vector<INFO> temp;
    for (int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++){
            if(graph[j][i].size() == 0) continue;
            if(graph[j][i].size() == 1) {
                temp.push_back(graph[j][i][0]);
                continue;
            }

            // 같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다.
            int weightSum = 0, speedSum = 0;
            int oddCnt = 0; // 홀수 방향 개수
            int x = graph[j][i][0].x;
            int y = graph[j][i][0].y;

            int size = graph[j][i].size();
            for (int k = 0; k < size; k++) {
                weightSum += graph[j][i][k].weight;
                speedSum += graph[j][i][k].speed;
                if (graph[j][i][k].dir % 2) oddCnt++;
            }

            // 질량 0 이면 소멸
            if(weightSum / 5 == 0) continue;

            // 4개로 나눈 파이어볼
            // 방향이 모두 짝수거나 홀수 -> 0,2,4,6
            int direction[] = {0, 1,2,3,4,5,6, 7};
            int idx = 1;
            if(oddCnt == 0 || oddCnt == size) idx = 0;
            for (; idx < 8; idx += 2) {
                temp.push_back(makeInfo(j, i, weightSum / 5, speedSum / size, direction[idx]));
            }
        }
    }
    fireball = temp;
}


int totalWeight(){
    int sum = 0;
    for (int i = 0; i < fireball.size(); i++) {
        sum += fireball[i].weight;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;
    int r,c,m,s,d;
    for(int i = 0; i < M; i++){
        cin >> r >> c >> m >> s >> d;
        fireball.push_back(makeInfo(c,r,m,s,d));
        graph[c][r].push_back(makeInfo(c, r, m, s, d));
    }

    // K번 명령
    while(K--){
        move();
    }

    cout << totalWeight() << endl;

    return 0;
}