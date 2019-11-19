//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define sqr(a) (a * a)
#define ll long long
#define ull unsigned long long
using namespace std;

#define mod 1000000007

string go_ok(string s) {
    vector<int> st;
    string sst;
    int fst = -1;
    int bal = 0;
    for (int i = 0; i < s.size(); ++i) {
        char ch = s[i];
        if (!sst.size()) {
            st.push_back(i);
            sst.push_back(ch);
        }
        else if (sst.back() == '(' && ch == ')') {
            st.pop_back();
            sst.pop_back();
        }
        else {
            st.push_back(i);
            sst.push_back(ch);
        }
        bal += ch == '(' ? 1 : -1;
    }
    if (bal)
        return "#";
    for (int i : st) {
        if (s[i] == '(') {
            fst = i - 1;
            break;
        }
    }
    if (fst == -1)
        return s;
    return s.substr(fst + 1, s.size() - fst - 1) + s.substr(0, fst + 1);
}

int cnt(string &s) {
    s = go_ok(s);
    if (s == "#")
        return 0;
    int bal = 0;
    int ans = 0;
    for (char ch : s) {
        bal += ch == '(' ? 1 : -1;
        if (bal == 0) {
            ++ans;
        }
    }
    return ans;
}

void solve() {
    string s;
    cin >> s >> s;

    int ans = 0;
    int id1 = 1, id2 = 1;

    for (int i = 0; i < s.size(); ++i)
        for (int j = i; j < s.size(); ++j) {
            if (i == 2 && j == 11) {
                int jkd = 0;
            }
            string s2 = s;
            swap(s2[i], s2[j]);
            int tmp = cnt(s2);
            if (tmp > ans) {
                ans = tmp;
                id1 = i + 1;
                id2 = j + 1;
            }
        }
    
    cout << ans << '\n' << id1 << ' ' << id2 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}