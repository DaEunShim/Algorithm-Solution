#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1, len = clothes.size();
    vector<pair<string, int>> category;
    for (int i = 0; i < len; i++) {
        bool flag = true;
        for (vector<pair<string, int>>::iterator it = category.begin(); it != category.end(); it++) {
            if (!clothes[i][1].compare(it->first)) {
                it->second++;
                flag = false;
                break;
            }
        }
        if (flag) category.push_back(make_pair(clothes[i][1], 1));
    }
    for (vector<pair<string, int>>::iterator it = category.begin(); it != category.end(); it++)
        answer *= it->second + 1;
    return answer - 1;
}
