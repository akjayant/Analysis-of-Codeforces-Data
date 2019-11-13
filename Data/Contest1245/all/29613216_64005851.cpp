#include <bits/stdc++.h>

using namespace std;

namespace CF
{
	const int MAXN = 100000, P = 1000000007;
	int F[MAXN + 1];
	char S[MAXN + 2];
	
	void work()
	{
		scanf("%s", S + 1);
		int n = strlen(S + 1);
		for (int i = 1; i <= n; i++)
			if (S[i] == 'w' || S[i] == 'm')
				return void(puts("0"));
		F[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (S[i - 1] == S[i] && (S[i] == 'u' || S[i] == 'n'))
				F[i] = (F[i - 1] + F[i - 2]) % P;
			else
				F[i] = F[i - 1];
		}
		printf("%d\n", F[n]);
	}
}

int main()
{
	CF::work();
	return 0;
}