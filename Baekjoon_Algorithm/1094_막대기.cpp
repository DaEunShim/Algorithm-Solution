#include <iostream>

using namespace std;

int main(void) {
	int a, stick=0, sum = 0;
	cin >> a;
	for (int i = 64; i > 0; i /= 2) {
		if (i > a) continue;
		else if (i == a) {
			stick = 1;
			break;
		}
		if (sum + i <= a) {
			sum += i;
			stick++;
		}
	}
	cout << stick << endl;
	return 0;
}