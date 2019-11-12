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
    vector <pair<ll,ll>> v;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])
        {
            int flag=0;
            int index=0;
            int j;
            for(j=i+1;j<n;j++)
            {
                if(s[j]==s[i])
                {
                    index=j;
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                v.pb(mp(j,i));
                char temp=s[j];
                s[j]=t[i];
                t[i]=temp;
                continue;
            }
            for(j=i+1;j<n;j++)
            {
                if(t[j]==s[i])
                {
                    index=j;
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                v.pb(mp(j,j));
                v.pb(mp(j,i));
                char temp=s[j];
                s[j]=t[j];
                t[j]=temp;
                temp=s[j];
                s[j]=t[i];
                t[i]=temp;
                continue;
            }
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    cout<<v.size()<<'\n';
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].first+1<<' '<<v[i].second+1<<'\n';
    }
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