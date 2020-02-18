#include <iostream>

using namespace std;

int main(void) {
	int ori,cnt=0,prev,newn=-1;
	cin >> ori;
	prev = ori;
	while (ori != newn) {
		newn = (prev % 10) * 10 + (prev / 10 + prev % 10) % 10;
		prev = newn;
		cnt++;
	}
	cout << cnt;
	return 0;
}