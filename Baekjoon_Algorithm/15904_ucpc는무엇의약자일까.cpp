#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(void) {
	char a[1001];
	char b[5] = "UCPC";
	int ck = 0;
	scanf("%[^\n]", a);
	for (int i = 0; a[i] != NULL; i++) {
		if (a[i] == b[ck]) ck++;
	}
	if (ck == 4) printf("I love UCPC");
	else printf("I hate UCPC");
	return 0;
}