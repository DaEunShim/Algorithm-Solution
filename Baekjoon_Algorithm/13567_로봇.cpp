#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int M, n;
	int move, turn=0,t;
	int x = 0, y = 0;
	string st;
	string MOVE = "MOVE";
	string TURN = "TURN";
	scanf("%d %d",&M,&n);
	for (int i = 0; i < n; i++) {
		cin >> st;
		if (st.compare(MOVE)==0) {
			scanf("%d", &move);
			if (turn == 0) { x += move; }
			else if (turn == 1) { y += move; }
			else if (turn == 2) { x -= move; }
			else if (turn == 3) { y -= move; }
		}
		//µ¿0 ºÏ1 ¼­2 ³²3
		else if (st.compare(TURN) == 0) {
			scanf("%d", &t);
			if (!t) turn = (turn + 1) % 4;
			else {
				if (!turn) turn = 4;
				turn = (turn - 1) % 4;
			}
		}
		if (x<0 || y<0 || x>M || y>M) {
			break;
		}
	}
	if (x<0 || y<0 || x>M || y>M) printf("-1");
	else printf("%d %d", x, y);
	return 0;
}