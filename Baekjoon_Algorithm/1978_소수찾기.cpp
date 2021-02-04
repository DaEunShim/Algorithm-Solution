#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> arr(1001);
void isPrime(){
    arr[1] = true;
    for(int i = 2; i <= sqrt(1000); i++){
        if(arr[i]) continue;
        for(int j = i + i; j <= 1000; j += i)
            arr[j] = true;
    }
}

int main(void){
    int n, num, cnt = 0;
    cin >> n;
    isPrime();
    while(n--){
        cin >> num;
        if(!arr[num]) cnt++;
    }
    cout << cnt <<endl;
    return 0;
}
