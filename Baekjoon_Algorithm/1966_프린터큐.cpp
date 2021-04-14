#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T, N, M, paper;
    cin >> T; 
    while(T--){
        cin >> N >> M;
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        for(int i = 0; i < N; i++){
            cin >> paper;
            pq.push(paper);
            q.push(make_pair(paper, i));
        }

        int cnt = 1;
        while(!q.empty()){
            int nValue = q.front().first;
            int nIndex = q.front().second;
            q.pop();

            if(nValue == pq.top()){
                pq.pop();
                if(nIndex == M){
                    cout << cnt << endl;
                }
                cnt++;
            }
            else{
                q.push(make_pair(nValue, nIndex));
            }
        }
    }

    return 0;
}