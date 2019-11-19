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

int main()
{
fast;
ll q=1,t;
cin >> q;
t = q;
while(q--)
{

    ll n,m,k,i,j,l,r,c=0,b,a,g,counter=0,u,v,d,e,w,p,x,y,flag=1;
    //n=m=i=j=l=r=a=t=b=c=u=v=w=p=x=y=0;
    cin >> a >> b >> c >> d >> k;
    ll ans = a/c + (a%c!=0) + b/d + (b%d!=0);
    if(ans <= k) cout << (a/c + (a%c!=0)) << " " <<  (b/d + (b%d!=0)) << endl;
    else cout << -1 << endl;

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
