# 최장 증가 수열 (LIS = Longest Increasing Sequence)

## 알고리즘 개념

- 가장 긴 증가 하는 수열!
- {2, 4, 7, 1, 5, 6} 이라는 배열이 있을 때 LIS는 **{2, 4, 5, 6}**
- 배열의 원소가 증가하게 숫자를 고르면서 부분 수열의 길이가 최대가 되도록 선택한다.

## 과정

1. DP를 이용했을 경우. 
- dp[i] = i 번째 원소를 마지막으로 하는 LIS 길이

             = 0 ~ i-1 번째 원소들 중에서 i번째 원소보다 값이 작은 것들 중, 가장 큰 dp 값 + 1

2. lower bound를 이용했을 경우

- lower_bound란 삽입되는 원소보다 크거나 같은 첫번째 원소의 위치를 반환한다.
- 새로운 배열을 만들고 마지막 원소보다 크면 다음 자리에 원소 삽입
- 마지막 원소보다 작거나 같으면 lower_bound로 위치 찾은 후 그 자리에 삽입

## 코드

```cpp
// DP 를 이용한 방법
int ans = 0;
for(int i = 0; i < n ; i++){
    dp[i] = 1;
    for(int j = 0; j < i; j++){
        if(arr[i] > arr[j] && dp[i] < dp[j]+1)
            dp[i] = dp[j] + 1;
    }
    ans = max(ans, dp[i]);
}

cout << ans << endl;
```

```cpp
// lower_bound 를 이용한 방법
vector<int> temp;
temp.push_back(arr[0]);
for(int i = 1; i < n; i++){
    if(temp.back() < arr[i]) temp.push_back(arr[i]);
    else{
        int lb = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
        temp[lb] = arr[i];
    }
}

cout<< temp.size() <<endl;
```

## 시간복잡도

- DP로 구현시: **O(N^2)**
- lower_bound 이용시: **O(NlogN)**

    → 단, temp 배열이 가장 긴 증가하는 부분 배열이 아닐 수 있다.

    즉, 답은 알지만 경로를 알수는 없다.