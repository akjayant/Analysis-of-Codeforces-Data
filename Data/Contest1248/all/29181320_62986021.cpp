// ml:run = $bin < input
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long odd1 = 0;
        long long even1 = 0;
        long long odd2 = 0;
        long long even2 = 0;

        int n;
        cin >> n;
        vector<int> vd(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> vd[i];
            if (vd[i] % 2 == 1) ++odd1;
            else ++even1;
        }
        int m;
        cin >> m;
        vector<int> vj(m, 0);
        for (int i = 0; i < m; ++i) {
            cin >> vj[i];
            if (vj[i] % 2 == 1) ++odd2;
            else ++even2;
        }
        long long res = 0;
        res = even1 * even2 + odd1 * odd2;
        cout << res << '\n';
    }
}