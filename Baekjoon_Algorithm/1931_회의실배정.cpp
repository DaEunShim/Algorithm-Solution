#include <iostream>
#include <algorithm>

using namespace std;
struct str{
	int start;
	int end;
};

bool cmp(const str& a,const str& b){
	if (a.end == b.end) return a.start < b.start;
	else return a.end < b.end;
}

str a[100000];
int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i].start >> a[i].end;
	}
	sort(a, a + N,cmp);
	int time = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		if (time <= a[i].start) {
			time = a[i].end;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}