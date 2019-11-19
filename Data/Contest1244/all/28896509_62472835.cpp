#pragma GCC optimize "03"
#include "bits/stdc++.h"
using namespace std;
 
#define int long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, ans, c = 0;
string s;

signed main() {
    IOS;
    #ifdef LOCAL
        freopen("input.txt","r", stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;  cin >> t;
    while(t--){
        ans = n;   
        cin >> n;
        cin >> s;
        int mi = 10000000, mx = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1')
                mi = min(mi, i+1), mx = max(mx, i+1);
        }
        ans = max(2*(n-mi+1), 2*mx);
        if(mx == 0) ans = n;
        cout << ans << endl;
    }   
    return 0;
}