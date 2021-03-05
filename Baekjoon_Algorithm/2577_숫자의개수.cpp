#include <iostream>
#include <string>

using namespace std;

int arr[10] = {0} ;
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int A, B, C;
    cin >> A >> B >> C; 
    
    string value = to_string(A * B * C);

    for(int i = 0; i < value.size(); i++){
        arr[value[i]-'0']++;
    }
    for(int i = 0; i < 10; i++){
        cout << arr[i] << endl;
    }

    return 0;
}