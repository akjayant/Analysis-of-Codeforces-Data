#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#define pb push_back
#define mp make_pair
#define taskname "A"

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int maxn = 1e5 + 5;

int n , a[maxn];
ll k;
ll tot[maxn];
int CanHave(ll k){
    int l = 1;
    int h = 1e9;
    while(l <= h){
        int mid = l + h >> 1;
        int now = lower_bound(a + 1 , a + n + 1 , mid) - a;
        if(tot[now] - (ll)mid * (n - now + 1) <= k)h = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
		freopen(taskname".INP", "r",stdin);
		freopen(taskname".OUT", "w",stdout);
    }
    cin >> n >> k;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    for(int i = n ; i >= 1 ; --i)tot[i] = tot[i + 1] + a[i];
    int res = 1e9;
    ll sum = 0;
    for(int i = 1 ; i <= n ; ++i){
        sum += a[i];
        if(k >= (ll)a[i] * i - sum){
            res = min(res , CanHave(k - ((ll)a[i] * i - sum)) - a[i]);
        }
    }
    for(int i = 1 ; i <= n ; ++i)a[i] = 1e9 + 1 - a[i];
    sort(a + 1 , a + n + 1);
    for(int i = n ; i >= 1 ; --i)tot[i] = tot[i + 1] + a[i];
    sum = 0;
    for(int i = 1 ; i <= n ; ++i){
        sum += a[i];
        if(k >= (ll)a[i] * i - sum){
            res = min(res , CanHave(k - ((ll)a[i] * i - sum)) - a[i]);
        }
    }
    cout << max(res ,0 );
}

