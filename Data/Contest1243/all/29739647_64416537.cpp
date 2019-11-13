#include <bits/stdc++.h>    
using namespace std;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb  push_back
#define show(x) cout<<(#x)<<" : "<<x<<endl;
#define ll  long long
#define ld  long double
#define fill(a,val) memset(a,val,sizeof(a))
#define mp  make_pair
#define ff  first
#define ss  second
#define pii pair<ll,ll>
#define sq(x) ((x)*(x))
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define endl "\n"
const ll MOD     = 1000*1000*1000+7;
const ll INF     = 1ll*1000*1000*1000*1000*1000*1000 + 7;
const ll MOD2    = 1ll*1000*1000*1000 + 7;
const ll N       = 1ll*1000*1000*1000*1000*1000;
const ll N2      = 1000*100;
const ld PI  = 3.14159265;
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);} 
ll power(ll x,ll y,ll p = INF){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;} 
signed main()
{
    //CHECK for LONG LONG and LONG DOUBLE
    //comment for all except cc/cf    
    #ifndef ONLINE_JUDGE
           freopen("input.txt","r",stdin);
           freopen("output.txt","w",stdout);
    #endif//*/ 
    fastio();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        int count[26]={0};
        for(auto x : s)
            count[x-'a']++;
        for(auto x : t)
            count[x-'a']++;
        int flag(0);
        for (int i = 0; i < 26; ++i)
        {
            flag+=(count[i]%2);
        }
        if(flag)
            cout<<"No"<<endl;
        else
        {
            cout<<"Yes"<<endl;
            std::vector<pii> ans;
            for (int i = 0; i < n; ++i)
            {
                if(s[i]!=t[i])
                {
                    for (int j = i+1; j < n; ++j)
                    {
                        if(s[j]==s[i])
                        {
                            ans.pb(mp(j+1,i+1));
                            swap(s[j],t[i]);
                            break;
                        }
                        if(t[j]==s[i])
                        {
                            
                            ans.pb(mp(j+1,j+1));
                            swap(s[j],t[j]);
                            
                            ans.pb(mp(j+1,i+1));
                            swap(s[j],t[i]);
                            break;
                        }
                    }
                }
            }
            cout<<ans.size()<<endl;
            for(auto x: ans)
                cout<<x.ff<<" "<<x.ss<<endl;
        }
    }
    
    return 0;
}