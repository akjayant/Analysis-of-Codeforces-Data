#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    clock_t begin_time = clock();

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;

        int ans = 0;
        int z1 = min(z/2, y);
        int y1 = min(y/2, x);
        int z2 = min((y - z1) / 2, x);
        int y2 = min(z / 2, y - (y1 * 2));

        ans = max(z1 + z2, y1 + y2)*3;

        cout << ans << "\n";
    }

    // Print exec time
    clock_t end_time = clock();
    double elapsed_secs = double(end_time - begin_time) / CLOCKS_PER_SEC;
    cerr << "Exec time: " << elapsed_secs << " s" << endl;
}
