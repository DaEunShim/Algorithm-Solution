#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T, a, b;
    cin >> T;
    while(T--){
        cin >> a >> b;
        cout << a + b << "\n";
    }

    return 0;
}