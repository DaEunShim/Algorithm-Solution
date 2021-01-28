#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tree[1000000];
int n, m, answer = 0;
int binarysearch(int left, int right){
    long long mid = (left + right) / 2;
    if(left <= right){
        long long sum = 0;
        for(int i = 0; i < n; i++){
            if(tree[i] - mid > 0) sum += tree[i] - mid;
        }

        if(sum == m) return mid;
        else if(sum > m) return binarysearch(mid + 1, right);
        else return binarysearch(left, mid - 1);
    }
    return mid;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        cin >> tree[i];
    sort(tree, tree + n);

    cout << binarysearch(0, tree[n-1]) << "\n";

    return 0;
}