#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void){
    int n, k, cnt = 0;
    cin >> n >> k;
    vector<bool> arr(n+1);
    for(int i = 2; i <= n; i++){
        if(arr[i]) continue;
        for(int j = i; j <= n; j += i){
            if(arr[j]) continue;
            if(++cnt == k) {
                cout << j <<endl;
                return 0;
            }
            arr[j] = true;
        }
    }
    return 0;
}
