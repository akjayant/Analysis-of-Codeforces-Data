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
        int n;
        cin>>n;
        int a[1005];
        for (int i=0;i<n;i++)
            cin>>a[i];
        int ans;
        for (int i=1;i<=n;i++)
        {
            int k=0;
            for (int j=0;j<n;j++)
                if (a[j]>=i) k++;
            if (k>=i) ans=i;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
0 0 0
0 0 1
0 1 0
1 0 0
*/