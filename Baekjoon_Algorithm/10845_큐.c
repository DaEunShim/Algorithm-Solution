#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int queue[10000];

int main(void) {
	int n,i,j,front=-1,back=-1;
	char st[6];
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s",st);
		if (strcmp(st, "push") == 0) {
			scanf("%d", &j);
			queue[++back] = j;
		}
		else if (strcmp(st, "pop") == 0) printf("%d\n", back == front ? -1:queue[++front]);
		else if (strcmp(st, "size") == 0) printf("%d\n", back - front);
		else if (strcmp(st, "empty") == 0) printf("%d\n", back == front ? 1 : 0);
		else if (strcmp(st, "front") == 0) printf("%d\n", back == front ? -1:queue[front + 1]);
		else if (strcmp(st, "back") == 0) printf("%d\n", back == front ? -1:queue[back]);
	}


	return 0;
}




