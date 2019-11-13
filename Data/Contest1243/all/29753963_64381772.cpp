#include <bits/stdc++.h>
using namespace std;
const int nmax=1e5+5;
long long t,n,a[nmax],ma,s;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for (int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		ma=1;
		for (int i=n;i>=1;i--)
			if (a[i]>=ma)
                ma++;
		cout<<ma-1<<'\n';
	}
}
