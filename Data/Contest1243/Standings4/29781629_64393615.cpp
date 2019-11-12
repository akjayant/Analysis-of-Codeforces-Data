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
        vector<int> v(27, 0);
        rep(i, n){
            v[s[i]-'a']++;
            v[t[i]-'a']++;
        }
        bool f = false;
        rep(i, 26){
            if(v[i] % 2 != 0){
                f = true;
                break;
            }
        }
        if(f){
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        vector<pair<int,int>> res;
        for(int i = 0; i < n; i++){
            if(s[i] == t[i])
                continue;
            int need = -1;
            for(int j = i + 1; j < n; j++){
                if(t[j] == s[i]){
                    need = j;
                    break;
                }
            }
            if(need != -1){
                res.eb(i+1, need);
                swap(s[i+1], t[need]);
                res.eb(i+1, i);
                swap(s[i+1], t[i]);
            }else{
                for(int j = i + 1; j < n; j++){
                    if(s[j] == s[i]){
                        need = j;
                        break;
                    }
                }
                res.eb(need, i);
                swap(s[need], t[i]);
            }
        }
        cout << res.size() << '\n';
        for(auto [x, y] : res){
            cout << x+1 << " " << y+1 << '\n';
        }
    }
}
















