#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    string temp = words[0];
    int cnt = 0;
    for (int i = 1; i < words.size(); i++) {
        for (int j = 0; j < n; j++) {
            cnt++;

            char c1 = temp[temp.size() - 1];
            char c2 = words[i][0];
            if (c1 == c2) {
                temp = words[i];
                continue;
            }
            cout << " Àâ¾Ò´Ù" << endl;
            answer.push_back(j + 1);
            answer.push_back(cnt);
            break;
        }
    }

    return answer;
}

int main(void) {
    solution(3, { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" });

}