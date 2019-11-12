/// Template
#include<bits/stdc++.h>
using namespace std;
#define read FILE *fp;\
fp=freopen("testcase.txt","r",stdin);
#define ll long long
#define ull unsigned long long
#define sf(n) scanf("%I64d",&n)
#define pf(n) printf("%I64d\n",n)
#define loop for(long long i=0;i<n;i++)
#define tloop for(it=0;it<t;it++)
#define lp(b,n) for(long long i=b;i<n;i++)
#define pb push_back
#define srt(v) sort(v.begin(),v.end())
#define rvs(v) sort(v.begin(), v.end(), greater<long long>());
#define F first
#define S second
#define mp make_pair
#define fio ios::sync_with_stdio(false); cin.tie(),cout.tie();
bool sortbysec(const pair<pair<ll,ll>,ll> &a,
               const pair<pair<ll,ll>,ll> &b)
{
    return (a.second < b.second);
}
void con(ll fl)
{
    if(fl==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
ll mark[5010];
int main()
{
    ll t,it,i,n,x,s;
    cin>>t;
    tloop
    {
        vector<ll>ve;
        cin>>n;
        loop
        {
            cin>>x;
            ve.pb(x);
        }
        sort(ve.begin(),ve.end());
        s=1;
        for(i=n-1;i>=0;i--)
        {
            if(ve[i]<=n-i)
            {
                s=max(ve[i],n-i-1);
                break;
            }
        }
        cout<<s<<endl;
    }
}
