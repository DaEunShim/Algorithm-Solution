#include <iostream>
#include <vector>

using namespace std;


int main(void){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> temp;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    temp.push_back(arr[0]);
    for(int i = 1; i < n; i++){
        if(temp.back() < arr[i]) temp.push_back(arr[i]);
        else{
            int lb = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[lb] = arr[i];
        }
    }

    cout<< temp.size() <<endl;
    return 0;
}