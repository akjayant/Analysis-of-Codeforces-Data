// Input Output
#include <cstdio>
#include <cstdlib>
#include <iostream>
// Datastructures
#include <cstring>
#include <bitset>
#include <queue>
#include <map>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <utility>
#include <queue>
// Others
#include <cmath>
#include <algorithm>
#include <time.h>
// Define
#define mp make_pair
#define ff first
#define fi first
#define ss second
#define se second
#define pb push_back
#define eb emplace_back
#define rep(x,a,b,c) for(int x=a;x<=b;x+=c)
#define repp(x,a,b) rep(x,a,b,1)
#define rev(x,a,b,c) for(int x=a;x>=b;x-=c)
#define revv(x,a,b) rev(x,a,b,1)

using namespace std;

// Typedef
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;

// const
const double EPS = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9+7;
const int OO = 2e9;
const ll INF = (ll)9e18;

// Additional typedef for long long
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;

ll n,temp;
ll ans[200000];

int main() {
    scanf("%lld",&n);
    repp(x,1,n) {
        scanf("%lld",&ans[x]);
    }
    sort(ans+1,ans+n+1);
    ll a1=1;
    ll a2=n;
    ll a=0,b=0;
    while(a1<=a2) {
        //printf("%lld %lld: %lld %lld\n",a,b,ans[a1],ans[a2]);
        if(a1==a2) {
            b+=ans[a2];
            break;
        }
        a+=ans[a1];
        b+=ans[a2];
        a1++;
        a2--;
    }
    //printf("%lld %lld\n",a,b);
    printf("%lld\n",(a*a+b*b));
    return 0;
}