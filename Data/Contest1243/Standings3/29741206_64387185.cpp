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
char c1[55],c2[55];
int cnt[300];
vector<int> v;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d%s%s",&n,c1+1,c2+1);
		v.clear();
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
		{
			cnt[c1[i]]++;
			cnt[c2[i]]++;
		}
		int flag=0;
		for(int i='a';i<='z';i++)
		{
			if(cnt[i]%2)
			{
				flag=1;
				printf("No\n");
				break;
			}
		}
		if(flag==1)
		continue;
		
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(c1[i]!=c2[i])
			{
				int flag=1;
				for(int j=i+1;j<=n;j++)
				{
					if(c2[i]==c2[j])
					{
						ans++;
						v.pb(i);v.pb(j);
						swap(c1[i],c2[j]);
						flag=0;
						break;
					}
				}
				
				if(flag)
				{
					for(int j=i+1;j<=n;j++)
					{
						if(c2[i]==c1[j])
						{
							ans+=2;
							v.pb(j);v.pb(j);
							swap(c1[j],c2[j]);
							v.pb(i);v.pb(j);
							swap(c1[i],c2[j]);
							break;
						}
					}
				}
				
			}
		}
		printf("Yes\n%d\n",ans);
		for(int i=0;i<v.size();i+=2)
		{
			printf("%d %d\n",v[i],v[i+1]);
		}
	}
}
