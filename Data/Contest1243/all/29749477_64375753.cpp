#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; ++i)
            cin >> vec[i];
        sort(vec.begin(), vec.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, min(vec[i], n - i));
        }
        cout << ans << '\n';
    }
    return 0;
}