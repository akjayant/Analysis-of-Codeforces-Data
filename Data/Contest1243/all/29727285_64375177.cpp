#include <bits/stdc++.h>

using namespace std;

template<typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T> p) {
    out << "(" << p.first << "," << p.second << ")";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (auto a: v)
        out << a << " ";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const set<T>& S) {
    for (auto a: S)
        cout << a << " ";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const multiset<T>& S) {
    for (auto a: S)
        cout << a << " ";
    return out;
}

template<typename S, typename T>
ostream& operator<<(ostream& out, const map<S, T>& M) {
    for (auto m: M)
        cout << "(" << m.first << "->" << m.second << ") ";
    return out;
}

template<typename S, typename T>
pair<S, T> operator+(pair<S, T> a, pair<S, T> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

template<typename S, typename T>
pair<S, T> operator-(pair<S, T> a, pair<S, T> b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

int solve(vector<int>& A) {
    int n = A.size();
    int ans = 0;
    sort(A.begin(), A.end(), greater<int>());
    int min_val = A[0];
    for (int i = 0; i < n; i++) {
        min_val = min(min_val, A[i]);
        if (min_val >= i + 1)
            ans = max(ans, i + 1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cas, n;
    vector<int> A;
    cin >> cas;
    while (cas--) {
        cin >> n;
        A.resize(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        int ans = solve(A);
        cout << ans << endl;
    }
    return 0;
}
