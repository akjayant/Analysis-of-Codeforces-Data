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
int a[1005];
int sum[1005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(sum,0,sizeof(sum));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int temp;
			scanf("%d",&temp);
			a[temp]++;
		}
		int ans=0;
		for(int i=n;i>=1;i--)
		{
			sum[i]=sum[i+1]+a[i];
			if(sum[i]>=i)
			{
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	}
}
