#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	while(cases--)
	{
		int month, date;
		cin >> month >> date;
		switch (month) {
			case 1:
				if(date < 21)
					cout << "Capricorn\n";
				else
					cout << "Aquarius\n";
				break;
			case 2:
				if(date < 19)
					cout << "Aquarius\n";
				else
					cout << "Pisces\n";
				break;
			case 3:
				if(date < 21)
					cout << "Pisces\n";
				else
					cout << "Aries\n";
				break;
			case 4:
				if(date < 21)
					cout << "Aries\n";
				else
					cout << "Taurus\n";
				break;
			case 5:
				if(date < 22)
					cout << "Taurus\n";
				else
					cout << "Gemini\n";
				break;
			case 6:
				if(date < 22)
					cout << "Gemini\n";
				else
					cout << "Cancer\n";
				break;
			case 7:
				if(date < 23)
					cout << "Cancer\n";
				else
					cout << "Leo\n";
				break;
			case 8:
				if(date < 24)
					cout << "Leo\n";
				else
					cout << "Virgo\n";
				break;
			case 9:
				if(date < 24)
					cout << "Virgo\n";
				else
					cout << "Libra\n";
				break;
			case 10:
				if(date < 24)
					cout << "Libra\n";
				else
					cout << "Scorpio\n";
				break;
			case 11:
				if(date < 23)
					cout << "Scorpio\n";
				else
					cout << "Sagittarius\n";
				break;
			case 12:
				if(date < 22)
					cout << "Sagittarius\n";
				else
					cout << "Capricorn\n";
				break;
		}
	}
	return 0;
}
