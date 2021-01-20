// 6:39
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); 
    int n, num;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> num;
            if(pq.size() < n){
                pq.push(num);
            }
            else if(pq.top() < num) {
                pq.pop();
                pq.push(num);
            }
        }
    }

    cout << pq.top() << endl;
    return 0;
}