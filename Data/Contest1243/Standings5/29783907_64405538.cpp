#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 1e4+5;
char s[maxn], t[maxn];
int cnt[26], ans, ans1[maxn], ans2[maxn];
bool not_ok(int n)
{
    for(int i = 0;i < n;i++)
        if(s[i] != t[i]) return true;
    return false;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(cnt, 0, sizeof(cnt));
        ans = 0;
        int n;
        scanf("%d", &n);
        scanf("%s%s", s, t);
        for(int i = 0;i < n;i++)
        {
            if(s[i] == t[i]) continue;
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']++;
        }
        bool yes = true;
        for(int i = 0;i < 26;i++)
            if(cnt[i] & 1) yes = false;
        if(yes){
            while(not_ok(n))
            {
                for(int i = 0;i < n;i++)
                {
                    if(s[i] == t[i]) continue;
                    for(int j = 0;j < n;j++)
                    {
                        if(s[j] == t[j] || j == i) continue;
                        if(t[j] == t[i])
                        {
                            swap(s[i], t[j]);
                            ans1[ans] = i+1;
                            ans2[ans] = j+1;
                            ans++;
                            break;
                        }
                    }
                    if(s[i] == t[i]) continue;
                    for(int j = 0;j < n;j++)
                    {
                        if(s[j] == t[j] || j == i) continue;
                        if(s[j] == t[i])
                        {
                            swap(s[i], t[i]);
                            swap(s[i], t[j]);
                            ans1[ans] = i+1, ans2[ans] = i+1;
                            ans++;
                            ans1[ans] = i+1, ans2[ans] = j+1;
                            ans++;
                            break;
                        }
                    }
                }
            }
            printf("Yes\n%d\n", ans);
            for(int i = 0;i < ans;i++)
                printf("%d %d\n", ans1[i], ans2[i]);
        }else{
            printf("No\n");
        }
    }
    return 0;
}