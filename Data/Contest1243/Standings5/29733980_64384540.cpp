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
        string st1;
        cin>>st1;
        string st2;
        cin>>st2;
        ll c=0;
        vector<ll> v;
        loop
        {
            if(st1[i]!=st2[i])
            {
                c++;
                v.pb(i);
            }

        }
        if(c==0)
            {
                cout<<"YES\n";
            }
            else if(c==2)
            {
                ll x=v[0];
                ll y=v[1];
                if(st1[x]==st1[y] && st2[x]==st2[y])
                {
                    printf("YES\n");
                }
                else printf("NO\n");
            }
            else printf("NO\n");

    }
}




