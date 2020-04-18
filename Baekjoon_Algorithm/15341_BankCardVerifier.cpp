#include <iostream>
using namespace std;

int main() {
	while (1) {
		char nums[17];
		int nums_int[17];
		int check = 0;
		cin >> nums >> nums + 4 >> nums + 8 >> nums + 12;
		int flag = 0;
		for (int i = 0; i < 16; i++) {
			if (nums[i] != '0') {
				flag = 1;
				break;
			}
		}
		if (flag == 0) break;
		for (int i = 0; i < 16; i++) {
			nums_int[i] = nums[i] - '0';
			if (i % 2 == 0) {
				nums_int[i] *= 2;
				while (nums_int[i] > 9) nums_int[i] -= 9;
			}
			check += nums_int[i];
		}

		if (check % 10 == 0) cout << "Yes" << endl;
		else cout << "No" << endl;

	}


	return 0;
}