#include<bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define per(a,b,c) for(int a=b;a>=c;a--)
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
typedef double db;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
int n, m, k;
char s[N], t[N];
int a[N], b[N];
int vis[30];
vector<pii> ans;

int main(){
    int T; scanf("%d", &T);
    while(T--){
        rep(i,0,26) vis[i] = 0;
        ans.clear();
        scanf("%d", &n);
        scanf("%s%s", s+1, t+1);
        rep(i,1,n){
            vis[s[i]-'a']++, vis[t[i]-'a']++;
        }
        int flag = 1;
        rep(i,0,25) if(vis[i] & 1){ flag = 0; break;}
        if(!flag) printf("No\n");
        else{
            int cnt = 0, pos = 1;

            rep(i,1,n){
                int jud = 0;
                rep(j,i+1,n){
                    if(s[j] == s[i]){
                        ans.pb({j,i});
                        swap(s[j], t[i]);
                        ++cnt;
                        jud = 1;
                        break;
                    }
                }
                if(!jud){
                    if(t[i] == s[i]) continue;
                    rep(j,i+1,n){
                        if(t[j] == s[i]){
                            ans.pb({n,j});
                            ans.pb({n,i});
                            swap(s[n],t[j]);
                            swap(s[n],t[i]);
                            cnt += 2;
                            break;
                        }
                    }
                }
            }
            if(cnt > 2*n) printf("No\n");
            else{
                printf("Yes\n");
                printf("%d\n", cnt);
                int sz = ans.size();
                rep(i,0,cnt-1) printf("%d %d\n", ans[i].first, ans[i].second);
            }

        }
    }
    //scanf("%d%d", &n, &m);

    return 0;
}

