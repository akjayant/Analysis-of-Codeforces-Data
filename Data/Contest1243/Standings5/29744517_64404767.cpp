#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int N = 5e5 + 112;
const int M = 19;
const int MOD = 1e9 + 7;

signed main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s1, s2;
        cin >> n;
        cin >> s1 >> s2;
        bool f = 0;
        vector <pair <int, int> > ans;
        map <int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[s1[i]]++;
            mp[s2[i]]++;
        }
        for (auto it : mp)
        {
            if (it.second % 2 == 1)
            {
                cout << "NO\n";
                f = 1;
                break;
            }
        }
        if (!f) {
            for (int i = 0 ; i < n; i++) {
                if (s1[i] == s2[i]) 
                    continue;
                int p = s2.find(s1[i], i + 1);
                if (p != string::npos) {
                    ans.push_back({p, p});
                    ans.push_back({p, i});
                    swap(s2[p], s1[p]);
                    swap(s2[i], s1[p]);
                }
                else {
                    p = s1.find(s1[i], i + 1);
                    ans.push_back({p, i});
                    swap(s1[p], s2[i]);
                }
            }
            if (s1 != s2) {
                cout << "NO\n";
            }
            else {
                if (ans.size() <= 2*n) {
                    cout << "YES\n";
                    cout << ans.size() << '\n';
                    for (auto it : ans)
                    {
                        cout << it.first + 1 << ' ' << it.second + 1 << '\n';
                    }
                }
                else { 
                    cout << "NO\n";
                }
            }
        }
    }
}