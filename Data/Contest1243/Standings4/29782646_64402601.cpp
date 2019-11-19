#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int > v;



int32_t main()
{
	int n;
	cin>>n;
	int f=1;
	for(int i=2; i*i<=n; i++)
	{
		if(n%i==0)
		{
			f=i;
			break;
		}
	}
	if(f==1)
	{
		cout<<n;
	}
	else
	{
		while(n>1 && n%f==0)
			n=n/f;
		if(n==1)
			cout<<f;
		else
			cout<<1;
	}
	return 0;
}