#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); 
    int n, num;
    vector<int> v(10001);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        v[num]++;
    }
    for(int i=1; i <= 10000; i++){
        while(v[i]--){
            cout<< i << "\n";
        }
    }
    return 0;
}