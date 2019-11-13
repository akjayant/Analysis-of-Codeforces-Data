#include "bits/stdc++.h"

#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
#define exp 2.718281
#define ends asd
#define ld long double
#define ii pair<int, int>
#define pb push_back
using namespace std;

const long long INF = 1e18;
const int MNOGO = 2e9;
const long long MD = 1e9 + 7;
const double EPS = 1e-10;


struct segmentTree{
    int tl = 1, tr = (1ll << 21);
    segmentTree* left = nullptr;
    segmentTree* right = nullptr;
    int val = 0;
    int push = 0;
    segmentTree(int tl, int tr) : tl(tl), tr(tr) {}
    segmentTree() = default;
    void createSons(){
        int tm = (tl + tr)/2;
        if (!left){
            left = new segmentTree(tl, tm);
        }
        if (!right){
            right = new segmentTree(tm + 1, tr);
        }
    }
    void doPush(){
        createSons();
        if (push){
            left -> push += push;
            right -> push += push;
            val = push;
            push = 0;
        }
    }
    void updateRange(int l, int r, int val){
        doPush();
        if (l > r){
            return;
        }
        if (tl == l && r == tr){
            push = val;
            doPush();
            return;
        }
        createSons();
        int tm = (tl + tr)/2;
        left -> updateRange(l, min(r, tm), val);
        right -> updateRange(max(tm + 1, l), r, val);
        this -> val = max(left -> val , right -> val);
    }
    void update(int pos, int val){
        doPush();
        if (tl == tr){
            this -> val = max(this -> val, val);
            return;
        }
        createSons();
        int tm = (tl + tr)/2;
        if (pos <= tm){
            left -> update(pos, val);
        } else {
            right -> update(pos, val);
        }
        this -> val = max(left -> val, right -> val);
    }
    int get(int l, int r){
        doPush();
        if (l > r){
            return 0;
        }
        if (l == tl && tr == r){
            return val;
        }
        int tm = (tl + tr)/2;
        return max(left -> get(l, min(r, tm)) , right -> get(max(tm + 1, l), r));
    }

};
template <typename T>
ostream& operator<<(ostream& stream, const vector<T>& v){
    for (auto i: v){
        stream << i << " ";
    }
    return stream;
}
bool operator<(const pair<int, int>& p1, const pair<int,int>& p2){
    if (p1.fi < p2.fi) return true;
    if (p1.fi > p2.fi) return false;
    return p1.se < p2.se;
}

int n;
signed main() {
    fast;

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a.begin() + 1, a.end());
        int ans = 0;
        for (int i = 1; i <= n; i++){
            int cnt = n - i + 1;
            int cur = min(cnt, a[i]);
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }







}
/*
4
100 1
15 15
20 5
1 100
 */