#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;

int T,n;
char s[maxn],t[maxn];
int tot[300];
int ans[300][2],top;

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> n;
		scanf("%s%s",s,t);
		memset(tot,0,sizeof(tot));
		for(int i = 0; i < n; i++)
		{
			int c = s[i] - 'a';
			tot[c]++;
			tot[t[i]-'a']++;
		}
		bool flag = true;
		top = 0;
		for(int i = 0; i < 26; i++)
			if(tot[i]&1)
				flag = false;
		if(!flag)
			printf("No\n");
		else
		{
			for(int i = 0; i < n; i++)
			{
				if(s[i] != t[i])
				{
					int pos = 0;
					for(int j = i + 1; j < n; j++)
						if(s[i] == s[j])
						{
							pos = j;
							break;
						}
					if(pos > 0)
					{
						ans[top][0] = pos;
						ans[top][1] = i;
						swap(t[i],s[pos]);
						top++;
						continue;
					}
					for(int j = i + 1; j < n; j++)
						if(t[j] == s[i])
						{
							pos = j;
							break;
						}
					ans[top][0] = i + 1;
					ans[top][1] = pos;
					swap(t[pos],s[i+1]);
					top++;
					ans[top][0] = i + 1;
					ans[top][1] = i;
					swap(t[i],s[i+1]);
					top++;
				}
			}
			printf("Yes\n%d\n",top);
			for(int i = 0; i < top; i++)
			{
				printf("%d %d\n",ans[i][0]+1,ans[i][1]+1);
			}
		}
	}
	return 0;
}


