#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;

ll n,q,a,b,c;

void solve()
{
	cin>>a>>b>>c;
	ll anw=0;
	while(b>=1&&c>=2)
	{
		b-=1,c-=2;
		anw+=3;
	}	
	while(a>=1&&b>=2)
	{
		a-=1,b-=2;
		anw+=3;
	}
	cout<<anw<<"\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>q;
	while(q--)
		solve();
	return 0;
}