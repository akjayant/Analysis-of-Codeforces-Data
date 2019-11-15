#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    clock_t begin_time = clock();

    int n;
    cin >> n;

    vector<vector<int>> ans(n);

    bool inc = true;

    int val = 1;
    for (int i = 0; i < n; ++i) {
        if (inc) {
            for (int j = 0; j < n; ++j) {
                ans[j].push_back(val++);
            }
        } else {
            for (int j = n - 1; j >= 0; --j) {
                ans[j].push_back(val++);
            }
        }
        inc = !inc;
    }

    // Print answer
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    // Print exec time
    clock_t end_time = clock();
    double elapsed_secs = double(end_time - begin_time) / CLOCKS_PER_SEC;
    cerr << "Exec time: " << elapsed_secs << " s" << endl;
}
