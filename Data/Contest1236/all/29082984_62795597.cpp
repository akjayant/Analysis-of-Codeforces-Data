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



int main() {
    int n=read();
    for(int i=1; i<=n; ++i) {
        int t=0;
        for(int j=0; j<n; ++j) {
            printf("%d%c", j*n+((j%2)?n+1-i:i), " \n"[j==n-1]);
        }
    }
}