#include "bits/stdc++.h"
#define hhh printf("hhh\n")
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
inline int read() {int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}

const int maxn = 1e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-7;

int n, m;
int a[maxn], b[maxn];

int main() {
    int T=read();
    while(T--) {
        int a=read(), b=read(), c=read(), d=read(), k=read();
        int aa=(a-1)/c+1, bb=(b-1)/d+1;
        if(aa+bb>k) printf("-1\n");
        else printf("%d %d\n", k-bb, bb);
    }
}