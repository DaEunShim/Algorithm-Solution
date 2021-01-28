#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];
int binarysearch(int key, int left, int right){
    long long mid = (left + right) / 2;
    if(left <= right){
        if(key == arr[mid]) return 1;
        else if(key < arr[mid]) return binarysearch(key, left, mid - 1);
        else return binarysearch(key, mid + 1, right);
    }
    else return 0;
}
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    cin >> m;
    int key;
    for(int i = 0; i < m; i++){
        cin >> key;
        cout << binarysearch(key, 0, n-1) << "\n";
    }

    return 0;
}