#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

char s[200];

void solve(){
    int n, rk, pa, sc;
    cin >> n >> rk >> pa >> sc;
    int brk = 0, bpa = 0, bsc = 0;
    cin >> (s+1);
    rep(i, 1, n){
        if (s[i] == 'R') brk++;
        else if (s[i] == 'P') bpa++;
        else bsc++;
    }
    int win = 0;
    win = std::min(brk, pa) + std::min(bpa, sc) + std::min(bsc, rk);
    if (win*2 >= n){
        cout << "YES\n";
        int freepa = pa - std::min(brk, pa), freesc = sc - std::min(bpa, sc),  freerk = rk - std::min(bsc, rk);
        pa = std::min(brk, pa), sc = std::min(bpa, sc), rk = std::min(bsc, rk);
        rep(i, 1, n){
            if (s[i] == 'R' && pa > 0) { cout << 'P'; pa--; continue; }
            if (s[i] == 'P' && sc > 0) { cout << 'S'; sc--; continue; }
            if (s[i] == 'S' && rk > 0) { cout << 'R'; rk--; continue; }
            if (freepa){cout << 'P'; freepa--;}
            else if (freesc){cout << 'S'; freesc--;}
            else {cout << 'R'; freerk--;}
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
