/**
* Author : Xiuchen
* Date : 2019-11-01-22.31.19
* Description : 597 Div2 B
*/
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=110;
int t;
int a,b,c,n;
char s[maxn],ans[maxn];
int main(){
    scanf("%d",&t);
    while(t--){
        for(int i=1;i<maxn;i++) ans[i]=0;
        scanf("%d",&n);
        scanf("%d%d%d",&a,&b,&c);
        scanf("%s",s+1);
        int R=0,P=0,S=0,len=strlen(s+1);
        for(int i=1;i<=len;i++){
            if(s[i]=='R') R++;
            else if(s[i]=='P') P++;
            else S++;
        }
        //printf("%d %d %d\n",R,P,S);
        int sum=0,mid;
        sum+=min(R,b);
        sum+=min(P,c);
        sum+=min(S,a);
        if(n%2) mid=n/2+1;
        else mid=n/2;
        //printf("%d %d %d\n",a,b,c);
        if(sum<mid) printf("NO\n");
        else{
            printf("YES\n");
            for(int i=1;i<=n;i++){
                if(!a) break;
                if(s[i]=='S'){
                    ans[i]='R';
                    a--;
                }
            }
            for(int i=1;i<=n;i++){
                if(!b) break;
                if(s[i]=='R'){
                    ans[i]='P';
                    b--;
                }
            }
            for(int i=1;i<=n;i++){
                if(!c) break;
                if(s[i]=='P'){
                    ans[i]='S';
                    c--;
                }
            }
            for(int i=1;i<=n;i++){
                if(ans[i]==0){
                    if(a){
                        ans[i]='R';
                        a--;
                    }
                    else if(b){
                        ans[i]='P';
                        b--;
                    }
                    else if(c){
                        ans[i]='S';
                        c--;
                    }
                }
            }
            for(int i=1;i<=n;i++){
                printf("%c",ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
