

#include<bits/stdc++.h>
#define debug(x) cerr << "[" << #x <<": " << (x) <<"]"<< endl
#define pii pair<int,int>
#define clr(a, b) memset((a),b,sizeof(a))
#define rep(i, a, b) for(int i = a;i < b;i ++)
#define pb push_back
#define MP make_pair
#define LL long long
#define ull unsigned LL
#define ls i << 1
#define rs (i << 1) + 1
#define fi first
#define se second
#define ptch putchar
#define CLR(a) while(!(a).empty()) a.pop()

using namespace std;

#ifndef ONLINE_JUDGE
clock_t prostart = clock();
#endif

const int maxn = 1e5 + 10;
const LL mod = 1e9 + 7;
LL dp[maxn];
char s[maxn];

int main() {
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif

    scanf("%s",s + 1);
    int n = strlen(s + 1);
    for(int i = 1;i <= n;++ i){
        if(s[i] == 'm' || s[i] == 'w'){
            printf("0\n");
            return 0;
        }
    }
    dp[0] = dp[1] = 1;
    for(int i = 2;i <= n;++ i){
        if((s[i] == 'u' && s[i - 1] == 'u') || (s[i] == 'n' && s[i - 1] == 'n')){
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }
        else dp[i] = dp[i - 1];
    }
    printf("%lld\n",dp[n]);

#ifndef ONLINE_JUDGE
    cerr << "time: " << 1.0 * (clock() - prostart) / CLOCKS_PER_SEC << " s" << endl;
#endif
    return 0;
}

