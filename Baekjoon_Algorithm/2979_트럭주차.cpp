#include <iostream>
#include <algorithm>

using namespace std;

int arr[101] = { 0 };
int main() {
	int a, b, c, total = 0, maxT = 0, minT = 101;
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		maxT = max(maxT, y);
		minT = min(minT, x);
		for (int j = x; j < y; j++)
			arr[j]++;
	}
	for (int i = minT; i < maxT; i++) {
		if (arr[i] == 1) total += a;
		else if (arr[i] == 2) total += b * 2;
		else if (arr[i] == 3) total += c * 3;
	}
	cout << total << endl;
	return 0;
}