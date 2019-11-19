#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<bitset>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define pb(x) push_back(x)
#define cls(x, val) memset(x, val, sizeof(x))
#define fi first
#define se second
#define mp(x, y) make_pair(x, y)
#define inc(i, l, r) for(int i=l; i<=r; i++)
const int inf = 0x3f3f3f3f;
const int maxn = 2e5+10;
int n, m;
int a[maxn];


int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    ll tot = 0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        tot += a[i];
    }
    ll ans = 0;
    ll tot1 = 0;
    sort(a+1, a+1+n);
    int mid = 0;
    if(n%2 == 0){
        mid = n/2+1;
    }
    else mid = n/2+1;
    for(int i=n; i>=mid; i--){
        tot1 += a[i];
    }
    tot -= tot1;

    ans = tot1*tot1+tot*tot;
    cout<<ans<<endl;

    return 0;
}


