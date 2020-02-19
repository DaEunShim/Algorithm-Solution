#include <iostream>

using namespace std;

int main(void) {
	int asc = 0,des=0;
	for(int i=1;i<=8;i++) {
		int x;
		cin >> x;
		if (x == i) asc++;
		else if (x == 9-i) des++;
	}
	if (asc == 8) cout << "ascending";
	else if (des == 8) cout << "descending";
	else cout << "mixed";
	return 0;
}