#include "bits/stdc++.h"
#define hhh printf("hhh\n")
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
inline int read() {int x=0,f=1;char c=getchar();while(c!='-'&&(c<'0'||c>'9'))c=getchar();if(c=='-')f=-1,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}

const int maxn = 1e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-7;



void solve() {
    int a=read(), b=read(), c=read();
    int ans=3*min(b,c/2);
    b-=min(b,c/2);
    ans+=3*min(a,b/2);
    cout<<ans<<endl;
}

int main() {
    int T=read();
    while(T--) solve();
}