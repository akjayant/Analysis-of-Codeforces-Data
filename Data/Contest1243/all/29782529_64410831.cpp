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
int cnt[30];
int color[10000000];
signed main() {
    fast;

    int t = 1;
//    cin >> t;
    while (t--) {
//        int n = t;
        cin >> n;
        if (n == 1){
            cout << 1 << endl;
            continue;
        }
        int div = 0;
        vector<int> v,v2;
        int g = 0;
        int wasN = n;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                while (n % i == 0){
                    n/=i;
                }
                v.push_back(i);
            }
        }
        if (n > 1){
            v.push_back(n);
        }
        n = wasN;
//        for (int i = 2; i <= sqrt(n); i++){
//            if (n % i == 0){
//                v2.push_back(i);
//                v2.push_back(n/i);
//            }
//        }
//        sort(v2.begin(), v2.end());
//        int mxcolor = 0;
//        for (int i = 1; i <= n; i++) {
//            int c = color[i];
//
//            set<int> s;
//            if (c) {
//                s.insert(color[i]);
//            }
//            for (auto j:v2) {
//                if (i + j > n) {
//                    break;
//                }
//                if (color[i + j]){
//                    s.insert(color[i + j]);
//                }
//            }
//            if (c == 0){
//                c = mxcolor + 1;
//                s.insert(c);
//                mxcolor++;
//            }
//            for (int j = 1; j <= n; j++){
//                if (s.find(color[j]) != s.end()){
//                    color[j] = *s.begin();
//                }
//            }
//
//            color[i] = *s.begin();
//            for (auto j:v2) {
//                if (i + j > n) {
//                    break;
//                }
//                color[i + j] = *s.begin();
//            }
//        }
////        cout << mxcolor << endl;
//        set<int> s;
//        for (int i = 1; i <= n; i++) {
////            cout << color[i] << " ";
//            s.insert(color[i]);
//            color[i] = 0;
//
//        }
////        cout << endl;
////        cout << s.size() << endl;
//        if (s.size() != 2) {
////            cout << n << " " << v.size() << endl;
//        }
        int myans = v[0];
        if (v.size() >= 2){
            myans = 1;
        }
        cout << myans << endl;
//        if (myans != s.size() && myans != -1){
//            cout << myans << " " << s.size() << " " << n << endl;
//        }
    }







}
/*
4
100 1
15 15
20 5
1 100
 */