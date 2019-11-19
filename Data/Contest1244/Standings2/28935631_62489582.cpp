#include <bits/stdc++.h>
#include<limits.h>
#include<stdio.h>
#include<cstring>
#include<string>
using namespace  std;
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define fi first
#define se second
#define rsz(a,n) a.resize(n)
#define test(t) ll t;cin>>t;while(t--)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define fillv(a,k) memset(a,k,sizeof(a))
#define leadzero(a) __builtin_clz(a) //count leading zeros
#define trailzero(a) __builtin_ctz(a) //count trailing zeros
#define bitcount(a) __builtin_popcount(a) // count set bits (add ll)
#define ln cout<<"\n"
#define sp cout<<" "
#define spaceprint(a,i,s,n) {forsn(i,s,n) { cout<<a[i]; sp;}}
#define lineprint(a,i,s,n) {forsn(i,s,n) {cout<<a[i]; ln;}}
#define maxe(a) *max_element(a.begin(),a.end())
#define maxi(a) max_element(a.begin(),a.end())-a.begin()
#define mine(a) *min_element(a.begin(),a.end())
#define mini(a) min_element(a.begin(),a.end())-a.begin()
#define all(c) c.begin(),c.end()
#define trav(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element)  (find(all(container),element) != container.end())// check the presence of element
//copy(from_begin, from_end, to_begin); copy function
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<string> vs;
typedef vector<int> v32;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
typedef map<ll,ll> m64;
const int LIM = 1e5+5, MOD =  1e9+7;
#define sumv(v) accumulate(all(v),ll(0))
#define productv(v) accumulate(all(v), ll(1), multiplies< ll >())
ll gcd(ll a, ll b) { if(b == 0) return a; return gcd(b, a % b); }
ll fastpowMOD(ll a, ll p,ll MOD){ if(p==0) return 1; ll z = fastpowMOD(a,p/2,MOD); z = (z*z)%MOD; if(p%2) z = (z*a)%MOD; return z; }
bool seive[100005];
void SieveOfEratosthenes(ll n)
{ memset(seive, true, sizeof(seive)); for (ll p=2; p*p<=n; p++) if (seive[p] == true) for (ll i=p*p; i<=n; i += p) seive[i] = false; }
int main()
{
    fast;
    ll n;
    cin>>n;
    ll a[n+5][3];
    v64 v[n+5];
    ll i;
    v64 an;
    for(i=0;i<3;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            cin>>a[j][i];
        }
    }
    for(ll i=0;i<n-1;i++)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    ll k;
    for(i=1;i<=n;i++)
    {
        if(v[i].size()==1)
            k=i;
        if(v[i].size()>2)
        {
            cout<<-1;
            return 0;
        }
    }
    ll k1;
    k1=v[k][0];
    ll ans=1e17;
    ll ch1,ch2;
    for(ll i=0;i<3;i++)
    {
        for(ll j=0;j<3;j++)
        {
            //ll ch;
            ll cost=0;
            if(i==j)
                continue;
            cost+=a[k][i];
            cost+=a[k1][j];
            ll c1=i;
            ll c2=j;
            ll f1=c1;
            ll f2=c2;
            ll visited[n+5]={0};
            visited[k]=visited[k1]=1;
            ll pre;

            for(auto it:v[k1])
            {
                if(it==k)
                    continue;
                pre=it;
            }
            for(ll i=0;i<n-2;i++)
            {
                visited[pre]=1;
                ll c;
                for(ll i=0;i<3;i++)
                {
                    if(i==c1 or i==c2)
                        continue;
                    c=i;
                }
                cost+=a[pre][c];
                c1=c2;
                c2=c;
                ll p;
                for(auto it:v[pre])
                {
                    if(visited[it])
                        continue;
                    p=it;
                }
                pre=p;
            }
            if(ans>cost)
            {
                ch1=f1;
                ch2=f2;
            }
            ans=min(ans,cost);
        }
    }
    cout<<ans;
    ln;
    ll col[n+5];
    col[k]=ch1;
    col[k1]=ch2;
    //ll cost=0;
    // cost+=a[k][ch1];
    // cost+=a[k1][ch2];
    ll c1=ch1;
    ll c2=ch2;
    ll f1=c1;
    ll f2=c2;
    ll visited[n+5]={0};
    visited[k]=visited[k1]=1;
    ll pre;

    for(auto it:v[k1])
    {
        if(it==k)
            continue;
        pre=it;
    }
    for(ll i=0;i<n-2;i++)
    {
        visited[pre]=1;
        ll c;
        for(ll i=0;i<3;i++)
        {
            if(i==c1 or i==c2)
                continue;
            c=i;
        }
        // cost+=a[pre][c];
        col[pre]=c;
        c1=c2;
        c2=c;
        ll p;
        for(auto it:v[pre])
        {
            if(visited[it])
                continue;
            p=it;
        }
        pre=p;
    }
    for(i=1;i<=n;i++)
        cout<<col[i]+1<<" ";

}
       //cout<<-1;
