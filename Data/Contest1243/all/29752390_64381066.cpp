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
const int N=10005;
int Time,n,tag,pos[N];
char S[N],T[N];
int main(){
    //freopen("txt.in","r",stdin);freopen("txt.out","w",stdout);
    scanf("%d\n",&Time);
    while(Time--){
        tag=0;
        scanf("%d\n",&n);
        scanf("%s\n%s\n",S+1,T+1);
        F(i,1,n){
            if(S[i]!=T[i])pos[++tag]=i;
        }
        if(tag==1||tag>2)printf("No\n");
        else {
            if(!tag)printf("Yes\n");
            else {
                swap(S[pos[1]],T[pos[2]]);
                int flag=1;
                F(i,1,n){
                    if(S[i]!=T[i]){flag=0;break;}
                }
                if(flag)printf("Yes\n");
                else printf("No\n");
            }
        }
    }
    return 0;
}