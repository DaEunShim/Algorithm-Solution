#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

vector<string> answer;
void selectMenu(vector<string> orders, int course){
    map<string, int> m;
    for (int i = 0; i < orders.size(); i++) {
        if(orders[i].size() < course) continue;
        sort(orders[i].begin(), orders[i].end());

        // 조합..
        vector<bool> temp(orders[i].size(), true);
        for (int j = 0; j < orders[i].size() - course; j++)  // 뒤에 false가 n-r개 채워지고 true 가 r개 채워진다.
            temp[j] = false;
        do {
            string s = "";
            for (int j = 0; j < orders[i].size(); j++) {
                if (temp[j])
                    s += orders[i][j];
            }
            m[s]++;
        } while (next_permutation(temp.begin(), temp.end()));

    }
    int maxValue = 2;
    vector<string> key;
    for(auto kv: m){
        if(kv.second > maxValue){
            maxValue = kv.second;
            key.clear();
            key.push_back(kv.first);
        } else if (kv.second == maxValue){
            key.push_back(kv.first);
        }
    }
    for (string s : key) {
        answer.push_back(s);
    }
    m.clear();
}
vector<string> solution(vector<string> orders, vector<int> course) {
    for(int i = 0; i < course.size(); i++)
        selectMenu(orders, course[i]);
    sort(answer.begin(), answer.end());

    for(string s: answer){
        cout << s<< endl;
    }
    return answer;
}