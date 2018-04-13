// wrong
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cases, limit;
	string seq;
	cin >> cases;
	for (int j = 0; j < cases; j++)
	{
		cin >> limit >> seq;
		vector<int> C;
		int cnt = 0;
		for (int i = seq.length() - 1; i >= 0; i--)
		{
			if (seq[i] == 'C')
				cnt <<= 1;
			else
				++cnt;
			if (seq[seq.length() - i - 1] == 'C')
				C.push_back(seq.length() - i - 1);
		}
		int moves = 0;
		// cout << limit << " " << seq << "\n";
		// cout << cnt << "\t";
		// for (auto x:C)
		// 	cout << x << " ";
		// cout << "\n";
		while (cnt > limit && !C.empty())
		{
			if (uint(C.back()) < seq.length() - 1)
			{
				cnt -= (1 << (C.size() - 1));
				++moves;
				++C.back();
			}
			else
				C.pop_back();
		}
		if(cnt <= limit)
			cout << "Case #" << j + 1 << ": " << moves << "\n";
		else
			cout << "Case #" << j + 1 << ": IMPOSSIBLE\n";
	}
	return 0;
}
