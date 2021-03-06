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
        bool can=1;
        vector<pair<int,int>> ans;
        for (int i=0;i<n;i++)
        {
            if (s[i]!=t[i])
            {
                bool f=0;
                for (int j=i+1;j<n;j++)
                    if (s[j]==s[i])
                    {
                        ans.pb(mp(j+1,i+1));
                        swap(s[j],t[i]);
                        f=1;
                        break;
                    }
                if (f) continue;
                for (int j=i+1;j<n;j++)
                    if (t[j]==s[i])
                    {
                        ans.pb(mp(j+1,j+1));
                        swap(s[j],t[j]);
                        ans.pb(mp(j+1,i+1));
                        swap(s[j],t[i]);
                        f=1;
                        break;
                    }
                if (!f) {can=0; break;}
            }
        }
        if (!can)
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
            cout<<ans.size()<<endl;
            for (auto it:ans)
                cout<<it.fir<<" "<<it.sec<<endl;
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