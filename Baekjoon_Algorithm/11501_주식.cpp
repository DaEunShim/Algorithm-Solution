#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		long long value=0;
		scanf("%d", &N);
		vector<int> arr(N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}
		int max = arr[N - 1];
		for (int n = N - 2; n >= 0; n--) {
			if (arr[n] < max)
				value += (long long)(max - arr[n]);
			else max = arr[n];
		}
		printf("%ld\n", value);
	}
	return 0;
}