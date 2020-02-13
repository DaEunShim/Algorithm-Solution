#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		int N, min=0;
		int arr[10000],minArr[10000];
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		sort(&arr[0], &arr[N]);
		int i;
		for(i = 0; i < N; i++) {
			minArr[i] = arr[i * 2];
		}

		i--;
		if (N % 2) N--; //È¦¼ö
		for (int j = N * 2; j > 0; j--,i++) {
			minArr[i] = arr[j/2];
		}
		if (N % 2) N++; //È¦¼ö

		for (int i = 0; i < N; i++) {  //Ãâ·ÂÀ§ÇÔ
			cout << minArr[i] << " ";
		}

		for (int j = 0; j < N-1; j++) {
			min = max(min, abs(minArr[j] - minArr[j + 1]));
		}
		cout << min;
	}
	return 0;
}
/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
int t, n;
int tong[10001] = { 0, };
int ans[10001] = { 0, };
cin >> t;
while (t--) {
cin >> n;
for (int i = 0; i < n; i++) cin >> tong[i];
sort(tong, tong + n);
for (int i = 0; i < n; i++) {
int temp = i / 2;
if (i % 2 == 0)
ans[temp] = tong[n - i - 1];
else
ans[n - temp -1] = tong[n - i - 1];
}
int level = 0;
for (int i = 0; i < n - 1; i++) {
int temp = ans[i] - ans[i + 1];
if (temp < 0) temp = -temp;
if (temp >= level) level = temp;
}
cout << level <<endl;
}

return 0;
}*/