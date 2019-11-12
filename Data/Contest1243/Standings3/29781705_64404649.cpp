#include <bits/stdc++.h>
#define PI 2*asin(1)
#define int long long
#define mod 1000000007
#define all(a) begin(a),end(a)
#define fore(i, j, n) for(long long i = j; i < n;i++)

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int qwe; cin >> qwe;
    while(qwe--) {
        int n; cin >> n;
        int used[27];
        fore(i,0,26) used[i] = 0;
        string s,t; cin >> s >> t;
        fore(i,0,n){
            used[(int)s[i] - (int)('a')]++;
            used[(int)t[i] - (int)('a')]++;
        }
        bool flag = true;
        fore(i,0,26) {
            if (used[i] % 2 == 1 && used[i] != 0) {
                flag = false;
                cout << "No\n";
                break;
            }
        }
        vector<pair<int,int>>res;
        if(flag){
            fore(i,0,n){
                bool use = false;
                if(s[i] != t[i]){
                    fore(j, i + 1, n){
                        if(s[i] == s[j] && s[j] != t[j]){     // saaaah
                            res.push_back({j + 1,i + 1});
                            swap(s[j],t[i]);// haaaas
                            use = true;
                            break;
                        }
                    }
                    if(!use){
                        fore(j, i + 1, n){
                            if(s[i] == t[j] && s[j] != t[j]){
                                res.push_back({j+1,j+1});
                                res.push_back({j + 1,i + 1});
                                swap(s[j],t[j]);
                                swap(s[j],t[i]);
                                break;
                            }
                        }
                    }
                }
            }
            cout << "Yes\n";
            cout << res.size() << '\n';
            for(auto i: res) cout << i.first << ' ' << i.second <<'\n';
        }

    }
}