#include <iostream>
#include <unordered_map>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, cnt = 0;
    string s;
    cin >> n;
    while(n--){
        bool flag = true;
        cin >> s;
        unordered_map<char, int> map;
        for(int i = 0; i < s.length(); i++){
            if(map.find(s[i]) == map.end()){ // 처음 등장
                map.insert(make_pair(s[i], i));
            }
            else { // 등장 했던 경우
                if(map[s[i]] == i - 1) map[s[i]] = i; // 연속된 문자면 값 업데이트
                else{ // 그룹 단어 아닌 경우
                    flag = false;
                    break;
                }
            }
        }
        if(flag) cnt++;
    }
    cout << cnt <<endl;
    return 0;
}