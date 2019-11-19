#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<long long> A(n);
    for(int i=0; i<n; ++i) cin >> A[i];
    sort(begin(A), end(A));

    long long x = accumulate(begin(A), begin(A) + n / 2, 0LL);
    long long y = accumulate(begin(A) + n / 2, end(A), 0LL);
    cout << x * x + y * y << '\n';
}