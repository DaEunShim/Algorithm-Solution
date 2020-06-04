#include <iostream>

using namespace std;

int arr[51];
int n, money;
int ans(int arr[], int money, int n) {
	int i, t, cnt = 0;
	if (n == 1) {
		if (money % arr[0] == 0) return 1;
		else return 0;
	}
	t = money / arr[n - 1];
	for (i = 0; i <= t; i++)
		cnt += ans(arr, money - arr[n - 1] * i, n - 1);
	return cnt;
}
int main() {
	cout << "input number of bills: ";
	cin >> n;
	cout << "input bills: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "input money: ";
	cin >> money;
	cout << ans(arr, money, n) << endl;
	return 0;
}