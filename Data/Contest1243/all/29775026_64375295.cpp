#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x,y) for (ll i=x;i<=y;i++)
int main()
{
	int q;
	cin>>q;
	while (q--)
	{
		int n;
		cin>>n;
		int a[n+1],i;
		rep(i,1,n)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		rep(i,1,n)
		{
			if (a[i]>n-i)
			{
				cout<<n-i+1<<endl;
				break;
			}
		}
	}
	return 0;
}
