#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
namespace Dango
{
	const int MAXN=100005;
	long long n,k,num[MAXN];
	long long ans;
	int work()
	{
		ios::sync_with_stdio(false);
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>num[i];
		sort(num+1,num+n+1);
		int i=1,j=n;
		ans=num[n]-num[1];
		while(k&&i<j)
		{
			int x=i,y=n-j+1;
			if(x<y)
			{
				long long tmp=num[i+1]-num[i],cnt=min(k,tmp*x);
				k-=cnt;
				ans-=cnt/x;
				i++;
			}
			else
			{
				long long tmp=num[j]-num[j-1],cnt=min(k,tmp*y);
				k-=cnt;
				ans-=cnt/y;
				j--;
			}
		}
		cout<<ans;
		return 0;
	}
}
int main()
{
	return Dango::work();
}