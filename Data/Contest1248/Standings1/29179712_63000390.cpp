#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
char s[maxn];
int stk[maxn];
char cstk[maxn];
int n;
int ans=0;
int x,y;
int tot[2];
int getans(int l,int r){
    if(l>=r)return 0;
    int top=0;
    int cnt=1;
    for(int i=l;i<=r;i++){
        if(!top||cstk[top]==s[i])cstk[++top]=s[i];
        else{
            if(cstk[top]=='('){
                top--;
                if((!top)||cstk[top]==')')cnt++;
            }else cstk[++top]=s[i];
        }
    }
    return cnt;
}
int check(int l,int r){
    swap(s[l],s[r]);
    int cnt=0;
    int top=0;
    s[0]=')',s[n+1]='(';
    tot[1]=tot[0]=0;
    for(int i=0;i<=n+1;i++){
        tot[s[i]=='(']++;
        if(!top||s[stk[top]]==s[i]){
            stk[++top]=i;
        }else{
            if(s[i]==')'){
                top--;
            }else{
                stk[++top]=i;
            }
        }
    }
    int lpos,rpos;
    for(int i=1;i<top;i++)if(s[stk[i]]!=s[stk[i+1]])cnt=getans(stk[i]+1,stk[i+1]-1);
    if(top==2&&cnt)cnt--;
    swap(s[l],s[r]);
    return tot[0]==tot[1]?cnt:0;
}
int main(){
 //  freopen("in.txt","r",stdin);
    scanf("%d",&n);
    scanf("%s",s+1);
//    printf("ck=%d\n",check(9,10));
  //  return 0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int tv=check(i,j);
            if(tv>=ans){
                ans=tv;
                x=i,y=j;
            }
        }
    }
    printf("%d\n%d %d\n",ans,x,y);
}
