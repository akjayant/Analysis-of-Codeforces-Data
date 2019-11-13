#include <bits/stdc++.h>
using namespace std;

int main() {
//    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(NULL);

    int k;
    cin >> k;
    while(k--) {
        int n;
        cin >> n;
        char s[51], t[51];
        cin >> s >> t;

        int alphabet[26] = {};
        for(int i=0; i<n; i++) alphabet[s[i]-'a']++, alphabet[t[i]-'a']++;

        bool yes = true;
        for(int i=0; i<26; i++)
            if (alphabet[i] % 2 == 1) {
                yes = false;
                break;
            }
        if(!yes) {
            cout << "No\n";
            continue;
        }

        vector<pair<int, int> > vt;
        for(int i=0; i<n; i++) {
            if(s[i] == t[i]) continue;

            // Find s[i] in s.
            bool swaped = false;
            for(int j=i+1; j<n; j++) {
                if(s[i] == s[j]) {
                    vt.emplace_back(j+1, i+1);
                    swap(s[j], t[i]), swaped = true;
                    break;
                }
            }
            if(swaped) continue;

            // Find s[i] in t.
            for(int j=i+1; j<n; j++) {
                if(s[i] == t[j]) {
                    vt.emplace_back(i+2, j+1);
                    vt.emplace_back(i+2, i+1);
                    swap(s[i+1], t[j]);
                    swap(s[i+1], t[i]);
                    break;
                }
            }
        }
        cout << "Yes\n" << vt.size() << '\n';
        for(pair<int, int> p : vt) cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}