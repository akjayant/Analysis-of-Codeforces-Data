#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

using ll = long long;
using ii = pair<int, int>;

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

    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int ans = 0;
        for (int i = 0; a >= i and b >= 2*i; i++) {
            for (int j = 0; b >= j + 2*i and c >= 2*j; j++) {
                ans = max(ans, 3*i + 3*j);
            }
        }

        cout << ans << "\n";
    }
}