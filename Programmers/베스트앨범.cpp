#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<string, int>p1, pair<string, int>p2) {
    if (p1.second > p2.second) return true;
    else return false;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector <pair<string, int>> category; // 장르 순위 세우기 위함.
    map <string, pair<int,int>> maxPlay; // max들의 재생 수
    map <string, pair<int, int>> maxNum; // max들의 고유번호
    for (int i = 0; i < genres.size(); i++) {
        if (maxPlay[genres[i]].first < plays[i]) {
            maxPlay[genres[i]] = make_pair(plays[i], maxPlay[genres[i]].first);
            maxNum[genres[i]] = make_pair(i, maxNum[genres[i]].first);
        }
        else if (maxPlay[genres[i]].second < plays[i]) {
            maxPlay[genres[i]] = make_pair(maxPlay[genres[i]].first, plays[i]);
            maxNum[genres[i]] = make_pair(maxNum[genres[i]].first, i);
        }

        bool flag = true;
        for (vector<pair<string, int>>::iterator it = category.begin(); it != category.end(); it++) {
            if (!genres[i].compare(it->first)) {
                it->second += plays[i];
                flag = false;
                break;
            }
        }
        if (flag) category.push_back(make_pair(genres[i], plays[i]));
    }
    sort(category.begin(), category.end(), compare);
    for (int i = 0; i < category.size(); i++) { // 카테고리(장르) 마다 
        if (maxPlay[category[i].first].first > 0) answer.push_back(maxNum[category[i].first].first);
        else continue;
        if (maxPlay[category[i].first].second > 0) answer.push_back(maxNum[category[i].first].second);
    }
    return answer;
}