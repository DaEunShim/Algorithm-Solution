#include <iostream>

using namespace std;

int card[101];
int main(void) {
	int n, m, gap=999999999,result;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> card[i];
	for (int i = 0; i < n - 2; i++){
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = card[i] + card[j] + card[k];
				if (m - sum < 0) continue;
				if (m - sum < gap) {
					gap = m - sum;
					result = sum;
				}
			}
		}
	}
	cout << result << endl;
	return 0;
}