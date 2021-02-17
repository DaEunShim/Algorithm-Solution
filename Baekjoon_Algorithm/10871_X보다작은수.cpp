#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, x, num;
    cin >> n >> x;
    vector<int> arr(n);
    while(n--){
        cin >> num;
        if(num < x) cout << num << " ";
    }
    cout << endl;
    return 0;
}