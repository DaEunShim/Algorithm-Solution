#include <iostream>

using namespace std;

int num[200001];
int arr[100001];
int checktwo[200001] = { 0 };

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		num[i] = i;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &arr[i]);
		num[arr[i]] = -1;
	}
	for (int i = m - 1; i >= 0; i--) {
		int temp = arr[i];
		if (checktwo[temp] > 0) arr[i] = -1;
		checktwo[temp] = 1;
	}
	for (int i = m - 1; i >= 0; i--) {
		if (arr[i] > 0) printf("%d\n", arr[i]);
	}
	for (int i = 0; i <= n; i++) {
		if (num[i] > 0) printf("%d\n", num[i]);
	}
	return 0;
}