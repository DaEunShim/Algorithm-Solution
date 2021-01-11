#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];
int main(void){
    // selection sort 사용
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++){
        int minIdx = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }

    for (int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }

    return 0;
}