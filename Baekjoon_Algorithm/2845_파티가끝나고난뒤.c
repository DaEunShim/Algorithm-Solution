#include <stdio.h>
int main(void) {
	int P, L,i,num=0;
	int a[5];
	scanf_s("%d", &L); 
	scanf_s("%d", &P); 
	for(i=0;i<5;i++){
		scanf_s("%d", &a[i]);
	}
	num = P*L;
	for (i = 0; i < 5; i++) {
		printf("%d ", a[i]-num);
	}
	return 0;
}