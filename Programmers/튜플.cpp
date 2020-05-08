#include <string>
#include <vector>

#include <cstdlib>
#include <set>
#include <algorithm>

using namespace std;

bool func(vector<int> v1, vector<int> v2) {
    if (v1.size() > v2.size()) return false;
    else return true;
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> v1;
    vector<int> v2;
    set<int> swap;

    string element;
    bool flag = false;
    for (int i = 0; i < s.length() - 1; i++) {
        if ('0' <= s[i] && s[i] <= '9') { // 숫자인 경우
            element.push_back(s[i]);
            flag = true;
        }
        if (s[i] == ',' && flag) { // 집합 안의 ,
            v2.push_back(atoi(element.c_str()));
            element = "";
            flag = false;
        }
        if (s[i] == '}') {
            v2.push_back(atoi(element.c_str()));
            element = "";
            v1.push_back(v2);
            v2.clear();
            flag = false;
        }
    }

    sort(v1.begin(), v1.end(), func);

    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v1[i].size(); j++) {
            if (swap.find(v1[i][j]) == swap.end()) {
                swap.insert(v1[i][j]);
                answer.push_back(v1[i][j]);
            }
        }
    }
    return answer;
}