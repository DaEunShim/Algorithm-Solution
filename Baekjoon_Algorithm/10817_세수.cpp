#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int a,b,c;
    cin >> a >> b >> c;
    
    if(a < b){
        if(a > c) cout << a << endl;
        else if(c > b) cout << b << endl;
        else cout << c << endl;
    }
    else{ 
        if(b > c) cout << b << endl;
        else if(c > a) cout << a << endl;
        else cout << c << endl;
    } 

    return 0;
}