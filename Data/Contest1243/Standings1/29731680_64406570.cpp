#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
char s[maxn], t[maxn];
int vis[26];
set<int> cat[26], jie[26];
#define pi pair<int, int>
#define mk make_pair
vector<pi> ans;
int solve()
{
    int n;
    scanf("%d%s%s", &n, s + 1, t + 1);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 26; i++)
        cat[i].clear(), jie[i].clear();
    for (int i = 1; i <= n; i++)
    {
        vis[s[i] - 'a']++, vis[t[i] - 'a']++;
        cat[s[i] - 'a'].insert(i);
        jie[t[i] - 'a'].insert(i);
    }
    for (int i = 0; i < 26; i++)
        if (vis[i] & 1)
            return puts("No"), 0;
    puts("Yes");
    ans.clear();
    for (int i = 1; i <= n; i++)
        if (s[i] == t[i])
        {
            cat[s[i] - 'a'].erase(i);
            jie[t[i] - 'a'].erase(i);
        }
        else
        {
            if (jie[t[i] - 'a'].size() == 1)
            {
                auto it = cat[t[i] - 'a'].begin();
                int k = *it;
                ans.push_back(mk(k, i + 1));
                cat[t[i + 1] - 'a'].insert(k);

                jie[t[i] - 'a'].insert(i + 1);

                jie[t[i + 1] - 'a'].erase(i + 1);
                cat[t[i] - 'a'].erase(k);
                swap(s[k], t[i + 1]);
            }
            if (jie[t[i] - 'a'].size() > 1)
            {
                auto it = ++jie[t[i] - 'a'].begin();
                ans.push_back(mk(i, *it));
                int k = *it;

                jie[s[i] - 'a'].insert(k);

                jie[t[i] - 'a'].erase(i);
                jie[t[i] - 'a'].erase(jie[t[i] - 'a'].begin());

                cat[s[i] - 'a'].erase(i);
                swap(s[i], t[k]);
            }
            else
            {
                auto it = ++cat[s[i] - 'a'].begin();
                ans.push_back(mk(i, *it));
                int k = *it;
                cat[t[i] - 'a'].insert(k);
                cat[s[i] - 'a'].erase(i);
                cat[s[i] - 'a'].erase(cat[s[i] - 'a'].begin());

                jie[t[i] - 'a'].erase(i);
                swap(s[i], t[k]);
            }
        }
    printf("%d\n", ans.size());
    for (auto tmp : ans)
        printf("%d %d\n", tmp.first, tmp.second);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
}