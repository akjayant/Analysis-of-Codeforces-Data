#include <bits/stdc++.h>
#define MAXN 100
using namespace std;
char s1[MAXN], s2[MAXN];
typedef pair<int, int> P;
vector <P> ans;
int cnt[30];
void solve(){
    ans.clear();
    memset(cnt, 0, sizeof(cnt));
    int len; scanf("%d%s%s", &len, &s1, &s2);
    for(int i = 0; i < len; i++) ++cnt[(int)s1[i] - 'a'], ++cnt[(int)s2[i] - 'a'];
    for(int i = 0; i < 26; i++) if(cnt[i] % 2){printf("No\n"); return;}
    for(int i = 0; i < len; i++){
        if(s1[i] == s2[i]) continue;
        bool flag = false;
        for(int j = i + 1; j < len; j++){
            if(s2[i] == s2[j]){
                swap(s1[i], s2[j]);
                ans.push_back(make_pair(i, j));
                flag = true; break;
            }
        }
        if(!flag)
            for(int j = i + 1; j < len; j++){
                if(s1[i] == s1[j]){
                    swap(s1[j], s2[i]);
                    ans.push_back(make_pair(j, i));
                    flag = true; break;
                }
            }
        if(!flag)
            for(int j = i + 1; j < len; j++){
                if(s1[i] == s2[j]){
                    swap(s1[j], s2[j]);
                    ans.push_back(make_pair(j, j));
                    i--; break;
                }
            }
    }
    printf("Yes\n%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main(){
    int T; scanf("%d", &T);
    while(T--) solve();
}