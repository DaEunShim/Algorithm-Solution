#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int n = prices.size();
    for (int i = 0; i < n - 1; i++) {
        int low = n - 1;
        for (int j = i + 1; j < n; j++) {
            if (prices[i] > prices[j]) {
                low = j;
                break;
            }
        }
        answer.push_back(low - i);
    }
    answer.push_back(0);

    return answer;
}