#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;

long long gcd(long long big, long long small) {
    if (big % small == 0) return small;
    else return gcd (small, big % small);
}

int main(int argc, const char * argv[]) {
    int k, n, e, f;
    cin >> k;
    string s, t;
    bool can;
    for (int i = 0; i < k; ++i) {
        cin >> n >> s >> t;
        vector<int>let(26, 0);
        for (int j = 0; j < n; ++j) {
            ++let[s[j] - 'a'];
            ++let[t[j] - 'a'];
        }
        can = true;
        for (int j = 0; j < 26; ++j) {
            if (let[j] % 2) can = false;
        }
        if (!can) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";
            vector<pair<int, int>>ans(0);
            for (int j = 0; j < n; ++j) {
                if (s[j] != t[j]) {
                    e = j;
                    while (e < n && t[e] != s[j]) ++e;
                    if (e < n) {
                        swap(s[j], t[j]);
                        ans.push_back(make_pair(j + 1, j + 1));
                        swap(s[j], t[e]);
                        ans.push_back(make_pair(j + 1, e + 1));
                    }
                    else {
                        f = j + 1;
                        while (s[f] != s[j]) ++f;
                        swap(s[f], t[j]);
                        ans.push_back(make_pair(f + 1, j + 1));
                    }
                }
            }
            cout << ans.size() << endl;
            for (int j = 0; j < ans.size(); ++j) {
                cout << ans[j].first << " " << ans[j].second << endl;
            }
        }
    }
    
    return 0;
}
