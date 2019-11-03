#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(20000);

int cut(int s, int e)
{
	int mid = (s + e) / 2;

	if (s == e)
		return v[e];

	int left_max = cut(s, mid);
	int right_max = cut(mid + 1, e);

	int mid_max = 2 * (*min_element(v.begin() + mid, v.begin() + mid + 1 + 1));
	int left = 0, right = 0;

	int i = 1;
	while ((mid - left >= s) || (mid + right <= e))
	{
		if (i % 2)
		{
			if (mid + right <= e)
				right++;
		}
		else if (mid - left >= s)
			left++;
		if (mid_max < (2 + right + left) * (*min_element(v.begin() + mid - left, v.begin() + mid + right + 2)))
			mid_max = (2 + right + left) * (*min_element(v.begin() + mid - left, v.begin() + mid + right + 2));
		i++;
	}

	int _max = max(left_max, right_max);
	_max = max(_max, mid_max);

	return _max;
}

int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		int num;
		cin >> num;
		for (int i = 0; i < num; i++)
			cin >> v[i];
		cout << cut(0, num - 1) << endl;
	}
}