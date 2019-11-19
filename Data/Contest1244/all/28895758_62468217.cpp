#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pi;
 
ll q,n;
string s;

void solve()
{
	cin>>n>>s;
	ll mx=0;
	for(ll i=0;i<n;i++)
	{
		if(s[i]=='1')
			mx=max(mx,max(i+1,n-i));
	}
	if(mx==0) cout<<n<<"\n";
	else cout<<mx*2<<"\n";
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