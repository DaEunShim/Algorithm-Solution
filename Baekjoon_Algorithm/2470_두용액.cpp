#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long sum, minimum = 9999999999;
    int L = 0, R = n - 1, left = 0, right = n - 1;
    while (L < R){
        sum = arr[L] + arr[R];
        if (abs(sum) < minimum) {
            minimum = abs(sum);
            left = L;
            right = R;
        }
        if (sum < 0)  L++;
        else R--;
}

    cout<< arr[left] <<" "<<arr[right]<<endl;
    return 0;
}