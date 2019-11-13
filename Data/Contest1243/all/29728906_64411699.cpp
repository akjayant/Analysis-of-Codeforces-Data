#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;
#define ts(x)                       to_string(x)
#define ti(x)                       stoi(x)
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define mine(v)                     *min_element(all(v))
#define maxe(v)                     *max_element(all(v))
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define SIZE(x)                     (int)x.size()
#define endl                        "\n"
inline ll input(){ll n; cin >> n ; return n;}

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const ll INF = 8e18;

ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? (a * pw(a * a % MOD, b / 2)) % MOD : pw(a * a % MOD, b / 2))); }

int main(){
    fast_io;
    //cout << fixed << setprecision(15);
    //scanf("%d %d %f %lld %s %c", &x);
    //printf("%d %d %f %lld %s %c", x);
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        string s, s2, a, b;
        cin >> s >> s2;
        if(s == s2){
            cout << "Yes" << endl;
            continue;
        }
        bool ok = 1;
        map<string, int> mp1, mp2, mp;
        vector<pii> ans;
        vector<int> RI;
        for(int i = 0; i < n; i++){
            if(s[i] == s2[i]){
                continue;
            }
            else{
                a += string(1, s[i]);
                b += string(1, s2[i]);
                mp[string(1, s[i])]++;
                mp[string(1, s2[i])]++;
                RI.push_back(i);
            }
        }
        bool F = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->S % 2 != 0){
                cout << "No" << endl;
                F = 1;
                break;
            }
        }
        if(F){
            continue;
        }
        int m = (int)a.size();
        for(int i = 0; i < m; i++){
            if(a[i] == b[i]){
                continue;
            }
            int j, j2, k, k2;
            for(j = i + 1; j < m; j++){
                if(b[j] == a[i]){
                    break;
                }
            }
            for(j2 = i + 1; j2 < m; j2++){
                if(a[j2] == b[i]){
                    break;
                }
            }
            for(k = i + 1; k < m; k++){
                if(a[k] == a[i]){
                    break;
                }
            }
            for(k2 = i + 1; k2 < m; k2++){
                if(b[k2] == b[i]){
                    break;
                }
            }
            // j -> az a to b
            // j2 -> az b to a
            // k -> az a to a
            // k2 az b to b
            if(k != m){
                swap(b[i], a[k]);
                ans.push_back({RI[k] + 1, RI[i] + 1});
                continue;
            }
            if(k2 != m){
                swap(b[k2], a[i]);
                ans.push_back({RI[i] + 1, RI[k2] + 1});
                continue;
            }
            if(i == m - 1){
                ok = 0;
                continue;
            }
            if(j != m){
                swap(a[i + 1], b[j]);
                ans.push_back({RI[i + 1] + 1, RI[j] + 1});
                swap(a[i + 1], b[i]);
                ans.push_back({RI[i + 1] + 1,RI[i] + 1});
                continue;
            }
            if(j2 != m){
                swap(b[i + 1], a[j2]);
                ans.push_back({RI[j2] + 1, RI[i + 1] + 1});
                swap(b[i + 1], a[i]);
                ans.push_back({RI[i] + 1,RI[i + 1] + 1});
                continue;
            }
            ok = 0;
        }
        if(!ok || a != b){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
            cout << ans.size() << endl;
            for(auto x:ans){
                cout << x.F << " " << x.S << endl;
            }
        }
    }
    return 0;
}


