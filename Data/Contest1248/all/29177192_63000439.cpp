#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios::sync_with_stdio(false);
    int n;long long l = 0,w = 0;cin >> n;vector<int> a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(),a.end());
    for (int i = 0;i < n / 2;i++) l += a[i];
    for (int i = n / 2;i < n;i++) w += a[i];
    cout << l * l + w * w << endl;
    return 0;
}