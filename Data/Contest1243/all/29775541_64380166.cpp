#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        vector<int> v;
        for (int i = 0; i < n; i++)
            if (s[i] != t[i])
                v.push_back(i);
        cout << (v.size() == 2 && s[v[0]] == s[v[1]] && t[v[0]] == t[v[1]]? "Yes\n": "No\n");
    }
    return 0;
}