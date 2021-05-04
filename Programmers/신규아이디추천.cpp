#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {

    for(int i = 0; i < new_id.length(); i++){
        // 1단계 대문자 -> 소문자
        if('A' <= new_id[i] && new_id[i] <= 'Z'){
            new_id[i] = tolower(new_id[i]);
            continue;
        }
        // 2단계 제거
        else if (('a' <= new_id[i] && new_id[i] <= 'z') || ('0' <= new_id[i] && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] =='_' ||new_id[i] == '.') {
            continue;
        }
        else {
            new_id.erase(new_id.begin() + i);
            i--;
        }
    }


    bool flag = false;
        for (int i = 0; i < new_id.length(); i++) {
            if (new_id[i] == '.') {
                // 4단계
                if (i == 0 || i == new_id.length() - 1) {
                    new_id.erase(new_id.begin() + i);
                    i--;
                }
                // 3단계
                if (flag) {  // 바로 전에 .
                    for (int j = i; j < new_id.length(); j++) {
                        if (new_id[j] != '.')  break;
                        new_id.erase(new_id.begin() + j);
                        j--;
                    }
                    flag = false;
                } else
                    flag = true;
            } 
            else flag = false;
        }
        // 마지막 . 없애기
        for(int i = new_id.length() - 1; i >= 0; i--){
            if(new_id[i] != '.') break;
            new_id.erase(new_id.begin() + i);
        }


        // 5단계
        if(new_id.length() == 0) new_id = 'a';

        // 6단계
        if(new_id.length() >= 16){
            new_id.erase(new_id.begin() + 15, new_id.end());
            // 마지막 . 없애기
            for (int i = new_id.length() - 1; i >= 0; i--) {
                if (new_id[i] != '.') break;
                new_id.erase(new_id.begin() + i);
            }
        }

        // 7단계
        if(new_id.length() <= 2){
            for(int i = 0; i < new_id.length(); i++){
                if(new_id.length() < 3){
                    new_id += new_id[new_id.length() - 1];
                }
            }
        }

        return new_id;
    }
