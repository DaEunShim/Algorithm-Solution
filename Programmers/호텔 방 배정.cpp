#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<long long> answer;
unordered_map<long long, long long> hm;

long long findRoom(long long num) {
    if (hm[num] == 0) {
        hm[num] = num + 1;
        answer.push_back(num);
        return num;
    }
     return hm[num] = findRoom(hm[num]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
    long long size = room_number.size();
    for (long long i = 0; i < size; i++) {
        if (hm[room_number[i]] == 0) { // 비었으면
            hm[room_number[i]] = room_number[i] + 1;
            answer.push_back(room_number[i]);
        }
        else { //이미 저장되어있음
            findRoom(room_number[i]);
        }
    }

    return answer;
}