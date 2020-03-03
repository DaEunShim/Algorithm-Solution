#include <iostream>

using namespace std;

int arr[10001] = { 0 };
int main() {
	for (int i = 1; i <= 10000; i++) {
		if (i < 10) arr[i + i] = 1;
		else if (i < 100) arr[i / 10 + i % 10 + i] = 1;
		else if (i < 1000) arr[i / 100 + (i % 100) / 10 + i % 10 + i] = 1;
		else if (i < 10000) arr[i / 1000 + (i % 1000) / 100 + (i % 100) / 10 + i % 10 + i] = 1;
	}
	for (int i = 1; i <= 10000; i++)
		if (!arr[i]) printf("%d\n", i);
	return 0;
}