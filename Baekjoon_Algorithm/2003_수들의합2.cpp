#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int start = 0, end = 0, sum = 0, cnt = 0;
    while(start <= end){
        if(sum >= m){
            sum -= arr[start++];
        }
        else if(end == n){
            break;
        }
        else{
            sum += arr[end++];
        }
        if(sum == m) cnt++;
    }
    cout << cnt << endl;
    return 0;
}