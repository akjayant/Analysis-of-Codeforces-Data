#define IOS ios::sync_with_stdio(false);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int M = 3e5 + 7;
const int INF = 1e8 + 7;
ll mod = 998244353;

ll n, k;
int a[N];
map<int, int> mp;

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++ i) scanf("%d", &a[i]), mp[a[i]] ++;
    vector<int> g;
    for(auto iter = mp.begin(); iter != mp.end(); iter ++) g.push_back(iter->first);
    if(mp.size() == 1){
        cout << 0 << endl;
        return 0;
    }
    int l = 0, r = g.size() - 1;
    int lv = g[l], rv = g[r];
    int lc = mp[g[l]], rc = mp[g[r]];
    while(k >= min(lc, rc) && l != r){
        if(lc < rc){
            ll d = g[l+1] - g[l];
            ll add = k / lc;
            int down = 0;
            if(add < d) down = 1;
            add = min(d, add);

            k -= add * lc;
            lv = lv + add;
            lc += mp[g[++ l]];
            if(down) break;

        }else{
            ll d = g[r] - g[r-1];
            ll add = k / rc;
            int down = 0;
            if(add < d) down = 1;
            add = min(d, add);

            k -= add * rc;
            rv = rv - add;
            rc += mp[g[-- r]];
            if(down) break;
        }
    }
    cout << rv - lv << endl;

    return 0;
}