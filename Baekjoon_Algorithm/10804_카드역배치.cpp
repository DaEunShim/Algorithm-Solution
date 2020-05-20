#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> card(21);
int cnt = 10;
int main(void) {
	for (int i = 1; i <= 20; i++)
		card[i] = i;
	while (cnt--) {
		int a, b;
		cin >> a >> b;
		reverse(card.begin()+a, card.begin()+b+1);
	}
	for (int i = 1; i <= 20; i++)
		cout<<card[i]<<" ";
	cout << endl;
	return 0;
}