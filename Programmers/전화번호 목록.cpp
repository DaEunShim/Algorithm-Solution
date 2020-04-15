#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    int len = phone_book.size();
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0; i < len-1; i++){
        if(phone_book[i].find(phone_book[i+1],0)==0) return false;
        if(phone_book[i+1].find(phone_book[i],0)==0) return false;
    }    
    return true;
}