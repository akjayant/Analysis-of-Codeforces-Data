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

const int maxn = 3e5 + 5;
int n , a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
        freopen(taskname".INP", "r",stdin);
        freopen(taskname".OUT", "w",stdout);
    }
    cin >> n;
    int sum = 0 , sum1 = 0;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1 , a + n + 1);
    ll res = 0;
    for(int i = 1 ; i <= n / 2 ; ++i)sum1 += a[i];
    sum = sum - sum1;
    cout << (ll)sum * sum + (ll)sum1 * sum1;
}
