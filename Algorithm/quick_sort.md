## 알고리즘 개념

- 분할 정복 방법을 통해 큰 문제를 작은 문제 단위로 쪼개면서 해결된다.
- 불안정 정렬에 속한다.
- 보통 프로그래밍 언어에서 sort의 내부적으로 사용된다.
- 임의의 기준 수 pivot을 선택하여 정렬 대상 수들을 pivot 값보다 작은 그룹과 큰 그룹으로 분할한다.
- pivot은 작은 그룹과 큰 그룹 사이로 이동시킨다.
- 분할 된 각 그룹에 대해서 재귀적으로 또 다시 pivot을 정하고 동일한 과정을 반복한다. 원소가 1개가 되어 더이상 분할이 불가능할 때까지 반복한다.

## 알고리즘 배열 내부에서의 분할 과정

1. i는 왼쪽 끝, j는 오른 쪽 끝 위치로 둔다.
2. pivot을 첫번째 항목으로 선택하고(때에 따라 랜덤이나 중간 값을 선택 할 수도 있음) pivot보다 큰 값을 만날 때까지 i값을 1씩 증가시키고, pivot보다 작은 값을 만날 때까지 j값을 1씩 감소시킨다.
3. 고정된 i와 j 위치의 수를 교환하고 i<j 일 때까지 이 과정을 반복한다.
4. i≥j 이면 분할이 완료된 것으로 list[j]와 pivot을 교환한다.

## 코드

1. pivot을 가장 왼쪽 값으로 설정한 경우

```cpp
void quicksort(int left, int right){
    if(left >= right) return;
    int i = left + 1;
    int j = right;
    int pivot = left;

    while(i<=j){
        while(i <= right && arr[i] <= arr[pivot]) i++;
        while(j > left && arr[j] >= arr[pivot]) j--;
        if(i > j){ // 엇갈린 상태
            swap(pivot, j);
        }
        else{
            swap(i, j);
        }
    }

    quicksort(left, j-1);
    quicksort(j+1, right);
}
```

2. pivot을 중간 값으로 설정한 경우(최악의 경우를 방지하기 위함)

```cpp
void swap(int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void quicksort(int left, int right){
    if(left >= right) return;
    **// pivot 중간 index로 지정
    int mid = (left + right) / 2;
    swap(mid, left);**

    int pivot = left;
    int i = left + 1;
    int j = right;

    while(i<=j){
        while(i <= right && arr[i] <= arr[pivot]) i++;
        while(j > left && arr[j] >= arr[pivot]) j--;
        if(i > j){ // 엇갈린 상태
            swap(pivot, j);
        }
        else{
            swap(i, j);
        }
    }

    quicksort(left, j-1);
    quicksort(j+1, right);
}
```

## 장점

- 빠르다 O(nlogn)

## 단점

- 최악의 경우 느리다.

## 시간 복잡도

- 두 그룹으로 분할하는데 n의 시간이 걸리고 분할된 단계가 long(n)개 존재하므로 평균 정렬 속도는 O(nlog2n)
- 분할한 결과가 한쪽으로 몰리는 최악의 경우에는 O(n^2)

## 공간복잡도

- O(n)