#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, a, b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << a+b<< "\n";
    }
    return 0;
}