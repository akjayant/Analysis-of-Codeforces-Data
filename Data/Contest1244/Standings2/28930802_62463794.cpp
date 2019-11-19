#include <bits/stdc++.h>
using namespace std;
 
#define M 1000000007
 
#define mp make_pair
#define pb push_back
#define tri pair<int, pair<int, int> >
#define TRI(a,b,c) (make_pair(a,make_pair(b,c)))
 
typedef long long ll;
typedef long double ld;

ll powmod(ll x, ll y, ll m=M)
{
	if(y==0) return 1;
	ll ret = powmod(x, y/2, m);
	ret = (ret*ret)%m;
	if(y%2) ret=(ret*x)%m;
	return ret;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--)
    {
    	int a, b, c, d, k; cin>>a>>b>>c>>d>>k;
    	a = (a-1)/c+1;
    	b = (b-1)/d+1;
    	if((a+b) > k)
    	{
    		cout<<-1<<endl;
    	}
    	else cout<<a<<" "<<b<<endl;
    }
    return 0;
}