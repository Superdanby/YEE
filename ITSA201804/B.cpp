#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int cases;
	cin >> cases;
	while(cases--)
	{
		int stack = 0;
		string inp;
		cin >> inp;
		for(auto x: inp)
		{
			if(x == '(')
				++stack;
			else
				--stack;
			if(stack < 0)
				break;
		}
		if(!stack)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
