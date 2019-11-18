#include <iostream>

using namespace std;

int t[51];
int main(void){
	int n;
	cin >> n;
	for (int i = 1; i <= 50; i++)
		t[i] = i * (i + 1) / 2;
	while (n--) {
		int k, i,flag=0;
		cin >> k;
		for (i = 0; i <= 50; i++) 
			if (t[i] > k) break;
		i--;
		for (int j = 1; j <= i; j++) {
			for (int x = j; x <= i; x++) {
				for (int y = x; y <= i; y++)
					if (t[j] + t[x] + t[y] == k) {
						flag = 1;
						break;
					}
			}
		}
		if (flag) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
