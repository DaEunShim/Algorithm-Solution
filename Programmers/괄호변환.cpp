#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string answer = "";

bool rightString(string s){
    stack<int> st;
    int openCount = 0;   // '('의 개수
    int closeCount = 0;  // ')'의 개수

    // s 문자열 순회
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
            openCount++;
        }

        if (s[i] == ')') {
            closeCount++;

            if (!st.empty())
                st.pop();
        }
    }

    // s 문자열 순회 끝
    if (st.empty() && openCount == closeCount && openCount > 0 && closeCount > 0)
        return true;
    else
        return false;
}

string separate(string p){
    string temp="";
    // 1단계
    if (p == "") return "";
    // 2단계
    int cnt1 = 0, cnt2 = 0, i ;
    for (i = 0; i < p.size(); i++) {
        if (p[i] == '(')
            cnt1++;
        else
            cnt2++;
        if (cnt1 == cnt2) break;
    }

    string u, v;
    u = p.substr(0, i + 1);
    if(i + 1 == p.size()) v = "";
    else v = p.substr(i + 1);

    // 3단계 u가 올바른 괄호 문자열인지
    if (rightString(u)) {
        // v에 대해서 1단계부터 다시 수행
        temp += u + separate(v);
    }
    // // 4단계
    else {
        temp = "(" + separate(v) + ")";
        for (int j = 1; j < u.size() - 1; j++) {
            if(u[j] == '(')
                temp += ")";
            else
                temp += "(";
        }
    }
    return temp;
}

string solution(string p) {

    return separate(p);
}
