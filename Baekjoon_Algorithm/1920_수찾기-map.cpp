#include <iostream>
#include <unordered_map>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m, num;
    cin >> n;
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++){
        cin >> num;
        hash[num] = 1;
    }

    cin >> m;
    int key;
    for(int i = 0; i < m; i++){
        cin >> key;
        if(hash.find(key) == hash.end()) cout<< "0\n";
        else cout <<"1\n";
    }
    return 0;
}