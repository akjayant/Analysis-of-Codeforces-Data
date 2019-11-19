#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<int> A(N); for (auto &a : A) cin >> a;
    sort(begin(A), end(A));
    Int x = 0, y = 0;
    for (int i = 0; i < A.size() / 2; i++) {
        x += A[i];
    }
    for (int i = A.size() / 2; i < A.size(); i++) {
        y += A[i];
    }
    cout << x * x + y * y << endl;
    return 0;
}