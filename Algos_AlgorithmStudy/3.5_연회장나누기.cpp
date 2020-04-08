#include <iostream>

using namespace std;

int arr[100][100];
int set[100] = { 0 };
int cut = 0;
int ans[100];

int partition(int set[], int set_size) {
	for (int i = 0; i < set_size; i++) {
		for (int j = 0; j < i; i++) {
			if (arr[i][j] == 1) ans[i]++;
		}
	}
	for (int i = 0; i < set_size; i++) {
		if (ans[i] < cut) cut = ans[i];
	}
	return cut;
}
bool half(int set[], int set_size) {
	int cnt = 0;
	for (int i = 0; i < set_size; i++) 
		if (set[i] == 0) cnt++;
	if (cnt != set_size / 2) return false;
	return true;
}
void subset(int set[], int set_size, int n, int index) {
	if (index == n) {		
		if(half(set,set_size)==true) partition(set,  set_size);
		return;
	}
	set[set_size] = index;
	subset(set, set_size, n, index + 1);
	subset(set, set_size + 1,  n, index + 1);
}

int main() {
	int n, m, k;
	cout << "input n: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> k;
			arr[i][k] = 1;
		}
	}
	subset(set, 0, n, 0);
	cout << "cut: " << cut << endl;
	return 0;
}