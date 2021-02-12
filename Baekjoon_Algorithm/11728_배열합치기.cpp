#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);
    vector<int> arr(n+m);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    
    int i = 0, j = 0, pos = 0;
    while(i < n && j < m){
        if(a[i] <= b[j]){
            arr[pos++] = a[i++];
        }
        else{
            arr[pos++] = b[j++];
        }
    }

    while(i < n){
        arr[pos++] = a[i++];
    }
    while(j < m){
        arr[pos++] = b[j++];
    }

    for(int k =0; k < n+m; k++){
        cout << arr[k] << " ";
    }
    cout << endl;
    return 0;
}