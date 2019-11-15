#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,res,a1,b1,c1;
char s[1000],v[1000];
int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&a,&b,&c);
        scanf("%s",s+1);
        res=0;    for(int i=1;i<=n;i++) v[i]='-';   v[n+1]='\0';

        for(int i=1;i<=n;i++){
            if(s[i]=='S'&&a) v[i]='R',a--,res++;
            else if(s[i]=='R'&&b) v[i]='P',b--,res++;
            else if(s[i]=='P'&&c) v[i]='S',c--,res++;
        }
        for(int i=1;i<=n;i++){
            if(v[i]=='-')
                if(a)v[i]='R',a--;
                else if(b)v[i]='P',b--;
                else if(c)v[i]='S',c--;
        }

        if(res>=n/2+n%2){
            puts("YES");
            puts(v+1);
        }else{
            puts("NO");
        }
    }
    return 0;
}