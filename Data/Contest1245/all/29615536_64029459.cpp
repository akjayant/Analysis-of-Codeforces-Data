#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
template<class Read>void in(Read &x){
    x=0;
    int f=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        f|=(ch=='-');
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    x=f?-x:x;
    return;
}
int n,tot[200005],h[200005],hh[200005];
ll ans,a[20005],b[20005],c[20005],x[20005],y[20005],z[20005],v[20005],f[20005];
int main(){
    in(n);
    for(int i=1;i<=n;i++)in(a[i]),in(b[i]);
    for(int i=1;i<=n;i++){
        in(x[i]);
        y[i]=x[i];
        z[i]=1ll<<62;
    }
    for(int i=1;i<=n;i++)in(c[i]);
    for(int i=1;i<=n;i++){
        ll sum=1ll<<62;
        int id=-1;
        for(int j=1;j<=n;j++){
            if(!v[j]&&sum>min(y[j],z[j])){
                sum=min(y[j],z[j]);
                id=j;
            }
        }
        if(id==-1)break;
        v[id]=1;
        ans+=sum;
        if(y[id]<z[id])tot[++tot[0]]=id;
        else{
            h[++h[0]]=id;
            hh[++hh[0]]=f[id];
        }
        for(int j=1;j<=n;j++){
            if(v[j]==0){
                ll k=(abs(a[j]-a[id])+abs(b[j]-b[id]))*(c[j]+c[id]);
                if(k<z[j]){
                    z[j]=k;
                    f[j]=id;
                }
            }
        }
    }
    cout<<ans<<endl<<tot[0]<<endl;
    for(int i=1;i<=tot[0];i++)printf("%I64d ",tot[i]);
    puts("");
    cout<<h[0]<<endl;
    for(int i=1;i<=h[0];i++)printf("%d %d\n",h[i],hh[i]);
	return 0;
}
