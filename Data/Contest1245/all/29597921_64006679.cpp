#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
    return x*f;
}
char s[105],s2[105];
int apr[105];
signed main(){
    int t=read();
    while(t--){
        int n=read();
        int a=read(),b=read(),c=read();
        int fk1=0,fk2=0,fk3=0;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            if(s[i]=='R')fk1++;
            if(s[i]=='P')fk2++;
            if(s[i]=='S')fk3++;
        }
        int ans=min(a,fk3)+min(b,fk1)+min(c,fk2);
        if(ans<ceil(1.0*n/2)){
            puts("NO");
            continue;
        }
        memset(apr,0,sizeof(apr));
        memset(s2,0,sizeof(s2));
        for(int i=1;i<=n;i++){
            if(s[i]=='R'&&b)b--,s2[i]='P';
            else if(s[i]=='P'&&c)c--,s2[i]='S';
            else if(s[i]=='S'&&a)a--,s2[i]='R';
            else apr[i]=1;
        }
        for(int i=1;i<=n;i++){
            if(!apr[i])continue;
            if(a)a--,s2[i]='R';
            else if(b)b--,s2[i]='P';
            else if(c)c--,s2[i]='S';
        }
        puts("YES");
        puts(s2+1);
    }
    return 0;
}
