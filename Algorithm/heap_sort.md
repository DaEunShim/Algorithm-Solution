## 알고리즘 개념

- 완전 이진 트리를 기본으로 하는 힙 자료구조를 기반으로 한 정렬 방
- 불안정 정렬에 속한다.
- 최대 힙의 루트가 원소의 최대값이라는 점을 활용하여 정렬을 수행하는 방법이다.
- 루트를 제외한 힙이 재정렬되는 과정이 반복되면서 정렬이 이루어진다.

## 과정

1. 최대 힙을 구성한다.
2. 루트를 힙의 마지막 원소와 교환한다.
3. 마지막 원소를 제외하고 나머지 원소에 대해서 반복한다.
4. 정렬된 원소를 제외하고 최대 힙에 원소가 1개 남으면 정렬을 종료한다.

## 최대 힙 재구성 과정

1. 노드 i(=n/2)와 그 자식 노드(2i, 2i+1) 중 큰 값과 비교하여 자식 노드가 더 크면 노드 i와 교환한다.
2. i의 값을 1씩 감소시킨 후 i>0 인 경우에 대해서 위 과정을 반복한다.

## 코드

```cpp
int arr[1000000];

void swap(int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void makeheap(int root, int n){
    int temp = arr[root]; // 해당 부모 노드
    int child = root * 2; // 왼쪽 자식 노드
    while(child <= n){
        // 더 큰 자식 노드 찾기
        if(child<n && arr[child] < arr[child+1])
            child++;
        if(temp < arr[child]){ // 자식 노드가 더 클 경우
            arr[child/2] = arr[child];
            child *=2; // 레벨 낮추기
        }
        else break;
    }
    arr[child/2] = temp;

}
void heapsort(int n){
    // 최대 힙 구성
    for(int i = n / 2; i > 0; i--){
        makeheap(i, n);
    }

    int temp;
    for(int i = n; i > 0; i--){
        swap(1, i);
        makeheap(1, i - 1);
    }
}
```

트리에서 index 0은 사용하지 않으니 arr[0] = 0으로 하고, arr[1]부터 입력을 받는다.

## 장점

- 성능이 좋다.
- 가장 큰 값이나 가장 작은 값을 구할 때 유용하다.

## 단점

- 데이터의 상태에 따라 같은 O(nlogn) 시간 복잡도 라도 조금 느리다.
- 불안정 정렬이다.

## 시간 복잡도

- 평균, 최선, 최악 모두 O(nlogn)

## 공간복잡도

- O(n)