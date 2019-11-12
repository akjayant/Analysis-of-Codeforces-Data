#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e4 + 5;

char s[N], t[N];
vector<pii> a, b;
vector<pii> ans;

void to_swap(int pos, pii node) {
    for(int i = pos + 1; i < b.size(); i++) {
        if(b[i].first == node.first) {
            ans.push_back({node.second, b[i].second});
            swap(a[pos].first, b[i].first);
            break;
        }
        else if(a[i].first == node.first) {
            swap(b[i].first, a[i].first);
            ans.push_back({b[i].second, b[i].second});
            swap(a[pos].first, b[i].first);
            ans.push_back({node.second, b[i].second});
            break;
        }
    }
}

int cnt[30];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        a.clear();
        b.clear();
        ans.clear();
        scanf("%d", &n);
        scanf("%s%s", s, t);
        memset(cnt, 0, sizeof(cnt));

        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) { a.push_back({s[i], i + 1}); b.push_back({t[i], i + 1}); }
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']++;
        }

        bool ok = true;
        for(int i = 0; i < 26; i++) {
            if(cnt[i] & 1) { ok = false; break; }
        }

        if(ok) {
            printf("Yes\n");
            for(int i = 0; i < b.size(); i++) to_swap(i, b[i]);
            printf("%d\n", ans.size());
            for(int i = 0; i < ans.size(); i++) {
                printf("%d %d\n", ans[i].first, ans[i].second);
            }
        }
        else printf("No\n");
    }
    return 0;
}
