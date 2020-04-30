#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	printf("\n");
	while (next_permutation(arr + 1, arr + n + 1)) {
		for (int i = 1; i <= n; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	return 0;
}