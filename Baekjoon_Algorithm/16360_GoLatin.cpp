#include <iostream>
#include <string>
using namespace std;

char eng[] = { 'a', 'i', 'y', 'l','n','e', 'o', 'r', 't', 'u', 'v', 'w' };
string pLatin[] = { "as", "ios", "ios", "les", "anes", "anes", "os", "res", "tas", "us", "ves", "was" };

void printLatin(char latin[], int len, string plat) {
	for (int k = 0; k < len; k++) printf("%c", latin[k]);
	cout << plat << endl;
	return;
}

int main() {
	int tc;
	char latin[30];
	cin >> tc;
	while (tc--) {
		bool flag = false;
		int i;
		cin >> latin;
		for (i = 0;; i++) {
			if (latin[i] == '\0') break;
		}
		for (int j = 0; j < 12; j++) {
			if (latin[i - 1] == eng[j]) {
				if (j == 5) {
					if (latin[i - 2] == 'n') {
						printLatin(latin, i - 2, pLatin[j]);
						flag = true;
					}
					break;
				}
				printLatin(latin, i - 1, pLatin[j]);
				flag = true;
				break;
			}
		}

		if (!flag) {
			printLatin(latin, i, pLatin[9]);
		}

	}
	return 0;
}