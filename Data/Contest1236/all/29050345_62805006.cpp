#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ins insert
#define sb substr
#define con continue
#define ub upper_bound
#define lb lower_bound
#define sp fixed<<setprecision
#define bp __builtin_popcountll
#define pll pair<ll,ll>
#define pld pair<ld,ld>
using namespace std;

ll power(ll x, ll y);
ll mpower(ll x, ll y, ll p);
ll modInv(ll a, ll m);
ll gcdExtended(ll a, ll b, ll *x, ll *y);
bool isPrime(ll n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,i,j,k,l,h,p,q,r,x,y,z,a,b,c,d,f,n,m,M=1000000007;
    char ch,ch2,ch3;
    string s,s1,s2,s3;
    vector<ll> v,w;
    unordered_map<ll,ll> N;
    set<ll> S;
    set<ll> :: iterator itr;
    cin>>n>>m>>k;
    c=n*m;
    vector<ll> A[n+1],B[m+1];
    for(i=0;i<k;i++){
        cin>>x>>y;
        A[x].pb(y);
        B[y].pb(x);
    }
    for(i=1;i<=n;i++){
        A[i].pb(0);
        A[i].pb(m+1);
    }
    for(i=1;i<=m;i++){
        B[i].pb(0);
        B[i].pb(n+1);
    }
    for(i=0;i<=n;i++){
        sort(A[i].begin(),A[i].end());
    }
    for(i=0;i<=m;i++){
        sort(B[i].begin(),B[i].end());
    }
    ll x1,x2,y1,y2;
    x1=0;
    x2=n+1;
    y1=0;
    y2=m+1;
    i=1;
    j=0;
    d=0;
    while(1){
        if(d==0){
            a=i;
            b=j;
            p=ub(A[i].begin(),A[i].end(),j)-A[i].begin();
            p=min(y2,A[i][p]);
            c-=p-j-1;
            j=p-1;
            y2=p;
            x1=max(x1,i);
            d=1;
            if(a==i && b==j){
                break;
            }
        }
        else if(d==1){
            a=i;
            b=j;
            p=ub(B[j].begin(),B[j].end(),i)-B[j].begin();
            p=min(x2,B[j][p]);
            c-=p-i-1;
            i=p-1;
            x2=p;
            y2=min(y2,j);
            d=2;
            if(a==i && b==j){
                break;
            }
        }
        else if(d==2){
            a=i;
            b=j;
            p=ub(A[i].begin(),A[i].end(),j)-A[i].begin();
            p--;
            p=max(y1,A[i][p]);
            c-=j-p-1;
            j=p+1;
            y1=p;
            x2=min(x2,i);
            d=3;
            if(a==i && b==j){
                break;
            }
        }
        else{
            a=i;
            b=j;
            p=ub(B[j].begin(),B[j].end(),i)-B[j].begin();
            p--;
            p=max(x1,B[j][p]);
            c-=i-p-1;
            i=p+1;
            x1=p;
            y1=max(y1,j);
            d=0;
            if(a==i && b==j){
                break;
            }
        }
    }
    if((c-k)==0){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    return 0;
}

ll modInv(ll a, ll m){
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    ll res = (x%m + m) % m;
    return res;
}

ll gcdExtended(ll a, ll b, ll *x, ll *y){
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}

ll mpower(ll x, ll y, ll p){
    ll res = 1;
    x = x % p;
    while(y > 0){
        if(y & 1) res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

ll power(ll x, ll y){
    ll res = 1;
    while (y > 0){
        if (y & 1) res = res*x;
        y = y>>1;
        x = x*x;
    }
    return res;
}

bool isPrime(ll n){
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    ll p=sqrt(n);
    for(int i=5;i<=p;i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;
    return true;
}
