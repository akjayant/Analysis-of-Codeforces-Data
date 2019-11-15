//Utkarsh.25dec
#include <bits/stdc++.h>
#define ll long long int 
#define ull unsigned long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define vi vector <int>
#define vs vector <string>
#define vc vector <char>
#define vl vector <ll>
#define all(c) (c).begin(),(c).end()
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
using namespace std;
const int N=500023;
bool vis[N];
vector <int> adj[N];
void solve()
{
    ll n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    vl v;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])
            v.pb(i);
    }
    if(v.size()!=2)
    {
        cout<<"NO\n";
        return;
    }
    int i=v[0];
    int j=v[1];
    char ch1=s[i];
    char ch2=t[i];
    // cout<<ch1<<' '<<ch2<<' '<<s[j]<<' '<<t[j]<<'\n';
    int flag=0;
    if((s[j]==ch1))
        flag++;
    if((t[j]==ch2))
        flag++;
    if(flag==2)    
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int T=1;
    cin>>T;
    int t=0;
    while(t++<T)
    {
        //cout<<"Case #"<<t<<":"<<' ';
        solve();
        //cout<<'\n';
    }
}