#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
const int N = 10010;
char s[N], t[N];
int pos[N];
int tot[30], cnts[30], cntt[30];
pair<int, int> ins[N * 2];
inline int cmp(const int &a, const int &b) {return a > b;}
int main()
{
    int n, T;
    cin>>T;
    while(T--){
        memset(tot, 0, sizeof(tot));
        memset(cnts, 0, sizeof(cnts));
        memset(cntt, 0, sizeof(cntt));
        int cnt = 0;
        scanf("%d%s%s", &n, s + 1, t + 1);
        for (int i = 1; i <= n; ++i){
            tot[s[i] - 'a']++, tot[t[i] - 'a']++;
            cnts[s[i] - 'a']++, cntt[t[i] - 'a']++;
        }    
        int ans = 0;
        for (int i = 0; i <= 26; ++i){
            if (tot[i] & 1) ans = -1;
        }
        if (ans == -1) {
            printf("No\n");
            continue;
        }
        for (int i = 1; i <= n; ++i){
            if (s[i] == t[i]) continue;
            for (int j = i + 1; j <= n; ++j){
                if (t[j] == s[j]) continue;
                if (s[j] == s[i]){
                    ins[++ans] = make_pair(j, i), swap(s[j], t[i]);
                    break; 
                } else if (t[j] == t[i]){
                    ins[++ans] = make_pair(i, j), swap(s[i], t[j]);
                    break;
                } else if (s[i] == t[j]) {
                    ins[++ans] = make_pair(i, i), swap(s[i], t[i]);
                    ins[++ans] = make_pair(i, j), swap(s[i], t[j]);
                    break;
                } else if (t[i] == s[j]) {
                    ins[++ans] = make_pair(i, i), swap(s[i], t[i]);
                    ins[++ans] = make_pair(j, i), swap(s[j], t[i]);
                }
            }
        }
        printf("Yes\n%d\n", ans);
        for (int i = 1; i <= ans; ++i) printf("%d %d\n", ins[i].first, ins[i].second);
    }    
    // system("pause");
}