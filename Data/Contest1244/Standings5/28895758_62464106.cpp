#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pi;
 
ll q,a,b,c,d,k;

void solve()
{
	cin>>a>>b>>c>>d>>k;
	if(ceil((double)a/(double)c)+ceil((double)b/(double)d)>k)
		cout<<-1<<"\n";
	else
		cout<<ceil((double)a/(double)c)<<" "<<ceil((double)b/(double)d)<<"\n";
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