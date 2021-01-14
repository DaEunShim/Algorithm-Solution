#include <iostream>

using namespace std;

int arr[1000000];
int temp[1000000];
void merge(int left, int mid, int right){
    int i = 0, j = 0, position = 0;
    int llength = mid - left;
    int rlength = right - mid + 1;
    while( i < llength && j < rlength){
        if(arr[left + i] < arr[mid + j]){
            temp[position++] = arr[left + i];
            i++;
        }
        else{
            temp[position++] = arr[mid + j];
            j++;
        }
    }

    while(i < llength){
        temp[position++] = arr[left + i];
        i++;
    }

    while(j < rlength){
        temp[position++] = arr[mid + j];
        j++;
    }

    for(int k = 0; k < position; k++){
        arr[left + k] = temp[k];
    }

}

void mergesort(int left, int right){
    if(left < right){
        int mid = (left + right ) / 2;

        mergesort(left, mid);
        mergesort(mid + 1, right);
        merge(left, mid + 1, right);
    }
}

int main(void){
    // merge sort 사용
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    mergesort(0, n-1);

    for (int i = 0; i < n; i++){
        cout << arr[i] << "\n";
    }

    return 0;
}


