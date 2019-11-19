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

int tc,n,m;
ll a[200000];
ll ev1,ev2,odd1,odd2;
ll b[200000];

int main() {
    scanf("%d",&tc);
    repp(t,1,tc) {
        scanf("%d",&n);
        ev1=0;
        ev2=0;
        odd1=0;
        odd2=0;
        repp(x,1,n ){
            scanf("%lld",&a[x]);
            if(a[x]%2==1) {
                odd1++;
            }
            else {
                ev1++;
            }
        }
        scanf("%d",&m);
        repp(x,1,m) {
            scanf("%lld",&b[x]);
            if(b[x]%2==1) {
                odd2++;
            }
            else {
                ev2++;
            }
        }
        printf("%lld\n",odd1*odd2+ev1*ev2);

    }

    return 0;
}