#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n+2);

    for(int i = 0; i < lost.size(); i++){
        student[lost[i]]--;
    }

    for(int i = 0; i < reserve.size(); i++){
        student[reserve[i]]++;
    }

    for(int i = 1; i <= n; i++){
        if(student[i] == 1 && student[i-1] == -1){
            student[i-1]++;
            student[i]--;
        }
        else if(student[i] == 1 && student[i+1] == -1){
            student[i+1]++;
            student[i]--;
        }
    }

    for(int i = 1; i <= n; i++){
        if(student[i] >= 0) answer++;
    }
    return answer;
}

int main(void){
    cout << solution(5, {2,4},{3}) <<endl;
    return 0;
}