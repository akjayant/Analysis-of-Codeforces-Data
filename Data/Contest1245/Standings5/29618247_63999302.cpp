#include<bits/stdc++.h>
using namespace std;
char str[105],res[105];
int main(){
    int t,n,a,b,c;
    scanf("%d",&t);
    while(t--){
        memset(res,0,sizeof(res));
        scanf("%d%d%d%d%s",&n,&a,&b,&c,str+1);
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(str[i]=='R'){
                if(b>0){
                    res[i]='P';
                    --b;
                    ++cnt;
                }
            }else if(str[i]=='P'){
                if(c>0){
                    res[i]='S';
                    --c;
                    ++cnt;
                }
            }else{
                if(a>0){
                    res[i]='R';
                    --a;
                    ++cnt;
                }
            }
        }
        if(cnt<(n+1)/2){puts("NO");continue;}
        puts("YES");
        vector<char> tmp;
        while(a>0){tmp.push_back('R');--a;}
        while(b>0){tmp.push_back('P');--b;}
        while(c>0){tmp.push_back('S');--c;}
        for(int i=1;i<=n;i++){
            if(res[i]==0){
                res[i]=tmp.back();
                tmp.pop_back();
            }
        }
        puts(res+1);
    }
    return 0;
}
