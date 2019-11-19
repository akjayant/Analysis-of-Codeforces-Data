#include<bits/stdc++.h>
#define faster_io ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define mem(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
using namespace std;
const ll N=1e6+3,inf=1e18,mod=1e9+7,eps=-1e8;
ll tc,n,m,a,b,c,d,i,j,k,l,sum,ans;
string s,t;
vector<ll>v;

int32_t main()
{
    faster_io;
    cin>>tc;
    while(tc--){
    cin>>a>>b>>c>>d>>n;
    a=(a+c-1)/c;
    b=(b+d-1)/d;
    if(a+b<=n)
        cout<<a<<' '<<b<<endl;
    else cout<<-1<<endl;}
}
