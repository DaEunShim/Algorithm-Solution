#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    pair<vector<int>::iterator, vector<int>::iterator> p = minmax_element(stones.begin(),stones.end());
    int min = *p.first;
    int max = *p.second;
    while (min <= max) {
        int mid = (max + min) / 2;
        int cnt = 0;

        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] - mid <= 0)  cnt++;
            else cnt = 0;
            if (cnt >= k) break;
        }
        if (cnt >= k) max = mid - 1;
        else  min = mid + 1;
    }
    return min;
}