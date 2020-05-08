#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    for (int i = 0; i < moves.size(); i++) {
        // board의 moves[i]번째
        for (int j = 0; j < board.size(); j++) {
            if (board[j][moves[i] - 1]) {
                if (!st.empty()) {
                    int top = st.top();
                    st.push(board[j][moves[i] - 1]);
                    board[j][moves[i] - 1] = 0;
                    if (top == st.top()) {
                        answer += 2;
                        st.pop();
                        st.pop();
                    }
                }
                else {
                    st.push(board[j][moves[i] - 1]);
                    board[j][moves[i] - 1] = 0;
                }
                break;
            }
        }
    }

    return answer;
}