#include <bits/stdc++.h>
using namespace std;
#define me(a, b) memset(a, b, sizeof(a))
#define IOS() ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'

typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 5;

char s[maxn], t[maxn];
vector<P> ans;

int main()
{
    IOS();
    int T;
    cin >> T;
    while(T--) {
        int n;
        ans.clear();
        cin >> n;
        cin >> s >> t;
        int i;
        for(i = 0; i < n; i++) {
            if(s[i] == t[i]) continue;
            int j = i+1;
            int flag = -1;
            for(; j < n; j++) {
                if(s[j] == s[i]) {
                    flag = 0;
                    break;
                }
                if(t[j] == s[i]) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                ans.push_back(make_pair(j, i));
                swap(s[j], t[i]);
            }
            else if(flag == 1) {
                ans.push_back(make_pair(j, j));
                ans.push_back(make_pair(j, i));
                swap(s[j], t[j]);
                swap(s[j], t[i]);
            }
            else {
                break;
            }
        }
        if(i < n || ans.size() > 2*n) cout << "No\n";
        else {
            cout << "Yes\n";
            cout << ans.size() << endl;
            for(int j = 0; j < ans.size(); j++) {
                cout << ans[j].first+1 << " " << ans[j].second+1 << endl;
            }
        }
    }

    return 0;
}