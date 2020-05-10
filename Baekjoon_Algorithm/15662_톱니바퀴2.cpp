#include <iostream>
#include <vector>
using namespace std;

vector<int> gear[1001];
int n, k, num, dir; // 톱니바퀴 개수, 회전횟수, 회전시킨 톱니 번호, 방향(1:시계,-1:반시계)

void rotate(int number, int direction) {
	if (direction == 1) {//시계방향이면 index + 1
		int temp = gear[number][7];
		for (int i = 7; i > 0; i--)
			gear[number][i] = gear[number][i - 1];
		gear[number][0] = temp;
	}
	else if (direction == -1) {//반시계방향이면 index - 1
		int temp = gear[number][0];
		for (int i = 0; i < 7; i++)
			gear[number][i] = gear[number][i + 1];
		gear[number][7] = temp;
	}
}

void left(int leftgear, int direction) {
	if (leftgear == 0) return;
	if (gear[leftgear][2] != gear[leftgear + 1][6]) { //다른 극
		left(leftgear - 1, direction * -1);
		rotate(leftgear, direction * -1);
	}
}

void right(int rightgear, int direction) {
	if (rightgear == n + 1) return;
	if (gear[rightgear][6] != gear[rightgear - 1][2]) { //다른 극
		right(rightgear + 1, direction * -1);
		rotate(rightgear, direction * -1);
	}

}

int main(void) {
	// N극: 0, S극:1
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < 8; j++)
			gear[i].push_back(input[j] - '0');
	}

	cin >> k;
	while (k--) {
		cin >> num >> dir;

		left(num - 1, dir);
		right(num + 1, dir);
		rotate(num, dir);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (gear[i][0] == 1) ans++;

	cout << ans << endl;
	return 0;
}