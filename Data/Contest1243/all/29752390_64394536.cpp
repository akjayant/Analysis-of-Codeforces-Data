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
const int N=55;
int Time,n,tot,num[30],ans[1000][2];
char S[N],T[N];
int main(){
   // freopen("txt.in","r",stdin);freopen("txt.out","w",stdout);
    scanf("%d\n",&Time);
    while(Time--){
        memset(num,0,sizeof(num));
        tot=0;
        scanf("%d\n",&n);
        scanf("%s\n%s\n",S+1,T+1);
        F(i,1,n)num[S[i]-'a']++;
        F(i,1,n)num[T[i]-'a']++;
        int flag=1;
        F(i,0,25){
            if(num[i]&1){flag=0;break;}
        }
        if(flag){
            printf("Yes\n");
            F(i,1,n){
                if(S[i]==T[i])continue;
                int tag=0;
                F(j,i+1,n){
                    if(S[i]==S[j]){
                        //printf("%d %d\n",j,i);
                        ans[++tot][0]=j,ans[tot][1]=i;
                        swap(S[j],T[i]);
                        tag=1;break;
                    }
                }
                if(tag)continue;
                F(j,i+1,n){
                    if(S[i]==T[j]){
                        //printf("%d %d\n",j,j);
                        ans[++tot][0]=j,ans[tot][1]=j;
                        swap(S[j],T[j]);
                        //printf("%d %d\n",j,i);
                        ans[++tot][0]=j,ans[tot][1]=i;
                        swap(S[j],T[i]);
                        break;
                    }
                }
            }
            printf("%d\n",tot);
            F(i,1,tot)printf("%d %d\n",ans[i][0],ans[i][1]);
        }
        else printf("No\n");
    }
    return 0;
}