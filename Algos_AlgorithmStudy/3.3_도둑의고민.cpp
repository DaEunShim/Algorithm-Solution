#include <iostream>
using namespace std;

void buggler(int set[], int set_size, int weight, int value, int n, int index);

struct thing {
	int number;
	int value;
	int weight;
};
thing all[50] = { 0, };
int ans[50] = { 0, };

int max_value = 0;
int max_size = 0;
int num, m_w;

int main() {
	int set[50];
	cin >> num >> m_w;
	for (int i = 0; i < num; i++) {
		all[i].number = i;
		cin >> all[i].value;
	}
	for (int i = 0; i < num; i++)
		cin >> all[i].weight;

	buggler(set, 0, 0, 0, num, 0);

	printf("Max value : %d\n", max_value);
	for (int i = 0; i < max_size; i++) {
		cout << ans[i] << " ";
	}
	printf("\n");

	return 0;
}

void buggler(int set[], int set_size, int weight, int value, int n, int index) {
	if (index == n) {
		if ((max_value < value) && (m_w >= weight)) {
			max_value = value;
			max_size = set_size;
			for (int i = 0; i < set_size; i++) {
				ans[i] = set[i];
			}
		}
		return;
	}
	buggler(set, set_size, weight, value, n, index + 1);   //안 가져가는 경우

	set[set_size] = all[index].number;
	weight += all[index].weight;
	value += all[index].value;
	buggler(set, set_size + 1, weight, value, n, index + 1);   //가져가는 경우
}