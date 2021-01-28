#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    for(int i = 0; i < progresses.size(); i++){
        if((100 - progresses[i]) % speeds[i] > 0) days.push_back((100 - progresses[i]) / speeds[i] +1);
        else days.push_back((100 - progresses[i]) / speeds[i]);
    }

    int cnt = 0, temp = days[0];
    for(int i = 0; i < days.size();i++){
        if(days[i] <= temp) cnt++;
        else{
            answer.push_back(cnt);
            cnt = 1;
            temp = days[i];
        }
    }
    answer.push_back(cnt);

    return answer;
}