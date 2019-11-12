#include<bits/stdc++.h>

#define LL long long
using namespace std;
const long long mod = 1000000000 + 7;

int n;

vector<char> a, b;
int c[100];
int d[100];

int findnext(const string &S, char v, int start) {
    for (int i = start; i < n; i++) {
        if (S[i] == v) {
            return i;
        }
    }
    return -1;
}

vector<pair<int, int>> ans;

int main() {
    //freopen("C:\\Users\\93569\\Desktop\\untitled\\a.txt", "r", stdin);
//    freopen("s","r",stdin)
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        a.clear();
        b.clear();
        ans.clear();
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        string s, t;
        cin >> n;
        cin >> s;
        cin >> t;
        for (auto i:s) {
            c[i - 'a']++;
            d[i - 'a']++;
        }
        for (auto i:t) {
            c[i - 'a']++;
        }
        int flag = 0;
        for (int i = 0; i <= (int) ('z' - 'a'); i++) {
            if (c[i] % 2 == 1) {
                cout << "No" << endl;
                flag = 1;
                break;
            }
            c[i] /= 2;
            d[i] -= c[i];
        }
        if (flag == 1) continue;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[i]) {
                continue;
            }
            int p = findnext(s, s[i], i + 1);
            if (p != -1) {
                swap(s[p], t[i]);
                ans.push_back({p, i});
            } else {
                p = findnext(t, s[i], i);
                ans.push_back({i+1, p});
                swap(s[i+1],t[p]);
                ans.push_back({i+1, i});
                swap(s[i+1], t[i]);
            }
        }
        cout << "Yes" << endl;
        if (ans.empty()) {
            cout << "1" << endl;
            cout << "1 1" << endl;
        } else {
            cout << ans.size() << endl;
            for (auto i:ans) {
                cout << i.first + 1 << " " << i.second + 1 << endl;
            }
        }
    }
    return 0;
}