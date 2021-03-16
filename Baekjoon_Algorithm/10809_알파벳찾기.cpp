#include <iostream>
#include <string>

using namespace std;

int arr[26] = {-1, } ;
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    for(int i = 0; i < 26; i++)
        arr[i] = -1;

    int word;
    for(int i = 0; i < s.size(); i++){
        word = s[i]-'a';
        if(arr[word] == -1) arr[word] = i;
    }

    for(int i = 0; i < 26; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}