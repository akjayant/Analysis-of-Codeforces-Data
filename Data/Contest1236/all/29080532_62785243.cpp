#include<bits/stdc++.h>

using namespace std;

main()
{
	int T, a, b, c;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d", &a, &b, &c);
		int best = 0;
		for(int i = 0; i <= c/2; i++)
		{
			if(i > b)
				break;
			best = max(best, 3*i + 3*min(a, (b-i)/2));	
		}
		printf("%d\n", best);
	}
	return 0;
}