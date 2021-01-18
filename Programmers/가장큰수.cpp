#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool compare(int a, int b){
    string str1 = to_string(a);
    string str2 = to_string(b);
    return str1+str2 > str2+str1;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);   
    if(numbers[0] == 0) return "0"; 
    for(int num: numbers){
        answer += to_string(num);
    }
    cout<< answer<<endl;
    return answer;
}
