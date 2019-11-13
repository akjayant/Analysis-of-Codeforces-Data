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
int v1[30];
int v2[30];

int main(){
    int T; scanf("%d", &T);
    while(T--){
        rep(i,0,26) v1[i] = v2[i] = 0;
        scanf("%d", &n);
        scanf("%s%s", s+1, t+1);
        //rep(i,1,n) v1[s[i]-'a']++, v2[t[i]-'a']++;
        int cnt = 0;
        rep(i,1,n) if(s[i] != t[i]){
            a[++cnt] = i;
            b[cnt] = i;
        }
        if(cnt > 2 || cnt == 1) printf("No\n");
        else if(cnt == 2){
            if(s[a[1]] == s[a[2]] && t[b[1]] == t[b[2]]) printf("Yes\n");
            else printf("No\n");
        }
        else printf("Yes\n");
    }
    //scanf("%d%d", &n, &m);

    return 0;
}
