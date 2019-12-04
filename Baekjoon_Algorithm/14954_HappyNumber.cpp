#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void ishappy(int n);
int reverse_newn(int n);

int main(void) {
	int n;
	scanf("%d", &n);
	ishappy(n);
	return 0;
}

void ishappy(int n) {
	int newn = 0, prev = n;
	int visit[1000];
	for (int i = 0;; i++) {
		while (prev) {
			newn += (prev % 10)*(prev % 10);
			prev /= 10;
		}
		visit[i] = newn;
		if (newn == 1) {
			printf("HAPPY");
			return;
		}
		for (int j = 0; j < i; j++) {
			if (newn == visit[j] || reverse_newn(newn) == visit[j]) {
				printf("UNHAPPY");
				return;
			}
		}
		prev = newn;
		newn = 0;
	}
}
int reverse_newn(int n) {
	int r = 0;
	while (n != 0) {
		r *= 10;
		r += (n % 10);
		n /= 10;
	}
	return r;
}