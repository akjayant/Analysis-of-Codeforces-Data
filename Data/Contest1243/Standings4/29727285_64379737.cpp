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

bool solve(string& str1, string& str2) {
    int n = str1.size();
    vector<int> A;
    for (int i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            A.push_back(i);
        }
    }
    /*
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "A: " << A << endl;
    */
    if (A.empty())
        return true;
    if (A.size() == 2) {
        int a = A[0];
        int b = A[1];
        if (str1[a] == str1[b] && str2[a] == str2[b])
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cas, n;
    string str1, str2;
    cin >> cas;
    while (cas--) {
        cin >> n >> str1 >> str2;
        bool ans = solve(str1, str2);
        if (ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
