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
    int cas;
    cin >> cas;
    while (cas--) {
        int n;
        string str;
        vector<int> A(3, 0);
        cin >>  n;
        cin >> A[0] >> A[1]  >> A[2];
        cin >> str;
        string ans(n, ' ');
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (str[i] == 'R' && A[1]) {
                ans[i] = 'P';
                A[1]--;
                cnt++;
            } else if (str[i] == 'P' && A[2]) {
                ans[i] = 'S';
                A[2]--;
                cnt++;
            } else if (str[i] == 'S' && A[0]) {
                ans[i] = 'R';
                A[0]--;
                cnt++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] == ' ') {
                if (A[0]) {
                    ans[i] = 'R';
                    A[0]--;
                } else if (A[1]) {
                    ans[i] = 'P';
                    A[1]--;
                } else if (A[2]) {
                    ans[i] = 'S';
                    A[2]--;
                }
            }
        }
        if (cnt >= (n + 1) / 2) {
            cout << "YES" << endl;
            cout << ans << endl;
        } else {
            cout  << "NO" << endl;
        }
    }
    return 0;
}
