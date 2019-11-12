#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) if(DEBUG) cout << #x _ "=" _ x << endl
#define TRACE_VEC(v) if(DEBUG){ cout << #v << _ "="; for(auto e : v) cout _ e; cout << endl; }
#define _ << " " <<
#define endl "\n"
#define IN_VEC(v, n) int temp_inv_var; REP(i, n){ cin >> temp_inv_var; v.push_back(temp_inv_var); }
#define IN_ARR(a, n) REP(i, n) cin >> (a)[i]
#define ll int64_t
#define i32 int32_t

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;

int has_l(const string & s, char c, int k0){
    FOR(k, k0+1, n){
        if(s[k] == c) return k;
    }
    return -1;
}

void swap(string & s, string & t, int i, int j){
    char tmp = s[i];
    s[i] = t[j];
    t[j] = tmp;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    string s; string t;
    int k;
    cin >> k;
    REP(mm, k){
        cin >> n;
        cin >> s;
        cin >> t;
        vector<pii > ex;
        bool ok = true;
        REP(i, n){
            if(s[i] != t[i]){
                //cout << i _ s _ t << endl;
                int it = has_l(s, s[i], i);
                if(it != -1){
                    ex.push_back({it, i});
                    swap(s, t, it, i);
                }
                else{
                    it =  has_l(t, s[i], i);
                    if(it != -1){
                        ex.push_back({i+1, it});
                        ex.push_back({i+1, i});
                        swap(s, t, i+1, it);
                        swap(s, t, i+1, i);
                    }
                    else{
                        ok = false;
                        break;
                    }
                }
                //cout << s _ t << endl;
            }
        }
        if(!ok){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
            cout << ex.size() << endl;
            for(auto p : ex){
                cout << p.first + 1 _ p.second + 1 << endl;
            }
        }
    }
}
