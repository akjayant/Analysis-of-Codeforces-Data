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

int main() {
    ios::sync_with_stdio(false);
    int cas;
    cin >> cas;
    while (cas--) {
        vector<int> A(3);
        for (int i = 0; i < 3; i++)
            cin >> A[i];
        int ans = 0;
        while (A[2] >= 2 && A[1] >= 1) {
            A[2] -= 2;
            A[1] -= 1;
            ans += 3;
        }
        while (A[1] >= 2 && A[0] >= 1) {
            A[1] -= 2;
            A[0] -= 1;
            ans += 3;
        }
        cout << ans << endl;
    }
    return 0;
}
