#include <iostream>

using namespace std;

int Rev(int n) {
	int rev = 0;
	while(n > 0) {
		rev *= 10;
		rev += n % 10;
		n /= 10;
	}
	return rev;
}
int main(void) {
	int X, Y;
	cin >> X >> Y;
	cout << Rev(Rev(X) + Rev(Y));
	return 0;
}