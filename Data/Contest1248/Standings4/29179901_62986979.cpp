#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n; cin >> n;
    vector<int> v(n);
 
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
 
    int64_t ox = 0, oy = 0;
    for (int i = 0; i < n / 2; i++)
        ox += v[i];
    for (int i = n / 2; i < n; i++)
        oy += v[i];

    cout << ox * ox + oy * oy << '\n';
    return 0;
}
