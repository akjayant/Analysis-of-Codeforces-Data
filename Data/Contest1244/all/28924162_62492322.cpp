#include<bits/stdc++.h>
#define ll                  long long
#define dl                 double
#define pb                push_back
#define F                  first
#define S                  second
#define endl              "\n"
#define rep(i,a,b)       for(i=a;i<b;i++)
#define all(v)             v.begin(),v.end()
#define allr(v)            v.rbegin(),v.rend()
#define mod              1000000007
#define CIN(V,s,n)      for(int i=s;i<n;i++){cin >> V[i];}
#define COUT(V,s,n)   {for(int i=s;i<n;i++){cout <<  V[i] << " "  ;} cout << endl;}
#define fast               ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define CLEAR(V);      for(ll i=0;i<V.size();i++) V[i] = 0;
#define N                  500005LL
#define tmod            998244353
using namespace std;

bool sBs(const pair<int,int> &a,const pair<int,int> &b)
{   return (a.second < b.second);   }

ll SUMD(ll n);
ll BS(vector<ll> &PS,ll s,ll e,ll ser);
ll MI(ll a, ll m);
bool P[N+1];
void Sieve(int n=N);
ll Powb(ll b,ll n);

ll DFS(vector<vector<ll> > &G,vector<vector<ll> > &DP,ll s,ll p,ll it,string &s1)
{
   // if(G[s].size()==1 and s!=p) return 0;
    for(auto it2:G[s])
    {
        if(it2!=p)
            return (DP[s1[it]-'0'][s] + DFS(G,DP,it2,s,(it+1)%3,s1));
    }
    return DP[s1[it]-'0'][s];
}

int main()
{
//fast;
ll q=1,t;
//cin >> q;
t = q;
while(q--)
{

    ll n,m,k,i,j,l,r,c=0,b,a,g,counter=0,u,v,d,e,w,p,x,y,z,flag=1;
    //n=m=i=j=l=r=a=t=b=c=u=v=w=p=x=y=0;
    cin >> n ; //cout << "n";
    vector<vector<ll> > DP(3,vector<ll> (n+1));

    for(i=0;i<3;i++)
    for(j=1;j<=n;j++)
        cin >> DP[i][j];

    vector<vector<ll> > G(n+1);

    for(i=0;i<n-1;i++)
    {
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    ll s = 1,c1=0;
    for(i=1;i<=n;i++)
    {
        if(G[i].size()>2) {cout << -1; return 0;}
        if(G[i].size()==1) {c1++;s=i;if(c1>2) {cout << -1 ; return 0;}}
    }
    //cout << "yes" << " ";
    ll ans = 1e17;
    string s1= "012",sa="";
    do{
        ll pc = DFS(G,DP,s,s,0,s1);
        if(pc<ans) {ans = pc; sa = s1;}
        //cout << s1 << " ";
    }while(next_permutation(s1.begin(),s1.end()));

    cout << ans << endl;
    p  = s;
    vector<ll> Col(n+1);
    i = 0;
    while(G[s].size()!=1 or s==p)
    {
        Col[s] = sa[i%3] - '0' + 1;
        i++ ;
        for(auto it:G[s])
        {
            if(it!=p)
            {
                swap(s,p);
                s = it;break;
            }
        }
    }
    Col[s] = sa[i%3] - '0' + 1;
    for(i=1;i<=n;i++) cout << Col[i ] << " " ;

}
    return 0;
}

//*****************************************************************************************************************************************

ll Powb(ll b,ll n)
{
    if(n==0) return 1LL;
    if(n==1) return b;
    ll temp = Powb(b,n/2);
    if(n%2==0){return (temp*temp)%mod;}
    else{return (b*((temp*temp)%mod))%mod;}
}

ll SUMD(ll n)
{   ll sum=0;
    while(n>0){sum += n%10;n = n/10;}
    return sum;

}
ll BS(vector<ll> &PS,ll s,ll e,ll ser)
{
    if(s>e)
        return s;
    ll mid = (s+e)/2;
    if(PS[mid]==ser)
    {
        return mid;
    }
    else if(PS[mid] > ser)
    {
        return BS(PS,s,mid-1,ser);
    }
    else
        return BS(PS,mid+1,e,ser);
}
ll MI(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
      return 0;
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
       x += m0;
    return x;
}

void Sieve(int n)
{
    memset(P,true,sizeof(P));
    P[0] = false;
    P[1]= false;
    for(ll i=2;i*i<=n;i++)
    {
        if(P[i])
        {
            for(ll j=i*i;j<=n;j+=i)
            {
                P[j]=false;
            }
        }
    }

}
