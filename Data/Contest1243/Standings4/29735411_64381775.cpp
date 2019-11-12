#include <bits/stdc++.h>
using namespace std;
#define me(a, b) memset(a, b, sizeof(a))
#define IOS() ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'

typedef long long ll;
typedef pair<char, char> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 5;

char s[maxn], t[maxn];
vector<P> cnt;

bool check()
{
    return cnt.size() == 2 && cnt[0].first == cnt[1].first && cnt[1].second == cnt[0].second;
}

int main()
{
    IOS();
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        cin >> s >> t;
        cnt.clear();
        bool flag = true;
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) {
                cnt.push_back(make_pair(s[i], t[i]));
                if(cnt.size() > 2) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag && check()) {
            cout << "Yes\n";
        }
        else cout << "No\n";
    }

    return 0;
}