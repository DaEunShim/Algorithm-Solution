#include <iostream>

using namespace std;

int arr[100];

void check(int arr[], int n) {
	int p[100] = { 0 };
	for (int i = 0; i < n; i++) {
		p[arr[i]]++;
	}
	for (int i = 0; i < n; i++) {
		//printf("%d %d ", p[i], arr[i]);
		if (p[i] != arr[i]) return; 
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void rperm(int arr[], int len, int n) {
	int i;
	if (len == n) {
		check(arr, n);
		return;
	}
	for (i = 0; i < n; i++) {
		arr[len] = i;
		rperm(arr, len + 1, n);
	}
}
int main() {
	int n;
	cin >> n;
	rperm(arr, 0, n);
	return 0;
}