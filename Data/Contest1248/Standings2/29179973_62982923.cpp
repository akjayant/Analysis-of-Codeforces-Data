#include<bits/stdc++.h>
#define ll long long
#define MAX_N 100010
using namespace std;
ll n,a,b,x[MAX_N];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(ll i=1;i<=n;++i)cin>>x[i];
	sort(x+1,x+n+1);
	for(ll i=1;i<=n/2;++i)
		a+=x[i];
	for(ll i=1;i<=n;++i)
		b+=x[i];
	b-=a;
	cout<<a*a+b*b<<endl;
	return 0;
}