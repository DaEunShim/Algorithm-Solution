#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string map1[17][17];
string map2[17][17];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    // 둘 다 공백 - 공백
    string str;
    for (int i = 0; i < arr1.size(); i++) {
        str = bitset<16>(arr1[i]).to_string();
        for (int j = n; j > 0; j--) {
            map1[i][n - j] = str[16 - j];
        }
    }
    for (int i = 0; i < arr2.size(); i++) {
        str = bitset<16>(arr2[i]).to_string();
        for (int j = n; j > 0; j--) {
            map2[i][n - j] = str[16 - j];
        }
    }
    for (int i = 0; i < n; i++) {
        string temp = "";
        for (int j = 0; j < n; j++) {
            if (map1[i][j] == "0" && map2[i][j] == "0")
                temp += " ";
            else
                temp += "#";
        }
        answer.push_back(temp);
    }

    return answer;
}