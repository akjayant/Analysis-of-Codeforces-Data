#include<bits/stdc++.h>
int n;
char ch[1005];
int main(){
    int T;scanf("%d",&T);   
    while(T--){
        scanf("%d",&n);
        scanf("%s",ch+1);
        int mn=n+1,mx=0;
        for(int i=1;i<=n;i++){
            if(ch[i]=='1'){
                mn=std::min(mn,i);
                mx=std::max(mx,i);
            }
        }
        if(!mx)printf("%d\n",n);
        else printf("%d\n",std::max(mx*2,(n-mn+1)*2));
    }
}