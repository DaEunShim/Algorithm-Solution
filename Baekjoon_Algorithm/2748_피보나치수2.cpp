#include <iostream>
#include <vector>

using namespace std;


int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n; // n번째 피보나치수 출력
    vector<long long> dp(n+1);

    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n] << endl;
    return 0;
}