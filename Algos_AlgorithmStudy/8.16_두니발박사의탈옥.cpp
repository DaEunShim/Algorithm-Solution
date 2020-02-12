#include <iostream>
using namespace std;

int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		int n, d, p;
		cin >> n >> d >> p;

		int v[n][n], v_num[n] = { 0 };
		//마을의 연결을 받음
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> v[i][j];
				if (v[i][j])
					v_num[i]++;
			}

		int T;
		cin >> T;
		int arr[T];
		//답을 출력할 마을 이름 받음
		for (int i = 0; i < T; i++)
			cin >> arr[i];

		//확률
		float dp[n][d] = { 0 };
		//어제 있었던 마을 (1이면 있었고 0이면 없었음)
		int yest[n] = { 0 };

		//첫째 날에 도망친 마을
		for (int i = 0; i < n; i++)
			if (v[p][i])
			{
				dp[i][1] = 1.0 / (float)v_num[p];
				yest[i] = 1;
			}

		for (int i = 2; i < d + 1; i++)
		{
			int tom[n] = { 0 };
			//어제 있었던 마을을 탐색
			for (int j = 0; j < n; j++)
			{
				//어제 j마을에 있었다면
				if (!yest[j])
					continue;

				//어제 갔던 데에서 이동할 수 있는 경우를 셈
				for (int k = 0; k < n; k++)
				{
					if (!v[j][k])
						continue;
					//dp[오늘 온 마을][오늘날짜] = dp[어제 있던 마을][어제 날짜] * 1/v_num[어제 있던 마을]
					dp[k][i] += dp[j][i - 1] * 1.0 / (float)v_num[j];
					tom[k] = 1;
				}
			}
			for (int t = 0; t < n; t++)
				yest[t] = tom[t];
		}

		for (int i = 0; i < T; i++)
			cout << dp[i][d] << " ";
	}
}