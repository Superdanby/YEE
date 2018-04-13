#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int sticks;
	cin >> sticks;
	int length = 0;
	vector<int> vec(sticks, 0);
	for(int i = 0; i < sticks; i++)
	{
		cin >> vec[i];
		length += vec[i];
	}
	if(length % 4 != 0)
	{
		cout << "no\n";
		return 0;
	}
	length = length / 4;
	sort(vec.begin(), vec.end());
	for (int i = 0; i < 4; i++)
	{
		int test = 0;
		for(int j = vec.size() - 1; j >= 0; j--)
		{
			if(test + vec[j] <= length)
			{
				test += vec[j];
				vec[j] = 0;
			}
		}
		if(test != length)
		{
			cout << "no\n";
			return 0;
		}
	}
	cout << "yes\n";
	return 0;
}
