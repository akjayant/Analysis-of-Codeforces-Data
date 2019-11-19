#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define pb push_back
using namespace std;
const ll MOD = 1e9 + 7;
signed main() {
    ios_base::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pair<ll, ll> > A(k);
    map<ll, vector<ll> > huhx, huhx2, huhy, huhy2;
    for(ll i = 0  ; i < k ; i++) {
        cin >> A[i].F >> A[i].S;
        A[i].F--, A[i].S--;
        huhx[A[i].F].pb(A[i].S);
        huhy[A[i].S].pb(A[i].F);
    }
    for(auto huh : huhx) {
        huhx2[huh.F] = huh.S;
        sort(huhx2[huh.F].begin(), huhx2[huh.F].end());
    }
    for(auto huh : huhy) {
        huhy2[huh.F] = huh.S;
        sort(huhy2[huh.F].begin(), huhy2[huh.F].end());
    }
    huhx = huhx2;
    huhy = huhy2;
    
    array<ll, 3> cur = {0, 0, 0};
    ll e = 0;
    ll col = 1;
    ll add = 1;
    ll Lx = -1, Ly = -1, Rx = n, Ry = m; 
    ll fuu = 0;
    while(add > 0 || fuu == 1) {
        ////cerr << cur[0] << " " << cur[1] << " " << cur[2] << " " << Lx << " " << Ly << " " << Rx << " " << Ry << endl;
        if(cur[2] == 0) {
            Lx = cur[0];
            if(huhx.count(cur[0])) {
            auto it = lower_bound(huhx[cur[0]].begin(), huhx[cur[0]].end(), cur[1]);
            if(it == huhx[cur[0]].end()) 
                e = Ry - 1;
            else
                e = min(Ry - 1, *it - 1);
            } else e = Ry - 1;
            add = e - cur[1];
            cur[1] = e;
        } else if(cur[2] == 1) {
            Ry = cur[1];
            if(huhy.count(cur[1])) {
            auto it = lower_bound(huhy[cur[1]].begin(), huhy[cur[1]].end(), cur[0]);
            if(it == huhy[cur[1]].end()) 
                e = Rx - 1;
            else
                e = min(Rx - 1, *it - 1);
            } else e = Rx - 1;
            add = e - cur[0];
            cur[0] = e;
        } else if(cur[2] == 2) {
            Rx = cur[0];
            if(huhx.count(cur[0])) {
            auto it = lower_bound(huhx[cur[0]].begin(), huhx[cur[0]].end(), cur[1]);
            if(it == huhx[cur[0]].begin())
                e = Ly + 1;
            else
                e = max(Ly + 1, *prev(it) + 1);
            } else e = Ly + 1;
            add = cur[1] - e;
            cur[1] = e;
        } else if(cur[2] == 3) {
            Ly = cur[1];
            if(huhy.count(cur[1])) {
            auto it = lower_bound(huhy[cur[1]].begin(), huhy[cur[1]].end(), cur[0]);
            if(it == huhy[cur[1]].begin()) 
                e = Lx + 1;
            else
                e = max(*prev(it) + 1, Lx + 1);
            } else e =  Lx + 1;
            add = cur[0] - e;
            cur[0] = e;
        }
        cur[2] = (cur[2] + 1) & 3;
        fuu++;
        col += add;
    }
    //cerr << cur[0] << " " << cur[1] << " " << cur[2] << " " << Lx << " " << Ly << " " << Rx << " " << Ry << endl;
    //cerr << col << " " << n * m - k <<endl;
    if(col != n * m - k) cout << "No";
    else cout << "Yes";
    return 0;
}