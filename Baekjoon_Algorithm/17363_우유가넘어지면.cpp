#include<iostream>
#include<string>
using namespace std;

int arr[101][101];
char milk[10] = {46,79,45,124,47,92,94,60,118,62};
char chg[10] = {46,79,124,45,92,47,60,118,62,94};
int main(void) {
	int x, y;
	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < y; j++) {
			char c = s[j];
			for (int k = 0; k < 10; k++) {
				if (milk[k] == c) {
					arr[y-1-j][i] = chg[k];
					break;
				}
			}
		}
	}
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++)
			cout << (char)arr[i][j];
		cout << endl;
	}
	return 0;
}