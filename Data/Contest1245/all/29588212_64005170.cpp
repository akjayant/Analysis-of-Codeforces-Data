#include<bits/stdc++.h>

using namespace std;

main()
{
	int T, N, a, b, c, w;
	string str, str2;
	cin >> T;
	while(T--)
	{
		w = 0;
		cin >> N >> a >> b >> c >> str;
		str2.clear();
		for(int i = 0; i < N; i++)
		{
			if(str[i] == 'R' && b)
			{
				w++;
				b--;
				str2 += 'P';
			}
			else if(str[i] == 'P' && c)
			{
				w++;
				c--;
				str2 += 'S';
			}
			else if(str[i] == 'S' && a)
			{
				w++;
				a--;
				str2 += 'R';
			}
			else
				str2 += 'V';
		}
		if(w < (N+1)/2)
			printf("NO\n");
		else
		{
			printf("YES\n");
			for(int i = 0; i < N; i++)
			{
				if(str2[i] == 'V')
				{
					if(a)
					{
						a--;
						str2[i] = 'R'; 
					}
					else if(b)
					{
						b--;
						str2[i] = 'P';
					}
					else
					{
						c--;
						str2[i] = 'S';
					}
						
				}
				printf("%c", str2[i]);
			}
			printf("\n");
		}
	
		
	}
	return 0;
}
