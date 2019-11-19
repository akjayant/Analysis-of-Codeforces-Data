#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pic pair<int,char>
#define pci pair<char,int>
#define pll pair<ll,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define vic vector<pic>
#define vci vector<pci>
#define vlc vector<plc>
#define vcl vector<pcl>
#define pb push_back
#define endl '\n'
const ll MOD=1e9+7;
const ll INF=1e9;
const ll MAXN=1e5+6;
const ll MAXM=1e5+6;
ll n;
ll minel=1e15,k,maxel=-1;
vector<ll>a;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;
    for(ll i=0;i<n;i++)
    {
        ll x;cin>>x;
        a.push_back(x);
        minel=min(minel,x);
        maxel=max(maxel,x);
    }
    sort(a.begin(),a.end());
    ll ans=maxel-minel,cntl=1,cntr=1;
    if(ans==0){cout<<ans<<endl;return 0;}
    for(ll i=1;i<a.size();i++)
    {
        if(a[i]==a[i-1])
        {
            cntl++;
        }
        else break;
    }
    for(ll i=a.size()-1;i>=0;i--)
    {
        if(a[i]==a[i+1])
        {
            cntr++;
        }
        else break;
    }
    for(;;)
    {
        if(cntl>k&&cntr>k)break;
        if(cntl<cntr)
        {
            ll x=min(a[cntl]-a[cntl-1],k/cntl);
            k-=x*cntl;
            a[cntl-1]+=x;ans-=x;
            while(cntl<n&&a[cntl-1]==a[cntl])cntl++;
        }
        else
        {
            ll x=min(a[n-cntr]-a[n-cntr-1],k/cntr);
            k-=cntr*x;
            a[n-cntr]-=x;ans-=x;
            while(n-cntr-1>=0&&a[n-cntr]==a[n-cntr-1])cntr++;
        }
        if(ans==0)break;
    }
    cout<<ans<<endl;
return 0;
}
