#include <iostream>
#include <cctype>

using namespace std;

int arr[26];
int main(void){
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        int num = toupper(s[i]) - 'A';
        arr[num]++;
    }

    int cnt = 0;
    char ans;
    bool flag = false;
    for(int i = 0; i < 26; i++){
        if(cnt < arr[i]){
            cnt = arr[i];
            ans = i + 'A';
            flag = false;
        }
        else if(cnt == arr[i]){
            flag = true;
        }
    }

    if(flag) cout<< "?" << endl;
    else cout << ans <<endl;
    return 0;
}