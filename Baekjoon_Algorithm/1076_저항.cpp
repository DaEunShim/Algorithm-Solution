#include <iostream>
#include <utility>
#include <string>
using namespace std;

int main() {
	int j;
	long long r=0;
	string s[] = { "black" ,"brown","red","orange","yellow","green","blue","violet","grey","white"};
	for (int i = 0; i < 3; i++) {
		string color;
		cin >> color;
		for (j = 0; j < 10; j++) {
			if (color==s[j]) break;
		}
		switch (i) {
		case 0: r += j * 10; break;
		case 1: r += j; break;
		case 2: while (j--) { r *= 10; } break;
		}
	}
	cout << r<<endl;
	return 0;
}