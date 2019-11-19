#define mm(a) memset(a,0,sizeof(a));
#define max(x, y) (x)>(y)?(x):(y)
#define min(x, y) (x)<(y)?(x):(y)
#define Fopen freopen("1.in","r",stdin); freopen("m.out","w",stdout);
#define rep(i, a, b) for(int i=(a);i<=(b);i++)
#define per(i, b, a) for(int i=(b);i>=(a);i--)
#define PII pair<ll,ll>

#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 5e5 + 5;
const ll mod = 1e9 + 7;


int T;
int a,b,c,d,k;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        bool f=0;
        for(int i=1;i<=k;i++){
            if(c*i>=a&&d*(k-i)>=b){
                printf("%d %d\n",i,k-i);
                f=1;
                break;
            }
        }
        if(!f)printf("-1\n");
    }
    return 0;
}
