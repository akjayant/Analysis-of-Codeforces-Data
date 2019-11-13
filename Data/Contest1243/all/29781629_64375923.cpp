//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
//#include <optimization.h>
#pragma GCC optimize("O3")
#define chervyak 6
#define sasha chervyak
#define y1 jhgfds
#define prev maAslo
#define ll long long
#define ull uint64_t
#define ld long double
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//cout << clock()*1000/CLOCKS_PER_SEC << '\n';


int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k, n;
    cin >> k;
    while(k--){
        cin >> n;
        vector<int> a;
        rep(i, n){
            int x;
            cin >> x;
            a.pb(x);
        }
        sort(all(a));
        int res = 0;
        rep(i, n){
            int ost = n - i;
            res = max(res, min(ost, a[i]));
        }
        cout << res << '\n';
    }
}
















