#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1010;
int a[MAXN];

int main() {
//     freopen("negcycle.in", "r", stdin);
//     freopen("negcycle.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        vector<int> q;
        for (int j = 0; j < s1.size(); ++j) {
            if (s1[j] != s2[j]) {
                q.push_back(j);
            }
        }
        if (q.size() > 2) {
            cout << "No" << '\n';
        } else if (q.size() == 2) {
            if (s1[q[0]] == s1[q[1]] && s2[q[0]] == s2[q[1]]) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
        } else  {
            cout << "No" << '\n';
        }
    }

}