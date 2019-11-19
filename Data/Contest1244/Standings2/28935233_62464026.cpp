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
    ll a,b,c,d,k;
    cin>>a>>b>>c>>d>>k;
    ll x=a/c+(a%c!=0);
    ll y=b/d+(b%d!=0);
    if(x+y>k)cout<<"-1\n";
    else cout<<x<<" "<<y<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    while(n--)solve();
return 0;
}
