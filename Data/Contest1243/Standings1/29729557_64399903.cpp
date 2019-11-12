#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
//#define debug(x) cout<<#x<<" is "<<x<<endl;

const int maxn=1e5+5;
const ll mod=1e9+7;

char ch[2][maxn];
int in[2][30],a[maxn*2],x[maxn],y[maxn];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<2;i++)scanf("%s",ch[i]);
        memset(in,0,sizeof(in));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                in[i][ch[i][j]-'a']++;
            }
        }
        int F=1;
        for(int i=0;i<26;i++){
            if((in[0][i]+in[1][i])%2)F=0;
        }
        if(!F)printf("No\n");
        else{
            printf("Yes\n");
            int tot=0;
            for(int i=0;i<n;i++){
                if(ch[0][i]!=ch[1][i]){
                    int ff=0;
                    for(int j=i+1;j<n;j++){
                        if(ch[1][j]==ch[1][i]){
                            x[++tot]=i;
                            y[tot]=j;
                            char cc=ch[0][i];
                            ch[0][i]=ch[1][j];
                            ch[1][j]=cc;
                            ff=1;
                            break;
                        }
                    }
                    if(!ff){
                    for(int j=i+1;j<n;j++){
                        if(ch[0][j]==ch[1][i]){
                            x[++tot]=j;
                            y[tot]=i+1;
                            char cc=ch[0][j];
                            ch[0][j]=ch[1][i+1];
                            ch[1][i+1]=cc;
                            x[++tot]=i;
                            y[tot]=i+1;
                            char cc2=ch[0][i];
                            ch[0][i]=ch[1][i+1];
                            ch[1][i+1]=cc2;
                            //ff=1;
                            break;
                        }
                    }
                    }
                }
            }
            printf("%d\n",tot);
            for(int i=1;i<=tot;i++)printf("%d %d\n",x[i]+1,y[i]+1);
        }
    }
    return 0;

}
