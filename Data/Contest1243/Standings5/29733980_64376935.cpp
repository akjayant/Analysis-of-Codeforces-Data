#include<bits/stdc++.h>
using namespace std;
#define read FILE *fp;\
fp=freopen("testcase.txt","r",stdin);
#define ll long long
#define ull unsigned long long
#define sf(n) scanf("%I64d",&n)
#define pf(n) printf("%I64d\n",n)
#define loop for(long long i=0;i<n;i++)
#define lp(b,n) for(long long i=b;i<=n;i++)
#define pb(n) push_back(n)
#define srt(v) sort(v.begin(),v.end())
#define rvs(v) sort(v.begin(), v.end(), greater<long long>());
#define F first
#define S second
#define mp(a,b) make_pair(a,b);
#define fio ios::sync_with_stdio(false); cin.tie(),cout.tie();
bool sortbysec(const pair<pair<ll,ll>,ll> &a,
               const pair<pair<ll,ll>,ll> &b)
{
    return (a.second < b.second);
}
class team
{
public:
    ll sol,pen,sub,tpen;
    vector<ll> v;
};
string add(string st1,string st2)
{
    ll r=0;
    string ans;
    ans.resize(3000);
    for(ll i=2999; i>=0; i--)
    {
        ll x=st1[i]-'0';
        ll y=st2[i]-'0';
        ll z=x+y+r;
        if(z>=10)
        {
            r=1;
        }
        else
            r=0;
        ans[i]=(z%10)+'0';
    }
    //cout<<ans<<endl;;
    return ans;
}
int main()
{

    ll q;
    cin>>q;
    vector <ll> v;
    while(q--)
    {
        ll n;
        sf(n);
        vector<ll> v;
        ll t;
        ll mx=0;
        loop
        {
            sf(t);
            v.pb(t);
            mx=max(mx,t);
        }
        ll ans=1;
        for(ll i=1;i<=mx;i++)
        {
            ll c=0;
            for(ll j=0;j<n;j++)
            {
                if(v[j]>=i)
                    c++;
            }
            if(c>=i)
                ans=i;
        }
        pf(ans);
    }
}




