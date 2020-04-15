#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    int i, len = participant.size();
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(i=0;i<len;i++){
        if(participant[i] != completion[i]) break;
    }
    string answer = participant[i];
    return answer;
}