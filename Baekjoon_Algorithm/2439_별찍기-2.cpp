#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int k = 1; k <= n; k++){
        for(int i = n - k; i > 0; i--){
            cout <<" ";
        }
        for(int j = 1; j <= k; j++){
            cout << "*";
        }
        cout <<"\n";
    }

    return 0;
}