#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const ll mod = 1e9 + 7;
#define afdafafafdafaf y1;
int ar[maxn], n, m, k;

char ch[maxn];
ll ans[maxn][2];
int main()
{
    scanf("%s", ch + 1);
    n = strlen(ch + 1);
    ans[0][0] = 1;
    for(int i=1;i<=n;i++){
        if(ch[i] == 'w' || ch[i] == 'm'){
            printf("0\n");
            return 0;
        }
        ans[i][0] += ans[i-1][0] + ans[i-1][1];
        ans[i][0] %= mod;
        if(i >= 2 && ch[i] == ch[i-1]){
            if(ch[i] == 'n' || ch[i] == 'u'){
                ans[i][1] += (ans[i-2][0] + ans[i-2][1]);
                ans[i][1] %= mod;
            }
        }
    }
    printf("%lld\n", (ans[n][0] + ans[n][1]) % mod);

    return 0;
}
