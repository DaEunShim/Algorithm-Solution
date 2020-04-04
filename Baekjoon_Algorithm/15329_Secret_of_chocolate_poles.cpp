#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int l, k;
long long white_end[101] = { 0, };
long long black_end[101] = { 0, };

int main() {
	scanf("%d %d", &l, &k);
	black_end[1] = 1;
	black_end[k] = 1;
	for (int i = 2; i <= l; i++) {
		if (black_end[i - 1] > 0)  //검정으로끝나고 위에 흰색
			white_end[i] += black_end[i - 1];
		if (white_end[i - 1] > 0)  //흰색위에 검정
			black_end[i] += white_end[i - 1];
		if (i - k > 0 && white_end[i - k]>0) {  //두꺼운덩어리
			black_end[i] += white_end[i - k];
		}
	}

	long long sol = 0;
	for (int i = 1; i <= l; i++) {
		sol = sol += black_end[i];
	}
	printf("%ld\n", sol);
	return 0;
}