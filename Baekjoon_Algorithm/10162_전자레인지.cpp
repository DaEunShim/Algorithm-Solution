#include <iostream>

using namespace std;

int timer[3];
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T; 
    
    // a: 300, b:60, c:10
    timer[0] = T / 300;
    if(timer[0] != 0) T %= 300;

    timer[1] = T / 60;
    if(timer[1] != 0) T %= 60;

    timer[2] = T / 10;
    if(timer[2] != 0) T %= 10;

    if(T != 0) cout << "-1" << endl;
    else cout << timer[0] << " " << timer[1] << " "<< timer[2] << endl;

    return 0;
}