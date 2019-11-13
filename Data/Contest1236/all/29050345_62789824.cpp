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
    cin>>n;
    ll A[n][n];
    x=1;
    for(j=0;j<n;j++){
        if(j%2){
            for(i=n-1;i>=0;i--){
                A[i][j]=x;
                x++;
            }
        }
        else{
            for(i=0;i<n;i++){
                A[i][j]=x;
                x++;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
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
