#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];
int main(void){
    // insertion sort 사용
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int j, temp;
    for (int i = 1; i < n; i++){
        // 정렬 대상 원소 저장
        temp = arr[i]; 
        for (j = i - 1 ; j >= 0 && temp < arr[j]; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }

    for (int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }

    return 0;
}

