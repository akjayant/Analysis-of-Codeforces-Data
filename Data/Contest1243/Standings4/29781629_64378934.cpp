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
    string s, t;
    cin >> k;
    while(k--){
        cin >> n;
        cin >> s >> t;
        vector<int> v;
        rep(i, n){
            if(s[i] != t[i])
                v.pb(i);
        }
        if(v.size() > 2 || v.size() == 1){
            cout << "No\n";
            continue;
        }
        if(v.empty()){
            cout << "Yes\n";
            continue;
        }
        int i = v[0], j = v[1];
        if(s[i] == s[j] && t[i] == t[j]){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
}
















