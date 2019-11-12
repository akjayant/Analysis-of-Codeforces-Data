#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

using ll = long long;

seed_seq seq {
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(
    	chrono::high_resolution_clock::now().
    	time_since_epoch()).count(),
    (uint64_t) __builtin_ia32_rdtsc(),
    (uint64_t) random_device{}(),
    (uint64_t) 17
};

mt19937 rd{seq};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    auto v = vector<vector<int>>();

    for (int i = 1; i <= n; i++) {
        v.emplace_back();
        for (int j = i; j <= n*n; j += n) {
            v.back().push_back(j);
        }
    }

    for (int i = 0, j = n-1; j > i; i++, j--) {
        for (int k = 0; k < n/2; k++) {
            swap(v[i][k], v[j][k]);
        }
    }

    for (auto const& vv : v) {
        for (int i : vv) cout << i  << " ";
        cout << "\n";
    }
}