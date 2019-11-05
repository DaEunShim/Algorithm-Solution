#include <iostream>

using namespace std;

int dol[150];

int main(void){
	int N;
	cin >> N;
	while (N--) {
		int x = 0, y = 0;
		int m, n, cnt = 0;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int temp;
			cin >> temp;
			x = x * 10 + temp;
		}
		for (int i = 0; i < m; i++) {
			int temp;
			cin >> temp;
			y = y * 10 + temp;
		}
		for (int i = m-1; i < n+m-1; i++) cin >> dol[i];
		for (int i = 0; i < m - 1; i++) dol[i] = dol[n+i];
		
		for (int i = 0; i < n; i++) {
			int num = 0;
			for (int j = 0; j < m; j++) {
				num = num * 10 + dol[i + j];
			}
			if (x <= num && num <= y) cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}

