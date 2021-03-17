#include <iostream>

using namespace std;

int dp[1000001];
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n; 
    
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }

    cout << dp[n] << endl;


    return 0;
}