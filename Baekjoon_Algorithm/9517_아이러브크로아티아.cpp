#include<iostream>

using namespace std;

int main() {
	int K, N, T;
	char Z;
	int time = 0;
	cin >> K >> N;
	int num = K;
	while(N--) {
		cin >> T >> Z;
		time += T;
		if (time>=210) break;
		if (Z == 'T') num++;
		if (num > 8) num %= 8;
	}
	cout << num;
	return 0;
}