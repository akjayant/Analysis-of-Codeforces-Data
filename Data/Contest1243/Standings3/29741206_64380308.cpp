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
char c1[10005],c2[10005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d%s%s",&n,c1+1,c2+1);
		for(int i=1;i<=n;i++)
		{
			if(c1[i]!=c2[i])
			{
				for(int j=i+1;j<=n;j++)
				{
					if(c1[j]!=c2[j])
					{
						swap(c1[i],c2[j]);
						break;
					}
				}
				break;
			}
		}
		
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(c1[i]!=c2[i])
			{
				printf("No\n");
				flag=0;
				break;
			}
		}
		if(flag)
		{
			printf("Yes\n");
		}
	}
}
