#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long   ll;
typedef long double ld;

#define all(x)  (x).begin(), (x).end()
#define sz(x)   (x).size()
#define pb      push_back
#define mp      make_pair
#define fr      first
#define sc      second

const int N = 100 * 1000 + 5;

int k, n[20];
vector<vector<ll>> elems;
ll oversum = 0, colsum[20], each;
unordered_map<ll, int> cols;

void input() {
    cin >> k;
    elems.resize(k);
    for(int i = 0; i < k; i++) {
        cin >> n[i];
        elems[i].resize(n[i]);
        for(int j = 0; j < n[i]; j++) {
            cin >> elems[i][j];
            cols[elems[i][j]] = i;
            colsum[i] += elems[i][j];
            oversum += elems[i][j];
        }
    }
}

vector<vector<pair<int, ll>>> cycles;

void simulate(int ni, ll elem) {
    vector<ll> tmpsums(colsum, colsum + k);
    vector<pair<int, ll>> res {};
    res.emplace_back(ni, elem);
    while(tmpsums[ni] != each) {
        ll needed = each - (tmpsums[ni] - elem);
        if (cols.find(needed) == cols.end()) return;
        int newni = cols[needed];
        if (tmpsums[newni] == each || newni == ni) return;
        tmpsums[ni] = each;
        tmpsums[newni] += elem - needed;
        res.emplace_back(newni, needed);
        ni = newni;
    }
    // cout << sz(res) << endl;
    int mask = 0;
    for(auto& elem : res) {
        mask |= (1 << elem.first);
    }
    if (cycles[mask].empty()) {
        cycles[mask] = res;
    }
}

vector<int> all_masks;
vector<bool> gen;
vector<int> last_mask;

void solve() {
    if (abs(oversum) % k != 0) {
        puts("No");
        return;
    }
    each = oversum / k;
    cycles.resize((1 << k));
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n[i]; j++) {
            simulate(i, elems[i][j]);
        }
    }
    gen.resize((1 << k), false);
    gen[0] = true;
    last_mask.resize((1 << k));
    for(int mask = 0; mask < (1 << k); mask++) {
        if (!cycles[mask].empty()) {
            all_masks.pb(mask);
            // cout << "For mask " << mask << "\n";
            // for(auto& elem : cycles[mask]) { cout << elem.fr << " " << elem.sc << "\n"; }
        }
    }
    for(int i = 1; i < (1 << k); i++) {
        for(int mask : all_masks) {
            if ((i & mask) == mask && gen[i ^ mask]) {
                gen[i] = true;
                last_mask[i] = mask;
                break;
            }
        }
    }
    if (gen[(1 << k) - 1]) {
        puts("Yes");
        int msk = (1 << k) - 1;
        vector<pair<ll, int>> moves(k);
        while(msk != 0) {
            // cout << last_mask[msk] << " ";
            int tmp_msk = last_mask[msk];
            int ssz = sz(cycles[tmp_msk]);
            for(int i = 0; i < ssz; i++) {
                moves[cycles[tmp_msk][i].fr] = mp(cycles[tmp_msk][i].sc, cycles[tmp_msk][(i - 1 + ssz) % ssz].fr + 1);
                // cout << cycles[tmp_msk][i].sc << " " << cycles[tmp_msk][(i - 1 + ssz) % ssz].fr + 1 << endl;
            }
            msk ^= last_mask[msk];
        }
        for(auto& elem : moves) {
            cout << elem.fr << " " << elem.sc << endl;
        }
    }
    else {
        puts("No");
    }





}

int main() {
    int testcases = 1;
    // scanf("%d", &testcases);
    while(testcases--) {
        input();
        solve();
    }
    return 0;
}