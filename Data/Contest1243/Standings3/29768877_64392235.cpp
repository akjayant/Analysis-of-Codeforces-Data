#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 10;

long long n,sq,stk[maxn];
int top;

int main()
{
	cin >> n;
	sq = sqrt(n) + 1;
	while((sq-1) * (sq-1) >= n)
		sq--;
	for(int i = 2; i <= sq; i++)
	{
		if(n % i == 0)
			stk[top++] = i;
		while(n % i == 0)
			n = n / i;
	}
	if(n != 1)
		stk[top++] = n;
	if(top == 1)
		cout << stk[0] << endl;
	else
		cout << 1 << endl;
	return 0;
}

