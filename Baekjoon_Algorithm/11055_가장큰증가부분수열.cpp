#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<long long> dp(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    long long ans = arr[0];
    for(int i = 0; i < n; i++){
        dp[i] = arr[i];
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && dp[i] < dp[j] + arr[i]){
                dp[i] = dp[j] + arr[i];
            }
            ans = max(ans, dp[i]);
        }
    }

    cout<< ans << endl;
    return 0;
}