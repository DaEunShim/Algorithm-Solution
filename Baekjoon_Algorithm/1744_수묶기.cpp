#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, sum = 0;
    cin >> n; 
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());

    // 양수 일 때
    for(int i = n-1; i >= 1 && v[i-1] > 1; ){
        v[i-1] = v[i] * v[i-1];
        v[i] = 99999;
        i -= 2;
    }

    // 음수 일 때
    for(int i = 0; i < n-1 && v[i+1] <= 0; ){ 
        v[i+1] = v[i] * v[i+1];
        v[i] = 99999;
        i += 2; 
    }

    for(int j = 0; j < v.size(); j++)
        if(v[j] != 99999) sum += v[j];
    
    
    cout << sum <<endl;
    return 0;
}

