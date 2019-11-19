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
const int N=1000023;
bool vis[N];
vector <int> adj[N];
void solve()
{
    ll n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<'\n';
        return;
    }
    ll isprime[1000023];
    for(int i=0;i<N;i++)
        isprime[i]=i;
    for(int i=2;i<N;i++)
    {
        if(isprime[i]==i)
        {
            for(int j=2*i;j<N;j+=i)
                isprime[j]=i;
        }
    }
    vl v;
    for(int i=2;i<N;i++)
    {
        if(isprime[i]==i)
        {
            if(n%i==0)
            {
                v.pb(i);
                while(n%i==0)
                    n/=i;
            }
        }
    }
    if(n!=1)
        v.pb(n);
    if(v.size()==1)
    {
        cout<<v[0]<<'\n';
    }
    else
    {
        cout<<1<<'\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int T=1;
    //cin>>T;
    int t=0;
    while(t++<T)
    {
        //cout<<"Case #"<<t<<":"<<' ';
        solve();
        //cout<<'\n';
    }
}