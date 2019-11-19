#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        Int A[2] = {}, B[2] = {};
        for (int i = 0; i < N; i++) {
            int p; cin >> p;
            A[p % 2]++;
        }
        int M; cin >> M;
        for (int i = 0; i < M; i++) {
            int q; cin >> q;
            B[q % 2]++;
        }
        cout << A[0] * B[0] + A[1] * B[1] << endl;
    }
    return 0;
}