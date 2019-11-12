#include <bits/stdc++.h>
using namespace std;
#define im 2147483647
#define lm 9223372036854775807
#define ll long long
#define vb vector<bool>
#define vi vector<int>
#define vl vector<long long>
#define vvi vector<vector<int>>
#define ii pair<int, int>
#define ff first
#define ss second
#define _graph map<int, vector<int>>
#define lower_str(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define upper_str(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define debug(index, num) cout << "Case #" << index << ": " << num << endl
#define nmax(an, na) an = max(an, na)
#define nmin(an, na) an = min(an, na)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rep2(i, a, b) for (int i = a; i <= b; i++)
#define repp(i, a, b) for (int i = a; i >= b; i--)
#define repp2(i, a, b) for (int i = a-1; i >= b; i--)
#define be(x) x.begin(), x.end()
#define rbe(x) x.rbegin(), x.rend()
#define pb push_back
#define IO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int main()
{
    IO;
    int k;
    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        map<char, int> cnt;
        vector<pair<int, int>> ans;
        rep(i, 0, n) {
            cnt[s[i]]++;
            cnt[t[i]]++;
        }
        bool f = 0;
        for (char i = 'a'; i <= 'z'; i++) {
            if (cnt[i] % 2 == 1) {
                cout << "No" << endl;
                f = 1;
                break;
            }
        }
        if(!f) {
        rep(i, 0, n) {
            bool ff = s[i] == t[i];
            if (!f) {
                rep(j, i + 1, n) {
                    if (s[i] == s[j]) {
                        swap(t[i], s[j]);
                        ans.pb({j + 1, i + 1});
                        break;
                    }
                    else if (s[i] == t[j]) {
                        swap(s[j], t[j]);
                        ans.pb({j + 1, j + 1});
                        swap(t[i], s[j]);
                        ans.pb({j + 1, i + 1});
                        break;
                    }
                }
            }
        }
        cout << "Yes" << endl;
        cout << ans.size() << endl;
        rep(i, 0, ans.size()) {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
        }
 
    }
}