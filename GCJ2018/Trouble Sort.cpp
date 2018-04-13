#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++)
	{
		int nums;
		scanf("%d", &nums);
		vector<int> odd, even;
		int inp;
		for (int j = 0; j < nums; j++)
		{
			scanf("%d", &inp);
			if (j & 1)
				even.push_back(inp);
			else
				odd.push_back(inp);
		}
		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end());
		bool flag = true;
		for (int j = 0; j < nums - 1; j++)
		{
			if (j & 1)
			{
				if (odd[j / 2 + 1] < even[j / 2])
				{
					printf("Case #%d: %d\n", i, j);
					flag = false;
					break;
				}
			}
			else
			{

				if (even[j / 2] < odd[j / 2])
				{
					printf("Case #%d: %d\n", i, j);
					flag = false;
					break;
				}
			}
		}
		if (flag)
			printf("Case #%d: OK\n", i);
	}
	return 0;
}
