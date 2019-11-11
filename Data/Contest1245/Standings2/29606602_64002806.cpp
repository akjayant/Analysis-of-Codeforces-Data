/** Simplicity is the final achievement **/

#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+55;

long long n, m;
int a[3];
string s;

long long arr[N];

map<char, char> mp;
map<char, int> mpp;
string rps = "RPS";

int32_t main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    /** ONLY FOOLS RUSH IN **/
    int t;
    cin >> t;
    mp['R'] = 'P';
    mp['S'] = 'R';
    mp['P'] = 'S';
    mpp['R'] = 1;
    mpp['S'] = 0;
    mpp['P'] = 2;

    while (t--) {
        cin >> n >> a[0] >> a[1] >> a[2] >> s;
        string ans = s;
        vector<bool> mark(n, 0);
        int w = 0;
        for (int i = 0; i < n ; i++) {
            if (a[mpp[s[i]]]) {
                ans[i] = mp[s[i]];
                w++;
                a[mpp[s[i]]]--;
                mark[i] = 1;
            }
        }


        for (int i = 0; i < n ; i++) {
            if (!mark[i]) {
                for (int j = 0; j < 3; j++) {
                    if (a[j]) {
                        ans[i] = rps[j];
                        a[j]--;
                        break;
                    }
                }
            }
        }

        if (w >= (n+1)/2) {
            cout << "YES\n" << ans << "\n";
        } else cout << "NO\n";

    }
    return 0;
}
