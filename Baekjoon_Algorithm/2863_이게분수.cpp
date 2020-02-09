#include <iostream>

using namespace std;

double arr[5];
int main(void) {
	double maxValue = 0, temp = 0;
	int maxCnt = 0;
	cin >> arr[1] >> arr[2] >> arr[3] >> arr[4];
	for (int i = 0; i < 4; i++) {
		switch (i) {
		case 0: temp = arr[1] / arr[3] + arr[2] / arr[4]; break;
		case 1: temp = arr[3] / arr[4] + arr[1] / arr[2]; break;
		case 2: temp = arr[4] / arr[2] + arr[3] / arr[1]; break;
		case 3: temp = arr[2] / arr[1] + arr[4] / arr[3]; break;
		}
		if (temp > maxValue) {
			maxCnt = i;
			maxValue = temp;
		}
	}
	cout << maxCnt << endl;
	return 0;
}