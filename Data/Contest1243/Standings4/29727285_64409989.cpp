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

bool solve(string& str1, string& str2, vector<pair<int,int>>& A) {
    int n = str1.size();
    A.clear();
    for (int i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            for (int j = i + 1; j < n; j++) {
                if (str1[j] == str1[i]) {
                    swap(str1[j], str2[i]);
                    A.emplace_back(j, i);
                    break;
                }
            }
        }
        if (str1[i] != str2[i]) {
            for (int j = i + 1; j < n; j++) {
                if (str2[j] == str2[i]) {
                    swap(str1[i], str2[j]);
                    A.emplace_back(i, j);
                    break;
                }
            }
        }
        if (str1[i] != str2[i]) {
            for (int j = i + 1; j < n; j++) {
                if (str1[j] == str2[i]) {
                    swap(str1[j], str2[j]);
                    swap(str1[i], str2[j]);
                    A.emplace_back(j, j);
                    A.emplace_back(i, j);
                    break;
                }
            }
        }
        if (str1[i] != str2[i]) {
            for (int j = i + 1; j < n; j++) {
                if (str2[j] == str1[i]) {
                    swap(str1[j], str2[j]);
                    swap(str1[j], str2[i]);
                    A.emplace_back(j, j);
                    A.emplace_back(j, i);
                    break;
                }
            }
        }
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cas, n;
    string str1, str2;
    vector<pair<int,int>> A;
    cin >> cas;
    while (cas--) {
        cin >> n >> str1 >> str2;
        bool ans = solve(str1, str2, A);
        if (ans) {
            cout << "Yes" << endl;
            cout << A.size() << endl;
            for (auto p: A) {
                cout << p.first + 1 << " " << p.second + 1 << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
