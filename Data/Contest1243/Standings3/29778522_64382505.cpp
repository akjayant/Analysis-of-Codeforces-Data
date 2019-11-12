#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("file.in", "r", stdin);
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s;
        cin >> t;
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i])
                arr.push_back(i);
        }
        if (arr.size() == 1 || arr.size() > 2)
            cout << "No" << "\n";
        else if (arr.size() == 0)
            cout << "Yes" << "\n";
        else {
            if (s[arr[0]] == s[arr[1]] && t[arr[1]] == t[arr[0]])
                cout << "Yes";
            else
                cout << "No";
            cout << "\n";
        }
    }
}
