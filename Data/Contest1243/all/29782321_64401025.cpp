#include <bits/stdc++.h>

using namespace std;
const int MAXSQRT = 1000100;
bool np[MAXSQRT];
long long n, p;
int cnt;

int main()
{
	scanf("%lld", &n);
	for(int i = 2, j; i < MAXSQRT; ++i)
		if(!np[i])
		{
			if(n % i == 0)
				cnt++, p = i;
			while(n % i == 0)
				n /= i;
			for(j = i; j < MAXSQRT; j += i)
				np[j] = true;
		}
	if(n != 1)
		cnt++, p = n;
	if(cnt != 1)
		printf("1\n"), exit(0);
	else
		printf("%lld\n", p);
}