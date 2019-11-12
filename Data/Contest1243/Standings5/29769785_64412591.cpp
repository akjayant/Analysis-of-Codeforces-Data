#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, i, j, n, P;
    string s, t;
    vector<int> pos[256][2], ans;

    cin >> k;
    while(k--) {
        cin >> n;
        cin >> s >> t;
        ans.clear();
        for(i = 0; i < 256; i++) {
            pos[i][0].clear();
            pos[i][1].clear();
        }
        for(i = 0; i < n; i++) {
            pos[s[i]][0].push_back(i);
            pos[t[i]][1].push_back(i);
        }
        for(i = 0; i < n; i++) {
            if(s[i] != t[i]) {
                P = s.find(s[i], i+1);
                if(P != -1) {
                    ans.push_back(P);
                    ans.push_back(i);
                    s[P] = t[i];
                } else {
                    P = t.find(s[i], i+1);
                    if(P != -1) {
                        ans.push_back(P);
                        ans.push_back(P);
                        ans.push_back(P);
                        ans.push_back(i);
                        t[P] = s[P];
                        s[P] = t[i];
                    } else {
                        break;
                    }
                }
            }
        }

        if(i < n) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            cout << ans.size()/2 << endl;
            for(i = 0; i < ans.size(); i+=2) {
                cout << ans[i]+1 << " " << ans[i+1]+1 << endl;
            }
        }
    }

    return 0;
}
