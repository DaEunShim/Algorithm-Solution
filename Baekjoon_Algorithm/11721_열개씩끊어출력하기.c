#include <stdio.h>
#include <string.h>
int main(void) {
	char a[101] = { 0 };
	int i,n;
	gets(a);
	n = strlen(a);
	for (i = 0; i < n; i++) {
		printf("%c", a[i]);
		if ((i + 1) % 10 == 0) printf("\n");
	}
	return 0;
}