#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1e3 + 5, M = 1e5 + 5;
 
int cnt[26];
int vis[N], vid;
char s[N], k[N];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d%s%s", &n, &s, &k);
        memset(cnt, 0, sizeof cnt);
        for(int i = 0 ; i < n ; ++i){
            ++cnt[s[i] - 'a'];
            ++cnt[k[i] - 'a'];
        }
        bool baz = false;
        for(int i = 0 ; i < 26 ; ++i)
            baz |= (cnt[i] & 1);
        if(baz){
            puts("No");
            continue;
        }
        int kml = 0;
        vector<pair<int, int> > out;
        while(kml < n && out.size() < 3 * n){
            /*********************************/
            ++vid;
            for(int i = 0 ; i < n ; ++i)
                if(s[i] == k[i])
                    vis[i] = vid;
            /*********************************/
            bool ok = false;
            for(int i = 0 ; i < n && ! ok; ++i){
                if(vis[i] == vid)continue;
                for(int j = 0 ; j < n && !ok; ++j){
                    if(vis[j] == vid)continue;
                    if(i == j)continue;
                    if(s[i] == s[j]){
                        swap(s[i], k[j]);
                        out.emplace_back(i, j);
                        ok = true;
                    }
                }
            }
            for(int i = 0 ; i < n && ! ok; ++i){
                if(vis[i] == vid)continue;
                for(int j = 0 ; j < n && !ok; ++j){
                    if(vis[j] == vid)continue;
                    if(i == j)continue;
                    if(s[i] == k[j]){
                        swap(s[j], k[j]);
                        out.emplace_back(j, j);
                        swap(k[i], s[j]);
                        out.emplace_back(j, i);
                        ok = true;
                    }
                }
            }
            kml = 0;
            for(int i = 0 ; i < n ; ++i)
                if(s[i] == k[i])
                    ++kml;
        }
        if(out.size() > 2 * n)
            assert(1 == 5);
        puts("Yes");
        printf("%d\n", (int)out.size());
        for(auto i : out)printf("%d %d\n", i.first + 1, i.second + 1);
    }
}