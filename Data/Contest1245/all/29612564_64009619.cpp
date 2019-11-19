#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
const int N=40;
int n,m,f[N][2][2];
int F(int i,int o1,int o2)
{
    if(!i) return 1;
    if(f[i][o1][o2]!=-1) return f[i][o1][o2];
    int &ret=f[i][o1][o2];
    ret=F(i-1,o1||bit(n,i),o2||bit(m,i));
    if(o1||bit(n,i)) ret+=F(i-1,o1,o2||bit(m,i));
    if(o2||bit(m,i)) ret+=F(i-1,o1||bit(n,i),o2);
    return ret;
}
int S(int x,int y)
{
    if(x<0||y<0) return 0;
    n=x,m=y;
    reset(f,-1);
    return F(30,0,0);
}
main()
{
    //freopen("1245F.inp","r",stdin);
    forinc(cs,1,in)
    {
        int l=in,r=in;
        cout<<S(r,r)-S(l-1,r)-S(r,l-1)+S(l-1,l-1)<<"\n";
    }
}
