#include<stdio.h>
#include<math.h>
#include<string.h>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#define pb push_back
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f
#define dd(x) cout<<#x<<" = "<<x<<","
#define de(x) cout<<#x<<" = "<<x<<"\n"
using namespace std;
typedef long long ll;
char s[110];
vector<char> ans;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ans.clear();
		int n,a,b,c;
		scanf("%d%d%d%d",&n,&a,&b,&c);
		scanf("%s",s+1);
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='R')
			{
				if(b>0)
				{
					b--;
					cnt++;
					ans.pb('P');
				}
				else
				{
					ans.pb('!');
				}
			}
			else if(s[i]=='P')
			{
				if(c>0)
				{
					c--;
					cnt++;
					ans.pb('S');
				}
				else
				{
					ans.pb('!');
				}
			}
			else if(s[i]=='S')
			{
				if(a>0)
				{
					a--;
					cnt++;
					ans.pb('R');
				}
				else
				{
					ans.pb('!');
				}
			}
		}
		if(cnt>=n/2+n%2)
		{
			printf("YES\n");
			for(int i=0;i<ans.size();i++)
			{
				if(ans[i]!='!')
				{
					printf("%c",ans[i]);
				}
				else if(a>0)
				{
					a--;
					printf("R");
				}
				else if(b>0)
				{
					b--;
					printf("P");
				}
				else if(c>0)
				{
					c--;
					printf("S");
				}
			}
			printf("\n");
		}
		else
		{
			printf("NO\n");
		}
	} 
}
