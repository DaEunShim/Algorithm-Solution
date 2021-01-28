## 알고리즘 개념

- 정렬이 되어있는 배열에서 데이터를 찾을 때, 원하는 탐색 범위를 두 부분으로 나눠 찾아간다.
- 중간 값과 비교해서 탐색 범위를 절반씩 줄여간다.

## 과정

1. 정렬을 한다.
2. left 값과 right 값의 중간값인 mid를 정한다.
3. 찾고자 한 값과 mid와 비교후, mid보다 작으면 right = mid -1, mid보다 크면 left = mid + 1로 설정한다.
4. left > right가 될 때까지 반복한다.

## 코드

```cpp
int binarysearch(int key, int left, int right){
    long long mid = (left + right) / 2;
    if(left <= right){
        if(key == arr[mid]) return 1;
        else if(key < arr[mid]) return binarysearch(key, left, mid - 1);
        else return binarysearch(key, mid + 1, right);
    }
    else return 0;
}
```

## 장점

- 전부 탐색하는 것보다 훨씬 빠르다.

## 단점

- 정렬이 된 상태에서 가능하다.

## 시간복잡도

- O(logN)