#include <iostream>

using namespace std;

int main(void) {
	string  a, b;
	int max,min; //max�� 5�� 6���� �ٲ۰�, min�� 6�� 5�� �ٲ۰�
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++)
		if (a[i] == '6') a[i] = '5';
	for (int i = 0; i < b.length(); i++)
		if (b[i] == '6') b[i] = '5';
	min = atoi(a.c_str()) + atoi(b.c_str());
	for (int i = 0; i < a.length(); i++)
		if (a[i] == '5') a[i] = '6';
	for (int i = 0; i < b.length(); i++)
		if (b[i] == '5') b[i] = '6';
	max = atoi(a.c_str()) + atoi(b.c_str());

	cout << min <<" "<< max << endl;
	return 0;
}