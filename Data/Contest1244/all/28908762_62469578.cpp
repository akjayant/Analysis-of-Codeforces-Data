#include<bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define PER(i,a,b) for(int i = a; i >= b; --i)
#define PB push_back
#define MP make_pair
#define fi first
#define se second
typedef long long LL;
typedef double DB;

const int maxn = 1000;

int n;
char str[maxn+5];

int main() {
    int _; scanf("%d", &_);
    while(_--) {
        scanf("%d", &n);
        scanf("%s", str+1);
        int ans = n;
        REP(i,1,n) if(str[i]=='1') {
            ans = max(ans, i*2);
            ans = max(ans, i + (n-i+1));
            ans = max(ans, (n-i+1)*2);
        }
        printf("%d\n", ans);
    }
    return 0;
}
