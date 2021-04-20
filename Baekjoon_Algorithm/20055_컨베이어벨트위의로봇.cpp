#include <iostream>
#include <vector>

using namespace std;

int N, K, answer = 1;
int power[201];
bool robot[101];

void print(){
    for (int i = 1; i <= 2 * N; i++)
        cout << power[i] <<" ";
    cout << endl;
}
int main(){
    cin >> N >> K;
    for(int i = 1; i <= 2*N; i++)
        cin >> power[i];

    while(1){
        // 1. 벨트 회전
        int temp1, temp2 = power[2*N];
        for (int i = 1; i <= 2 * N; i++){
            temp1 = power[i];
            power[i] = temp2;
            temp2 = temp1;
        }

        bool temp3, temp4 = robot[N];
        for (int i = 1; i <= N; i++) {
            temp3 = robot[i];
            robot[i] = temp4;
            temp4 = temp3;
        }

        // 로봇 내리기
        if(robot[N]) robot[N] = 0;

        // 2. 로봇 이동
        for(int i = N - 1; i >= 1; i--){
            if (robot[i] && !robot[i + 1] && power[i + 1] >= 1){
            // 다음 칸에 로봇 있으면 못 옮김, 다음 칸 내구도 1 이상 이어야 함
                robot[i+1] = 1;
                power[i+1]--;
                robot[i] = 0;
            }
        }

        // 로봇 내리기
        if (robot[N]) robot[N] = 0;

        // 3. 로봇 추가
        if (!robot[1] && power[1] >= 1) {
            power[1]--;
            robot[1] = 1;
        }

        // 4. 내구도 0 칸 개수 K 이상이면 종료
        int cnt = 0;
        for(int i = 1; i <= 2*N; i++){
            if(!power[i]) cnt++;
        }
        if(cnt >= K) {
            cout <<answer<< endl;
            return 0;
        }
        answer++;
    }
    return 0;
}