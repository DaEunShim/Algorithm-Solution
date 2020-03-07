#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int stack[10000];

int main(void) {
	int n, i, j, top = -1;
	char st[6];
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s", st);
		if (strcmp(st, "push") == 0) {
			scanf("%d", &j);
			stack[++top] = j;
		}
		else if (strcmp(st, "pop") == 0) printf("%d\n", top<0 ? -1 : stack[top--]);
		else if (strcmp(st, "size") == 0) printf("%d\n", top+1);
		else if (strcmp(st, "empty") == 0) printf("%d\n", top<0 ? 1 : 0);
		else if (strcmp(st, "top") == 0) printf("%d\n", top<0 ? -1 : stack[top]);
	}
	return 0;
}