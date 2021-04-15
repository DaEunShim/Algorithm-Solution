// 6:50~
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, B, C;
    long long cnt = 0;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++)
        cin >> A[i];
    cin >> B >> C;

    int temp;
    for (int i = 0; i < n; i++){
        if(A[i] - B <= 0) { // 총감독으로 충분
            cnt++;
            continue;
        }
        // 부감독
        if(((A[i] - B) % C) != 0) cnt++;
        cnt += ((A[i] - B) / C) + 1;
    }

    cout << cnt << endl;
    return 0;
}