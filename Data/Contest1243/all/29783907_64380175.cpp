#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 1e4+5;
char s[maxn], t[maxn];
char s_swap[2], t_swap[2];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, cnt = 0;
        scanf("%d", &n);
        scanf("%s%s", s, t);
        for(int i = 0;i < n;i++)
        {
            if(s[i] == t[i]) continue;
            if(cnt == 2){cnt++;break;}
            s_swap[cnt] = s[i];
            t_swap[cnt] = t[i];
            cnt++;
        }
        if(cnt == 0 || (cnt == 2 && s_swap[0] == s_swap[1] && t_swap[1] == t_swap[0]))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}