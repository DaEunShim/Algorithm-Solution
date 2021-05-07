#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = s.length();
    for(int i = 1; i <= s.length()/2; i++){
        string temp ="";
        // i개 단위로 압축
        int cnt = 1;
        string sub = s.substr(0, i);
        for (int j = i; j <= s.length(); j += i) {
            // j부터 i개 연속된 문자
            if(sub == s.substr(j, i)) cnt++;
            else{
                if(cnt > 1) temp += to_string(cnt);
                temp += sub;
                sub = s.substr(j, i);
                cnt = 1;
            }
        }
        if ((s.length() % i) != 0) {
            temp += s.substr((s.length() / i) * i);
        }
        answer = min(answer, (int)temp.length());
    }
    return answer;
}
