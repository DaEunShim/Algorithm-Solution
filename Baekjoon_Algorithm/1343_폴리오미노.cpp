#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
char board[501];

int main(void) {
	char A[] = "AAAA";
	char B[] = "BB";
	char X4[] = "XXXX";
	char X2[] = "XX";
	cin >> board;
	char *p;
	while ((p = strstr(board, X4))) {
		strncpy(p, A,4);
	}
	while ((p = strstr(board, X2))) {
		strncpy(p,B,2);
	}
	int ck = 0;
	for (int i = 0; board[i]; i++) {
		if (board[i] == 'X') {
			ck = 1;
			break;
		}
	}
	if (ck) cout << "-1" << endl;
	else cout<<board<<endl;
	return 0;
}