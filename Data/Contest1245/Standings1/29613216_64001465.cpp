#include <bits/stdc++.h>

using namespace std;

namespace CF
{
	const int MAXN = 100;
	char S[MAXN + 1], T[MAXN + 1];
	
	void work()
	{
		int kase;
		scanf("%d", &kase);
		while (kase--)
		{
			int n, r, p, s, cr = 0, cp = 0, cs = 0;
			scanf("%d%d%d%d", &n, &r, &p, &s);
			scanf("%s", S);
			for (int i = 0; i < n; i++)
				if (S[i] == 'R')
					cp++;
				else if (S[i] == 'P')
					cs++;
				else
					cr++;
			if (min(r, cr) + min(p, cp) + min(s, cs) >= (n + 1) / 2)
			{
				puts("YES");
				for (int i = 0; i < n; i++)
				{
					if (S[i] == 'R' && p)
						T[i] = 'P', p--;
					else if (S[i] == 'P' && s)
						T[i] = 'S', s--;
					else if (S[i] == 'S' && r)
						T[i] = 'R', r--;
					else
						T[i] = 0;
				}
				T[n] = 0;
				for (int i = 0; i < n; i++)
					if (!T[i])
					{
						if (p)
							T[i] = 'P', p--;
						else if (s)
							T[i] = 'S', s--;
						else if (r)
							T[i] = 'R', r--;
					}
				puts(T);
			}
			else
				puts("NO");
		}
	}
}

int main()
{
	CF::work();
	return 0;
}