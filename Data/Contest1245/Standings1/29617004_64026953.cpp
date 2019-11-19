#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
int l, r;
ll mem[32][2][2][2][2];
ll C(int i, bool lba, bool uba, bool lbb, bool ubb) {
    ll& ans = mem[i+1][lba][uba][lbb][ubb];
    if(ans == -1) {
        if(i == -1) {
            ans = 1;
        } else {
            ans = 0;
            int li = (l >> i) & 1, ri = (r >> i) & 1;
            for(int ai : {0, 1}) {
                for(int bi : {0, 1}) {
                    if((ai + bi) == (ai ^ bi) 
                    and (not lba or li <= ai) and (not uba or ai <= ri)
                    and (not lbb or li <= bi) and (not ubb or bi <= ri)) {
                        ans += C(i - 1, lba and li == ai, uba and ri == ai, 
                                        lbb and li == bi, ubb and ri == bi);
                    }
                }
            }
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // for(int i = 0; i < 4; i++) {
    //     for(int j = 0; j < 4; j++) {
    //         cout << bitset<2>(i) << " + " << bitset<2>(j) << ((i + j) == (i ^ j) ? " == " : " != ") << bitset<2>(i) << " ^ " << bitset<2>(j) << endl;
    //     }
    // }
    int t;
    cin >> t;
    while(t--) {
        cin >> l >> r;
        memset(mem, -1, sizeof mem);
        cout << C(30, true, true, true, true) << endl;
    }
    return 0;
}
