#include <iostream>

using namespace std;

int arr[4] = { 0 };
int main(void) {
	int minimum=0;
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
	arr[2] = arr[2] - arr[0];
	arr[3] = arr[3] - arr[1];
	minimum = arr[0];
	for (int i = 0; i<4; i++)
		if (minimum>arr[i])
			minimum = arr[i];
	cout << minimum;
	return 0;
}