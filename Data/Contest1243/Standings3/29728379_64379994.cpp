#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define ll long long
#define ull unsigned long long
 
ll md=(1e9)*1e9+7;
ll MOD=1e9+7;
int INF=1e9+7;
 
ll binpow (ll a, ll n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return (binpow (a, n-1) * a) % MOD;
	else {
		int b = binpow (a, n/2)% MOD;
		return (b * b) % MOD;
	}
}
 
pair<int,ll> rev(pair<ll,int> x)
{
    return mp(x.sec,x.fir);
}
 
void update()
{
    
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        string s,t;
        int n;
        cin>>n>>s>>t;
        vector<int> x;
        for (int i=0;i<n;i++)
            if (s[i]!=t[i]) x.pb(i);
        if (x.size()!=2)
        {
            cout<<"No"<<endl;
        }
        else
        {
            if (s[x[0]]==s[x[1]]&&t[x[0]]==t[x[1]]) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
/*
0 0 0
0 0 1
0 1 0
1 0 0
*/