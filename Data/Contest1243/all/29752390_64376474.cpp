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
const int N=1005;
int T,n,a[N],MX;
int main(){
   // freopen("txt.in","r",stdin);freopen("txt.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        F(i,1,n)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int MX=1;
        D(i,n,1){
            if(a[i]>=n-i+1)MX=max(n-i+1,MX);
        }
        printf("%d\n",MX);
    }
    return 0;
}