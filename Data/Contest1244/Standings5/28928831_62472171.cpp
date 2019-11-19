#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
int t,n;
char a[1001];
int main()
{
	ios::sync_with_stdio(false);
	char u;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int ans=n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]=='1')
				ans++;
		}
		int q1=1,q2=n;
		while(a[q1]!='1'&&q1<=n+1)
			q1++;
		while(a[q2]!='1'&&q2>=0)
			q2--;
		if(q1<n+1)
			ans=max(ans,2*(n-q1+1));
		if(q2>0)
			ans=max(ans,2*q2);
		cout<<ans<<endl;
	}
	return 0;
}