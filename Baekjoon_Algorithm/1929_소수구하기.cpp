#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int m, n;
    cin >> m >> n;
    vector<bool> arr(n+1);
    arr[1] = true;
    for(int i = 2; i <= sqrt(n); i++){
        if(arr[i]) continue;
        for(int j = i + i; j <= n; j += i)
            arr[j] = true;
    }

    for(int i = m; i <= n; i++)
        if(!arr[i]) cout << i << "\n";

    return 0;
}
