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
		//������ ������ ����
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
		//���� ����� ���� �̸� ����
		for (int i = 0; i < T; i++)
			cin >> arr[i];

		//Ȯ��
		float dp[n][d] = { 0 };
		//���� �־��� ���� (1�̸� �־��� 0�̸� ������)
		int yest[n] = { 0 };

		//ù° ���� ����ģ ����
		for (int i = 0; i < n; i++)
			if (v[p][i])
			{
				dp[i][1] = 1.0 / (float)v_num[p];
				yest[i] = 1;
			}

		for (int i = 2; i < d + 1; i++)
		{
			int tom[n] = { 0 };
			//���� �־��� ������ Ž��
			for (int j = 0; j < n; j++)
			{
				//���� j������ �־��ٸ�
				if (!yest[j])
					continue;

				//���� ���� ������ �̵��� �� �ִ� ��츦 ��
				for (int k = 0; k < n; k++)
				{
					if (!v[j][k])
						continue;
					//dp[���� �� ����][���ó�¥] = dp[���� �ִ� ����][���� ��¥] * 1/v_num[���� �ִ� ����]
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