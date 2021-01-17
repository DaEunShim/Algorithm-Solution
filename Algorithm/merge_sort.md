## 알고리즘 개념

- 분할 정복 방법을 통해 구현한다.
- 안정 정렬에 속한다.
- 레코드 리스트를 반으로 나누어 2개의 서브 리스트로 분할하고, 각 서브 리스트에 이 과정을 재귀적으로 적용하여 더 이상 분할이 불가능할 때까지 반복한다.
- 분할이 완료된 이후에는 이웃하는 두 개의 파티션을 서로 병합하여 정렬을 완료한다.

## 과정

1. 분할: 배열을 같은 크기의 2개의 부분 배열로 분할한다.
2. 정복: 부분 배열을 정렬한다.
3. 결합: 정렬된 부분 배열들을 하나의 배열에 병합한다.
    1. 2개의 리스트의 값들을 처음부터 하나씩 비교하여 더 작은 값을 새로운 리스트로 옮긴다.
    2. 둘 중 하나가 끝날 때까지 반복한다.
    3. 둘 중 하나가 먼저 끝나면 나머지 리스트의 값들을 전부 넣는다.
    4. 새로운 리스트를 원래 리스트로 옮긴다.

## 코드

```cpp
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
```

## 장점

- 성능이 좋다.
- 연결 리스트로 레코드 구성 시 유리하다.(제자리 정렬도 가능)

## 단점

- 별도의 임시 배열이 필요하다.(제자리 정렬 = in-place sorting)이 아니다.

## 시간 복잡도

- 분할할 때 걸리는 시간은 O(n), 병합에 걸리는 시간은 O(n) 그리고 레벨의 수가 O(logn)이므로 전체 레벨의 병합에 걸리는 총 시간은 O(nlogn) - 최선, 평균, 최악 동일

## 공간복잡도

- O(n)