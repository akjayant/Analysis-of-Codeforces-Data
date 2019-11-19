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

int n , m;
int p[maxn] , q[maxn];

void Solve(){
    cin >> n;
    int cnt[2] = {0 , 0};
    for(int i = 1 ; i <= n ; ++i){
        int x;cin >> x;
        cnt[x & 1]++;
    }
    int cnt1[2] = {0 , 0};
    cin >> m;
    for(int i = 1 ; i <= m ; ++i){
        int x;cin >> x;
        cnt1[x & 1]++;
    }
    cout << (ll)cnt[0] * cnt1[0] + (ll)cnt[1] * cnt1[1] << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
        freopen(taskname".INP", "r",stdin);
        freopen(taskname".OUT", "w",stdout);
    }
    int t;cin >> t;
    while(t--){
        Solve();
    }
}
