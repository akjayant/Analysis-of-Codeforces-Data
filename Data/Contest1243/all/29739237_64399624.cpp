#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=52;
char s[N];
char t[N];
int n,m;
int T;
int zms[27];
int zmt[27];
int sum[27];
int f[N*2];
int f2[N*2];
inline int check()
{
	for(int i=0; i<n; i++)
	{
		if(s[i]!=t[i])
			return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s);
		scanf("%s",t);
		int ok=0;
		memset(zms,0,sizeof(zms));
		memset(zmt,0,sizeof(zmt));
		memset(f,0,sizeof(f));
		memset(f2,0,sizeof(f2));
		for(int i=0; i<n; i++)
		{
			zms[s[i]-'a'+1]+=1;
			zmt[t[i]-'a'+1]+=1;
		}
		for(int i=1; i<=26; i++)
		{
			if((zms[i]+zmt[i])&1)
			{
				ok=1;
				printf("No\n");
				break;
			}
			sum[i]=zms[i]+zmt[i];
		}
		if(ok)
			continue;
		int st=0;
		while(1)
		{
			st++;
			int cz=0;
			for(int i=0; i<n; i++)
			{
				if(s[i]==t[i])
					continue;
				if(zms[s[i]-'a'+1]!=sum[s[i]-'a'+1]/2)
				{
					for(int j=i+1; j<n; j++)
					{
						if(s[j]!=s[i])
							continue;
						if(s[j]==t[j])
							continue;
						f[st]=i+1;
						f2[st]=j+1;
						zms[s[i]-'a'+1]--;
						zms[t[j]-'a'+1]++;
						zmt[s[i]-'a'+1]++;
						zmt[t[j]-'a'+1]--;
						swap(s[i],t[j]);
						cz=1;
						break;
					}
				}
				if(cz)
					break;
			}
			if(!cz)
			{
				for(int i=0; i<n; i++)
				{
					if(s[i]==t[i])
						continue;
					else
					{
						f[st]=i+1;
						f2[st]=i+1;
						zms[s[i]-'a'+1]--;
						zmt[s[i]-'a'+1]++;
						zms[t[i]-'a'+1]++;
						zmt[t[i]-'a'+1]--;
						swap(s[i],t[i]);
						cz=1;
					}
					if(cz)
						break;
				}
			}
			if(check())
				break;
		}
		if(st>2*n)
			printf("No\n");
		else
		{
			printf("Yes\n");
			printf("%d\n",st);
			for(int i=1; i<=st; i++)
			{
				printf("%d %d\n",f[i],f2[i]);
			}
		}

	}
	return 0;
}
