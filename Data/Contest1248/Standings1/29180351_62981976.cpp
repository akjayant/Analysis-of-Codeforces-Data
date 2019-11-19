#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; ++i)
        cin >> A[i];
    sort(A.begin(), A.end());
    long long x = 0, y = 0;
    for(int i = 0; i < A.size() / 2; ++i)
        x += A[i];
    for(int i = A.size()/2; i < A.size(); ++i)
        y += A[i];
    cout << x * x + y * y << endl;
    return 0;
}
