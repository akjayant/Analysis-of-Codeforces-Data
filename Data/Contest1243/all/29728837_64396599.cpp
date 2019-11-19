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
    ll n,fl,i;
    cin>>n;
    fl=0;
    for(i=2;i<=sqrt(n);i++)
    {
        while(n%i==0)
        {
            n=n/i;
            fl=1;
        }
        if(fl==1)
            break;
    }
    if(fl==0)
        cout<<n<<endl;
    else
    {
        if(n==1)
            cout<<i<<endl;
        else
            cout<<1<<endl;
    }
}
