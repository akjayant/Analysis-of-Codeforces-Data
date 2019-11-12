#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)(x).size())
#define whole(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const int N = int(1e5) + 2;
const int LG = 20;
const ll mod = (int)1e9 + 7;
const int INF = (int)1e9 + 7;
const ll linf = 1e13;
const ld pi = acos(-1);
const int base = 10;
const ld EPS = 1e-9;

int tt;
map < char, int > cnt;
int main (){
    cin >> tt;
    while (tt--){
        cnt.clear();
        int n;
        string s, t;
        cin >> n;
        cin >> s >> t;
        for (int i = 0; i < sz(s); ++i) cnt[s[i]]++, cnt[t[i]]++;
        bool ok = 1;
        for (int i = 0; i < sz(s); ++i){
            if (cnt[s[i]] & 1 || cnt[t[i]] & 1){
                ok = 0;
                break;
            }
        }
        if (!ok){
            cout << "No\n";
            continue;
        }
        vector < pii > res;
        for (int i = 0; i < sz(s); ++i){
            if (s[i] == t[i]) continue;
            char goal = s[i];
            for (int j = i + 1; j < sz(s); ++j){
                if (s[j] == goal){
                    swap(t[i], s[j]);
                    res.pb({j + 1, i + 1});
                    break;
                }
                else {
                    if (t[j] == goal){
                        swap(t[j], s[j]);
                        swap(t[i], s[j]);
                        res.pb({j + 1, j + 1});
                        res.pb({j + 1, i + 1});
                        break;
                    }
                }
            }
        }
        //cout << s << " " << t << "\n";
        cout << "Yes\n" << sz(res) << "\n";
        for (auto to : res) cout << to.fi << " " << to.se << "\n";
    }
    return 0;
}
