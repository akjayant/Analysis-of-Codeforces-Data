#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector <int> h(n);
        for (int& i : h)
            cin >> i;
        sort(h.begin(), h.end());

        int cnt = 0, i = (int) h.size() - 1;
        while (i >= 0 && h[i] > cnt)
            i--, cnt++;
        cout << cnt << endl;
    }
    return 0;
}
