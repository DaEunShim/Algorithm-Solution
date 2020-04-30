#include <iostream>

using namespace std;

int arr[10000];
int main() {
	int n, last=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i != 0 && arr[i] > arr[i - 1]) last = 1;
	}
	if (last == 0) {
		cout << "-1";
		return 0;
	}
	int i = n - 1;
	for (; i >= 0; i--) 
		if (arr[i - 1] < arr[i]) break;
	int j = n - 1;
	for (; j >= i; j--)
		if (arr[j] > arr[i - 1]) break;
	swap(arr[i - 1], arr[j]);
	for (int k = 0; k < i; k++)
		cout << arr[k]<<" ";
	for (int k = n-1; k >= i; k--)
		cout << arr[k]<<" ";
	return 0;
}