#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int T, N, K;
string str;
set<string, greater<string> > s;

int main(){
    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> N >> K;
        cin >> str;
        int size = str.size();
        for(int i = 0; i < size; i++){
            string temp = "";
            for(int j = 0; j < size/4; j++){
                temp += str[(i+j) % size];
            }
            s.insert(temp);
        }

        // set 16진수 -> vector 10진수
        set<string>::iterator iter = s.begin();
        for (int i = 0; i < K - 1; iter++, i++);
        cout << "#" << t <<" "<< stoi(*iter, nullptr, 16) << endl;
        s.clear();
    }

    return 0;
}