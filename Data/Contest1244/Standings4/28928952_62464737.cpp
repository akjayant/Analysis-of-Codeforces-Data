#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef double db;

#define mp make_pair
#define pb push_back
#define pt(i) printf("%lld\n",(ll)i)
#define mp make_pair
#define ff first
#define ss second
#define pi acos(-1.0)

ll in() { ll a;scanf("%lld",&a); return a;}
db din(){ db a;scanf("%lf",&a); return a; }
ll bigmod(ll b, ll p,ll md){if(p==0) return 1;if(p%2==1){ return ((b%md)*bigmod(b,p-1,md))%md;} else {ll y=bigmod(b,p/2,md);return (y*y)%md;}}
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b);}

long long getRandom(long long a,long long b){
    long long ret = (long long)rand()*(long long)rand();
    ret %= (b - a + 1);
    ret += a;
    return ret;
}

int main()
{
    int t=in();
    while(t--)
    {
        int a=in(),b=in(),c=in(),d=in(),k=in();
        int x=(a+c-1)/c,y=(b+d-1)/d;
        if(x+y>k)
        puts("-1");
        else
        printf("%d %d\n",x,y);
    }
}

