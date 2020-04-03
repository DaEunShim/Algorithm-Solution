#include <iostream>

using namespace std;

int main(void) {
	int n[5];
	int sum = 0, a = 0, max = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a;
			sum += a;
		}
		n[i] = sum;
		if (n[i] > n[max]) max = i;
		sum = 0;
	}
	cout << max + 1 <<" "<< n[max];
	return 0;

}