#include<bits/stdc++.h>
using namespace std;const int N=1e4+7;
char s[N],t[N];int n,i,j,T_T,q[N],top;
int main(){
    for(scanf("%d",&T_T);T_T--;){
        for(scanf("%d%s%s",&n,s+1,t+1),top=0,i=1;i<=n;++i)if(t[i]!=s[i])q[++top]=i;
        if(top==1)puts("No");else if(top==0)puts("Yes");
        else if(top==2){
            swap(s[q[1]],t[q[2]]);
            if(strcmp(s+1,t+1)==0)puts("Yes");else puts("No");
        }else puts("No");
    }
}
