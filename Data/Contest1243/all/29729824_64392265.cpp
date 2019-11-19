#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
vector<ll>a;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(ll i=2;i*i<=n;++i)
	{
		if(n%i)continue;
		while(n%i==0)n/=i;
		a.push_back(i);
	}
	if(n!=1)a.push_back(n);
	if(a.size()==1)
		cout<<a[0]<<endl;
	else cout<<1<<endl;
	return 0;
}
