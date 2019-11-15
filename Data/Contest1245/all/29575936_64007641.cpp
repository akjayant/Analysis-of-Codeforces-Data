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
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    int m = 1e9 + 7;
    cin >> str;
    int n = str.size();
    int has_n = 0, has_m = 0, has_u = 0, has_w = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'n')
            has_n = 1;
        else if (str[i] == 'm')
            has_m = 1;
        else if (str[i] == 'u')
            has_u = 1;
        else if (str[i] == 'w')
            has_w = 1;
    }
    if (has_n && has_m) {
        cout << 0 << endl;
    } else if (has_u && has_w) {
        cout << 0 << endl;
    } else {
        vector<int> A(n + 1, 0);
        A[0] = 1;
        for (int i = 1; i <= n; i++) {
            A[i] = A[i-1];
            if (i >= 2 && str[i-1] == 'u' && str[i-2] == 'u')
                A[i] += A[i-2];
            else if (i >= 2 && str[i-1] == 'n' && str[i-2] == 'n')
                A[i] += A[i-2];
            A[i] %= m;
        }
        cout << A[n] << endl;
    }
    return 0;
}
