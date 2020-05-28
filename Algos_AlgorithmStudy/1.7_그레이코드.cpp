#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;

vector<string> grayCode(int cnt, vector<string> code)
{
	vector<string> _code;

	if (cnt == n)
		return code;

	for (int i = 0; i < code.size(); i++)
		_code.push_back("0" + code[i]);

	for (int i = code.size() - 1; i >= 0; i--)
		_code.push_back("1" + code[i]);

	return grayCode(cnt + 1, _code);
}

int main()
{
	cin >> n;

	vector<string> code = { "0", "1" };
	vector<string> ans = grayCode(1, code);

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
}