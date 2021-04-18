#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, minResult = 0x7fffffff, maxResult = 0x80000000;
int num[101];  // 0: 덧셈, 1: 뺄셈, 2: 곱셈 3: 나눗셈
vector<int> oper(100);
vector<int> perm(100);
vector<bool> check(100);

void calculation(){
    int result = num[0];
    for (int i = 0; i < n - 1; i++) {
        switch(perm[i]){
            case 0: result += num[i+1]; break;
            case 1: result -= num[i+1]; break;
            case 2: result *= num[i+1]; break;
            case 3: result /= num[i+1]; break;
        }
    }
    minResult = min(minResult, result);
    maxResult = max(maxResult, result);
}

void dfs(int cnt) {
    if(cnt == n - 1) {
        calculation();
        return;
    }

    for(int i = 0; i < n - 1; i++){
        if(check[i]) continue;
        check[i] = 1;
        perm[cnt] = oper[i];
        dfs(cnt+1);
        check[i] = 0;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> num[i];
    int temp, k = 0;
    for(int i = 0; i < 4; i++){
        cin >> temp;
        for(int j = 0; j < temp; j++, k++){
            oper[k] = i;
        }
    }

    dfs(0);

    cout << maxResult << endl;
    cout << minResult <<endl;

    return 0;
}