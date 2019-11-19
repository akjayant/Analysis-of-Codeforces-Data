#include <bits/stdc++.h>
#define F(i,j,k) for(int i=(j);i<=(k);++i)
#define D(i,j,k) for(int i=(j);i>=(k);--i)
#define rep(it,s) for(auto it=s.begin();it!=s.end();++it)
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO{
    template <class T>
    inline void read(T &x){
        x=0;int f=1;char ch=getchar();
        while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
        while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
    }
};
const int N=1000005;
ll n,fac[N],Ans;
int indx;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main(){
    //freopen("txt.in","r",stdin);freopen("txt.out","w",stdout);
    scanf("%I64d\n",&n);
    for(ll i=2;i*i<=n;++i){
        if(n%i==0){
            fac[++indx]=i;
            if(i*i!=n)fac[++indx]=n/i;
        }
    }
    fac[++indx]=n;
    Ans=fac[1];
    F(i,2,indx)Ans=gcd(Ans,fac[i]);
    printf("%I64d\n",Ans);
    return 0;
}