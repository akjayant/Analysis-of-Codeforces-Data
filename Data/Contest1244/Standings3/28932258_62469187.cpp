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
        n=read();
        string l;
        cin>>l;
        l="0"+l;
        int ll=0, rr=0;
        for(int i=1; i<=n; ++i) if(l[i]=='1') {
            rr=i;
            if(ll==0) ll=i;
        }
        if(!ll&&!rr) cout<<n<<endl;
        else cout<<2*max(rr,n+1-ll)<<endl;
    }
}