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

int main() {
    int _; scanf("%d", &_);
    while(_--) {
        int a,b,c,d,k;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        int x = a/c;
        if(x*c < a) ++x;
        int y = b/d;
        if(y*d < b) ++y;
        if(x+y > k) puts("-1");
        else printf("%d %d\n", x, y);
    }
    return 0;
}
