/*Lower_Rating*/
/*CF 599 B2*/
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<set>
#include<vector>
#include<map>
using namespace std;

#define LL long long
#define MAXN 800000
#define MAXM 2000000
#define MOD 998244353
#define Pr pair<int,int>
#define X first
#define Y second
#define INF 1000000000000000000
#define mem(x,p) memset(x,p,sizeof(x))

LL read(){
  LL x=0,F=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')F=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
  return x*F;
}

int T,n,pos1,pos2,cnt;
char s[MAXN+5],t[MAXN+5];
vector<Pr> ans;
int main()
{
    T=read();
    while(T--){
        ans.clear();
        cnt=0;
        n=read();
        scanf("%s%s",s+1,t+1);
        int F=1;
        for(int i=1;i<=n;i++){
            if(s[i]!=t[i]){
                F=0;
                for(int j=i+1;j<=n;j++)
                if(s[i]==s[j]){
                    swap(s[j],t[i]);
                    ans.push_back(Pr(j,i));
                    F=1;
                    break;
                }
                else if(s[i]==t[j]){
                    swap(t[j],s[i+1]);
                    swap(s[i+1],t[i]);
                    ans.push_back(Pr(i+1,j));
                    ans.push_back(Pr(i+1,i));
                    F=1;
                    break;
                }
                if(!F)break;
            }
        }
        if(!F)printf("No\n");
        else{
            printf("Yes\n%d\n",ans.size());
            for(int i=0;i<ans.size();i++)
            printf("%d %d\n",ans[i].X,ans[i].Y);
        }
    }
}
