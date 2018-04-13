#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	double height, weight, age;
	double hat, clothes, dress;
	int stop;
	while(scanf("%lf %lf %lf", &height, &weight, &age) == 3)
	{
		hat = weight / height * 41.2;
		clothes = height * weight / 634.4 + max(0.0, double(int(age) / 5 - 6) * 0.15);
		dress = weight * 0.4 + max(0.0, double(int(age) / 2 - 14) * 0.25);
		printf("%.2lf %.2lf %.2lf\n", hat, clothes, dress);
		scanf("%d", &stop);
		if(stop)
			break;
	}
	return 0;
}
