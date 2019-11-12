#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;
char s1[MAXN], s2[MAXN];
typedef pair<char, char> P;
vector <P> p;
bool cmp(int x, int y){
    return x > y;
}
void solve(){
    p.clear();
    int len; scanf("%d%s%s", &len, s1, s2);
    for(int i = 0; i < len; i++)
        if(s1[i] != s2[i]) p.push_back(make_pair(s1[i], s2[i]));
    if(p.size() == 0){printf("Yes\n"); return;}
    if(p.size() == 2 && p[0].first == p[1].first && p[0].second == p[1].second){
        printf("Yes\n"); return;
    }
    printf("No\n");
}

int main(){
    int T; scanf("%d", &T);
    while(T--) solve();
}