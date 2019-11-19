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
void solve()
{
    ll n;
    string s;
    cin>>n;
    cin>>s;
    bool flag=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            flag=1;break;
        }
    }
    if(flag==0)
    {
        cout<<n<<endl;
        return;
    }
    ll ans=n;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            ans=max(ans,n*2-2*i);
            break;
        }
    }
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            ans=max(ans,n*2-2*i);
            break;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll q;cin>>q;
    while(q--)solve();
return 0;
}
