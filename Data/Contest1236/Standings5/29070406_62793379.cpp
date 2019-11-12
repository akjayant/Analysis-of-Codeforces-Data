#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long int lint;

lint quickmi(lint a, lint b, lint mode)
{
	lint sum = 1;
	a = a % mode;
 
	while (b > 0) {
		if (b % 2 == 1)	
			sum = (sum * a) % mode;
 
		b /= 2;
		a = (a * a) % mode;
	}
	return sum;
}

lint mod = 1000000007;
int main()
{
	
	int a, b; while(~scanf("%d%d", &a, &b)) {
		lint x = quickmi(2, b, mod) - 1;
		lint y = quickmi(x, a, mod);
		cout << y << endl;
	}
	return 0;
}
